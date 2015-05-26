//
// ScoreHandler.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIHandler/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 07:00:39 2015 TommyStarK
// Last update Wed May 27 00:59:55 2015 TommyStarK
//


#ifndef _SCOREHANDLER_HH_
# define _SCOREHANDLER_HH_

# include <ctime>
# include <vector>
# include <sstream>
# include <fstream>
# include <stdio.h>
# include <dirent.h>
# include <iostream>
# include <unistd.h>
# include <stdexcept>
# include "rapidjson/rapidjson.h"
# include "rapidjson/document.h"
# include "rapidjson/writer.h"
# include "rapidjson/filereadstream.h"
# include "rapidjson/filewritestream.h"

class       ScoreHandler
{
public:
  ScoreHandler();
  ~ScoreHandler();

// Public struct used to store scores
public:
  typedef struct              s_score
  {
    std::string               player;
    std::string               date;
    int                       best;
  }                           t_score;

// Private functionals attributes
private:
  std::string                 _filename;
  std::vector<t_score>        _top;

// Intern functionement
private:
  void                        orderTop();
  void                        updateScoreFile();
  void                        extractBestScores();
  void                        parseNewScore(t_score *, const std::string &);
  std::string                 formatDate(struct tm *, int);

// Public access
public:
  bool                        operator>>(const std::string &);
  ScoreHandler                &operator<<(const std::string &);
  std::vector<t_score>        *top(size_t);

// Debug
public:
  void                        debug();
};


typedef std::vector<ScoreHandler::t_score>      BestScores;


#endif /* end of include guard: _SCOREHANDLER_HH_ */
