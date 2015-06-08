//
// ABomb.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Wed May 20 19:45:50 2015 Jamais
// Last update Sun May 24 03:02:57 2015 Jamais
//

#include	"ABomb.hh"

ABomb::ABomb() : AGameModel()
{

}

ABomb::ABomb(glm::vec3 const& _position) : AGameModel(_position)
{
}

ABomb::ABomb(std::string const& filePath) : AGameModel(filePath)
{
}
ABomb::ABomb(glm::vec3 const& _position, std::string const& filePath) : AGameModel(_position, filePath)
{
}

ABomb::ABomb(std::string const& filePath, glm::vec3 const& _position) : AGameModel(_position, filePath)
{
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
  _timer -= clock.getElapsed();
}
