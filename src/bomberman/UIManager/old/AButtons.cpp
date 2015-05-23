//
// AButtons.cpp for BomAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Wed May 20 17:57:18 2015 TommyStarK
// Last update Sat May 23 05:48:37 2015 TommyStarK
//

#include "AButtons.hh"

AButtons::AButtons()
{

}


AButtons::~AButtons()
{

}

void                                        AButtons::setPosition(float x, float y, float z)
{
  _position = glm::vec3(x < 0 ? std::abs(x) : x,
                        y < 0 ? std::abs(y) : y,
                        z < 0 ? std::abs(z) : z);
}

const std::string                           &AButtons::getButtonName() const
{
  return _name;
}


std::tuple<bool, enum AButtons::Keys>       AButtons::checkInput()
{
  if (getInput(SDLK_RETURN) || getInput(SDLK_KP_ENTER)) {
    return (std::tuple<bool, enum AButtons::Keys>(true, ENTER));
  }
  else if (getInput(SDLK_ESCAPE)) {
    return (std::tuple<bool, enum AButtons::Keys>(true, ESC));
  }
  else
  {
    if (getInput(SDLK_UP))
      return (std::tuple<bool, enum AButtons::Keys>(true, UP));
    else if (getInput(SDLK_DOWN))
      return (std::tuple<bool, enum AButtons::Keys>(true, DOWN));
    return (std::tuple<bool, enum AButtons::Keys>(false, OTHER));
  }
  return (std::tuple<bool, enum AButtons::Keys>(false, NONE));
}
