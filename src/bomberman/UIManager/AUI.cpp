//
// AUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 23:04:43 2015 TommyStarK
// Last update Sat May 23 23:37:46 2015 TommyStarK
//


#include "UIManager/AUI.hh"

void                          AUI::setName(const std::string &name)
{
  _name = name;
}

std::string                   AUI::getName() const
{
  return _name;
}

AUI::TypeUI                   AUI::getType() const
{
  return _type;
}
