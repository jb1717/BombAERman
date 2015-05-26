//
// ScoreHandler.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/UIHandler/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 07:02:15 2015 TommyStarK
// Last update Wed May 27 01:03:40 2015 Milox Thomas
//

#include "manager/ScoreHandler.hh"

ScoreHandler::ScoreHandler()
: _filename(".score.json")
{
  this->extractBestScores();
}

ScoreHandler::~ScoreHandler()
{
  this->updateScoreFile();
}

//
// Intern Functionnement
//

/*
** Ordering scores of our vector _top from greater to lower
*/
void                    ScoreHandler::orderTop()
{
  int                   ret = 0;
  static int            count;
  static bool           check = false;
  static BestScores     tmp;

  if (!check) {
    tmp = _top;
    count = tmp.size();
    _top.clear();
    check = true;
  }
  while (count) {
    for (BestScores::iterator i = tmp.begin(); i != tmp.end(); ++i) {
        (*i).best > ret ? ret = (*i).best : ret = ret;
    }
    for (BestScores::iterator i = tmp.begin(); i != tmp.end(); ++i) {
      if ((*i).best == ret) {
          t_score      n = {(*i).player, (*i).date, (*i).best};
          _top.push_back(n);
          (*i).best = -1;
      }
    }
    return (--count, this->orderTop());
  }
  check = false;
}

/*
**
*/
void                  ScoreHandler::extractBestScores()
{
  FILE                *file = fopen(_filename.c_str(), "r");

  if (file) {
    char buff[65536] = {0};
    rapidjson::FileReadStream is(file, buff, sizeof(buff));
    rapidjson::Document doc;

    try {
      if (doc.ParseStream(is).HasParseError() || !doc.HasMember("score"))
        throw std::invalid_argument(_filename + " Invalid JSON file. Scores won't be loaded.");
      else {
        ScoreHandler::t_score    it;

        for (rapidjson::SizeType i = 0; i < doc["score"].Size(); i++) {
          it.player = doc["score"][i]["player"].GetString();
          it.date = doc["score"][i]["date"].GetString();
          it.best = doc["score"][i]["best"].GetInt();
          _top.push_back(it);
        }
        this->orderTop();
      }
      fclose(file);
    } catch(std::exception &e) {
      fclose(file);
      throw;
    }
  }
}

/*
**
*/
void                  ScoreHandler::updateScoreFile()
{
  rapidjson::Document doc;
	rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();
	doc.SetObject();
  rapidjson::Value score(rapidjson::kArrayType);

  this->orderTop();
  for (BestScores::iterator i = _top.begin(); i != _top.end(); i++) {
    rapidjson::Document it;
  	it.SetObject();
    it.AddMember("player", rapidjson::Value((*i).player.c_str(), (*i).player.length()), allocator);
    it.AddMember("date", rapidjson::Value((*i).date.c_str(), (*i).date.length()), allocator);
    it.AddMember("best", (*i).best, allocator);
    score.PushBack(it, allocator);
  }

  doc.AddMember("score", score, allocator);

  FILE*             file = fopen(_filename.c_str(), "w");
	if (file) {
		char buff[65536] = {0};
		rapidjson::FileWriteStream os(file, buff, sizeof(buff));
		rapidjson::Writer<rapidjson::FileWriteStream> writer(os);
		doc.Accept(writer);
		fclose(file);
  }
}

/*
** Parse std::string given to operator << and fill a t_score struct with data.
*/
void                  ScoreHandler::parseNewScore(t_score *n, const std::string &bestscore)
{
  int                 score;
  size_t              pos;
  std::string         token;
  std::string         handler = bestscore;
  time_t              t = time(0);
  struct tm           *now = localtime(&t);

  while ((pos = handler.find(";")) != std::string::npos) {
    token = handler.substr(0, pos);
    n->player = token;
    handler.erase(0, pos + 1);
  }
  token = handler.substr(0, handler.length());
  std::stringstream    s(token);
  s >> score;
  n->best = score;
  for (size_t i = 0; i < 3; ++i) {
    n->date += formatDate(now, i);
  }
}

/*
** Returns a std::string which contains current date formated.
** Every score will be saved as the format following: {Player: Date, Score.}
*/
std::string           ScoreHandler::formatDate(struct tm *now, int flag)
{
  std::string         final;
  std::ostringstream  convert;

  if (!flag)
    convert << (now->tm_year + 1900);
  else if (flag == 1)
    convert << (now->tm_mon + 1);
  else
    convert << (now->tm_mday);
  final += convert.str();
  return (final += flag < 2 ? "/" : "");
}

//
// PUBLIC ACCESS
//

/*
** Operator >> to delete player's score (player as parameter).
*/
bool                    ScoreHandler::operator>>(const std::string &player)
{
  for (BestScores::iterator i = _top.begin(); i != _top.end(); i++)
  {
    if ((*i).player == player) {
        _top.erase(i);
        return true;
      }
  }
  return false;
}

/* operator to add/modify best score.
** string(param) has to be formated as follow "PLAYERNAME;SCORE"
** At end of every party , please use this operator to put player's score
** It will be saved if the current score is better than the other, of if its his
**  first score.
*/
ScoreHandler            &ScoreHandler::operator<<(const std::string &bestscore)
{
  t_score               n;

  this->parseNewScore(&n, bestscore);
  for (BestScores::iterator i = _top.begin(); i != _top.end(); i++) {
      if ((*i).player == n.player)
        {
          if (n.best > (*i).best)
          (*i).best = n.best;
          return (*this);
        }
    }
  _top.push_back(n);
  return (*this);
}

/*
** Returns a pointer to a std::vector<t_score>.
** result is filled following the number of scores asked.
** nullptr is returned in case of no best scores are registered!
*/
BestScores          *ScoreHandler::top(size_t request)
{
  BestScores        *ret = new BestScores;

  if (_top.empty() == true)
    return (nullptr);
  else if (_top.size() < request) {
    for (BestScores::iterator i = _top.begin(); i != _top.end(); i++) {
      t_score               s;
      s.player = (*i).player;
      s.date = (*i).date;
      s.best = (*i).best;
      ret->push_back(s);
    }
    return (ret);
  }
  else {
    for (size_t i = 0; i < request; ++i)
      ret->push_back(_top[i]);
    return (ret);
  }
}


// DEBUG
void                ScoreHandler::debug()
{
  this->orderTop();
  for (BestScores::iterator i = _top.begin(); i != _top.end(); i++)
  {
    std::cout << "PLAYER " << (*i).player << " DATE " << (*i).date << " SCORE: " << (*i).best << std::endl;
  }
}
