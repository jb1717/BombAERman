//
// Score.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Tue May  5 20:46:32 2015 TommyStarK
// Last update Sun May 24 18:00:45 2015 TommyStarK
//

#include "UIManager/Score.hh"

Score::Score()
  :_filename(".score")
{
  if (access(_filename.c_str(), F_OK) == -1)
    this->updateScoreFile(false);
  else
    this->extractBestScores();
}

Score::~Score()
{
  if (_file.is_open())
    _file.close();
  if (unlink(_filename.c_str()) == -1)
    throw std::runtime_error("(Score::)~Score() - syscall unlink failed.");
  this->updateScoreFile(true);
}


/*
** Parsing Tools:
**    - epur string
**    - get current time and format as follow year/month/day it into string
**    - parser for operator <<
**    - parser to get score from file
*/

std::string             Score::epur(const std::string &input)
{
  std::istringstream    i(input);
  std::string           in;
  std::string           final;

  if (i >> in) {final += in;}
  while (i >> in) {final += ' ' + in;}
  return final;
}

std::string             Score::formatDate(struct tm *now, int flag)
{
  std::string           final;
  std::ostringstream    convert;

  if (!flag)
    convert << (now->tm_year + 1900);
  else if (flag == 1)
    convert << (now->tm_mon + 1);
  else
    convert << (now->tm_mday);
  final += convert.str();
  return (final += flag < 2 ? "/" : "");
}

void                    Score::parseFromFile(t_score *n, const std::string &bestscore)
{
  int                   score = 0;
  size_t                pos;
  std::string           token;
  std::string           handler = bestscore;

  while ((pos = handler.find(";")) != std::string::npos) {
    token = handler.substr(0, pos);
    !score ? n->player = token : n->date = token;
    handler.erase(0, pos + 1);
    ++score;
  }
  token = handler.substr(0, handler.length());
  std::stringstream    s(token);
  s >> score;
  n->best = score;
}

void                    Score::parseNewScore(t_score *n, const std::string &bestscore)
{
  int                   score;
  size_t                pos;
  std::string           token;
  std::string           handler = bestscore;
  time_t                t = time(0);
  struct tm             *now = localtime(&t);

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
** Ordering scores of our vector _top
** from greater to lower
*/
void                    Score::orderTop()
{
  int                   ret = 0;
  static int            count;
  static bool           check = false;
  static TOP            tmp;

  if (!check) {
    tmp = _top;
    count = tmp.size();
    _top.clear();
    check = true;
  }
  while (count) {
    for (TOP::iterator i = tmp.begin(); i != tmp.end(); ++i) {
        (*i).best > ret ? ret = (*i).best : ret = ret;
    }
    for (TOP::iterator i = tmp.begin(); i != tmp.end(); ++i) {
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
** if bool end is false
**    creates hidden file '.score' and write header.
** else
**    update '.score' writting @ end scores.
**
*/
void                Score::updateScoreFile(bool end)
{
  std::string         tmp("");

  _file.open(_filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
  _file << "######################################" << std::endl;
  _file << "##############BOMBAERMAN##############" << std::endl;
  _file << "######################################" << std::endl;
  _file << "##################BEST-SCORES#########" << std::endl;
  _file << "######################################" << std::endl;
  _file << "#####################copyright##2015##" << std::endl;
  if (end)
  {
    this->orderTop();
    for (TOP::iterator i = _top.begin(); i != _top.end(); ++i) {
      std::ostringstream  convert;

      convert << (*i).best;
      tmp += (*i).player;
      tmp += ";";
      tmp += (*i).date;
      tmp += ";";
      tmp += convert.str();
      _file << tmp << std::endl;
      tmp.clear();
    }
  }
}

/*
** Open hidden file '.score'
** Load best scores
** upload them into _top (our vector).
*/
void                Score::extractBestScores()
{
  std::string       current;
  std::ifstream     file(_filename.c_str());

  if (file.is_open()) {
    while (std::getline(file, current)) {
      if (current[0] != '#') {
        t_score       n;
        this->parseFromFile(&n, Score::epur(current));
        _top.push_back(n);
      }
      current.clear();
    }
  }
}

/*
** operator >> returns a pointer to a std::vector<t_score>.
** result is filled following the number of scores asked.
*/
TOP                     *Score::operator>>(size_t request)
{
  TOP                   *ret = new TOP;

  if (_top.empty()) {
    t_score               s = {"NONE", "NONE", 0};
    ret->push_back(s);
    return (ret);
  }
  else if (_top.size() < request) {
    for (TOP::iterator i = _top.begin(); i != _top.end(); ++i) {
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

/*
** operator to add/modify best score.
** string(param) has to be formated as follow "PLAYERNAME;SCORE"
*/
Score                   &Score::operator<<(const std::string &bestscore)
{
  t_score               n;

  this->parseNewScore(&n, bestscore);
  for (TOP::iterator i = _top.begin(); i != _top.end(); ++i)
  {
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
** Get numbers of players ranked in bestscores;
*/
size_t              Score::getNbrRankedPlayers() const
{
  return _top.size();
}





//
//
// DEBUG
//
//
void                Score::show()
{
  std::string       tmp;
  std::ifstream     file(_filename.c_str());

  while (std::getline(file, tmp)) {
    std::cout << tmp << std::endl;
    tmp.clear();
  }
}

void                Score::showTop()
{
  this->orderTop();
  for (TOP::iterator i = _top.begin(); i != _top.end(); ++i) {
    std::cout << "PLAYER: " << (*i).player << " @ " << (*i).date;
    std::cout << " SCORE: " << (*i).best << std::endl;
  }
}
