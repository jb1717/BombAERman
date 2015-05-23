//
// AUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Wed May 20 17:58:02 2015 TommyStarK
// Last update Sat May 23 05:48:37 2015 TommyStarK
//

#include "AUI.hh"

AUI::AUI()
{

}

AUI::~AUI()
{

}

AButtons                        *AUI::operator[](const std::string &name)
{
  for (auto i : _buttons)
  {
    if ((*i).getButtonName() == name)
      return (i);
  }
  throw std::logic_error("(AButtons::)[] invalid button name.");
  return (NULL);
}
