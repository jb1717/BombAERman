//
// ABomb.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Wed May 20 19:45:50 2015 Jamais
// Last update Thu May 21 22:02:24 2015 Jamais
//

#include	"ABomb.hh"

ABomb::ABomb() : AGameModel()
{
  translate(glm::vec3(_position.x, 1.0f, _position.z));
}
ABomb::ABomb(glm::vec3 const& _position) : AGameModel(_position)
{
  translate(glm::vec3(_position.x, 1.0f, _position.z));
}
ABomb::ABomb(std::string const& filePath) : AGameModel(filePath)
{
  translate(glm::vec3(_position.x, 1.0f, _position.z));
}
ABomb::ABomb(glm::vec3 const& _position, std::string const& filePath) : AGameModel(_position, filePath)
{
  translate(glm::vec3(_position.x, 1.0f, _position.z));
}
ABomb::ABomb(std::string const& filePath, glm::vec3 const& _position) : AGameModel(_position, filePath)
{
  translate(glm::vec3(_position.x, 1.0f, _position.z));
}

ABomb::~ABomb()
{}

float		ABomb::getTimer() const
{
  return _timer;
}

void		ABomb::setTimer(float timer)
{
  _timer = timer;
}

void		ABomb::update(gdl::Clock const& clock, UNUSED gdl::Input& input)
{
  // if (_position.y > -0.30)
  //   _position.y -= 0.1;
  _timer -= clock.getElapsed();
}
