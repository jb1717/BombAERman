//
// Score.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Tue May  5 20:46:09 2015 TommyStarK
// Last update Sat May 23 05:50:42 2015 TommyStarK
//

#ifndef _SCORE_HH_
# define _SCORE_HH_

# include <sstream>
# include <fstream>
# include <iostream>
# include <stdexcept>
# include <unistd.h>
# include <ctime>
# include <vector>

typedef struct                  s_score
{
  std::string                   player;
  std::string                   date;
  int                           best;
}                               t_score;

typedef std::vector<t_score>    TOP;

class                           Score
{
public:
	Score();
	~Score();

private:
  std::string                   _filename;
	std::fstream                  _file;
	std::vector<t_score>          _top;

private:
  std::string                   epur(const std::string &);
  std::string                   formatDate(struct tm *, int);
  void                          parseFromFile(t_score *, const std::string &);
  void                          parseNewScore(t_score *, const std::string &);
  void                          orderTop();
  void                          updateScoreFile(bool);
  void                          extractBestScores();

public:
  TOP                           *operator>>(size_t);
  Score                         &operator<<(const std::string &);
  size_t                        getNbrRankedPlayers() const;
  void                          show();
  void                          showTop();
};


#endif /* ! _SCORE_HH_ */
