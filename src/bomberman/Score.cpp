//
// Score.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Tue May  5 20:46:32 2015 TommyStarK
// Last update Thu May  7 06:41:09 2015 TommyStarK
//

#include "Score.hpp"

Score::Score()
  :_filename(".score")
{
  if (access(_filename.c_str(), F_OK) == -1)  {
      _file.open(_filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
      _file << "######################################" << std::endl;
      _file << "##############BOMBAERMAN##############" << std::endl;
      _file << "######################################" << std::endl;
      _file << "##################BEST-SCORES#########" << std::endl;
      _file << "######################################" << std::endl;
      _file << "#####################copyright##2015##" << std::endl;
  }
  else
    this->show();

}
void                    Score::setStructScore(t_score *it, const std::string &tmp, int flag)
{
  !flag ? it->player = tmp : it->date = tmp;
}

void                    Score::parse(t_score *n, const std::string &bestscore)
{
  int                   score = 0;
  size_t                pos;
  std::string           token;
  std::string           handler = bestscore;

  while ((pos = handler.find(";")) != std::string::npos) {
    token = handler.substr(0, pos);
    this->setStructScore(n, token, score);
    handler.erase(0, pos + 1);
    ++score;
  }
  token = handler.substr(0, handler.length());
  std::stringstream    s(token);
  s >> score;
  n->best = score;
}

/*
** operator to add/modify best score
*/
Score                   &Score::operator<<(const std::string &bestscore)
{
  t_score               n;

  this->parse(&n, bestscore);
  for (TOP::iterator i = _top.begin(); i != _top.end(); ++i)
  {
    if ((*i).player == n.player)
      {
        if (n.best > (*i).best)
          (*i).best = n.best;
        return *this;
      }
  }
  _top.push_back(n);
  return *this;
}


/*
** Ordering scores from greater to lower
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
  while (count)
  {
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
    --count;
    this->orderTop();
  }
  check = false;
  return ;
}






/*
** Display file '.score' for debug
*/
void                Score::show()
{
  std::string       tmp;
  std::ifstream     file(_filename.c_str());

  while (std::getline(file, tmp))
  {
    std::cout << tmp << std::endl;
    tmp.clear();
  }
}


/*
** Display _top for debug
*/
void                Score::showTop()
{
  this->orderTop();
  for (TOP::iterator i = _top.begin(); i != _top.end(); ++i) {
    std::cout << "PLAYER: " << (*i).player << " @ " << (*i).date;
    std::cout << " SCORE: " << (*i).best << std::endl;
  }
}
