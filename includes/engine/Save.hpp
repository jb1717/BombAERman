//
// Save.hpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May  9 09:50:48 2015 TommyStarK
// Last update Sat May  9 11:52:08 2015 TommyStarK
//

#ifndef _SAVES_HPP_
# define _SAVES_HPP_

# include "rapidjson/document.h"
# include <sstream>
# include <fstream>
# include <iostream>
# include <stdexcept>
# include <unistd.h>

class                     Save
{
public:
  Save();
  ~Save();

private:
  std::string             _filename;
  std::fstream            _file;

public:

};

#endif /* ! _SAVE_HPP_ */
