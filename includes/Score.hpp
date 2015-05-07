//
// Score.hpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Tue May  5 20:46:09 2015 TommyStarK
// Last update Thu May  7 08:21:31 2015 TommyStarK
//

#include "rapidjson/document.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <ctime>
#include <vector>

typedef struct          s_score
{
  std::string           player;
  std::string           date;
  int                   best;
}                       t_score;

typedef std::vector<t_score>    TOP;

class                   Score
{
public:
	Score();
	~Score();

private:
  std::string             _filename;
	std::fstream            _file;
	std::vector<t_score>    _top;

private:
  void                    parseNewScore(t_score *, const std::string &);
  void                    parseFromFile(t_score *, const std::string &);
  void                    orderTop();
  void                    updateScoreFile(bool);
  void                    extractBestScores();
  std::string             epur(const std::string &);
  std::string             formatDate(struct tm *, int);

public:
  Score                   &operator<<(const std::string &);
  void                    show();
  void                    showTop();
};
