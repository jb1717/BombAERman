//
// AButtons.cpp for BomAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Wed May 20 17:57:18 2015 TommyStarK
// Last update Wed May 20 21:15:35 2015 TommyStarK
//

#include "AButtons.hpp"

AButtons::AButtons()
{

}


AButtons::~AButtons()
{

}

std::tuple<bool, enum AButtons::Keys>                   AButtons::checkInput()
{
  if (getInput(SDLK_UP) == true)
    return (std::tuple<bool, enum AButtons::Keys>(true, UP));
  else if (getInput(SDLK_DOWN) == true)
    return (std::tuple<bool, enum AButtons::Keys>(true, DOWN));
  else if (getInput(SDLK_RETURN) == true || getInput(SDLK_KP_ENTER) == true)
    return (std::tuple<bool, enum AButtons::Keys>(true, ENTER));
  else if (getInput(SDLK_ESCAPE) == true)
  return (std::tuple<bool, enum AButtons::Keys>(false, NONE));
    return (std::tuple<bool, enum AButtons::Keys>(true, ESC));
}
