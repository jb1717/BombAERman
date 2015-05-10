//
// Save.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May  9 09:49:33 2015 TommyStarK
// Last update Sun May 10 02:44:17 2015 Milox Thomas
//

#include "Save.hpp"

Save::Save()
  : _filename(".save")
{
  if (access(_filename.c_str(), F_OK) == -1)
  {
    _file.open(_filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
  }
}

Save::~Save()
{

}

