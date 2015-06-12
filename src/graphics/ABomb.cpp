//
// ABomb.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Wed May 20 19:45:50 2015 Jamais
// Last update Fri Jun 12 03:59:35 2015 Jamais
//

#include	"ABomb.hh"

ABomb::ABomb() : AGameModel()
{
  _timer = 3;
}

ABomb::ABomb(glm::vec3 const& _position) : AGameModel(_position)
{
  _timer = 3;
}

ABomb::ABomb(std::string const& filePath) : AGameModel(filePath)
{
  _timer = 3;
}

ABomb::ABomb(glm::vec3 const& _position, std::string const& filePath) : AGameModel(_position, filePath)
{
  _timer = 3;
}

ABomb::ABomb(std::string const& filePath, glm::vec3 const& _position) : AGameModel(_position, filePath)
{
  _timer = 3;
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

void		ABomb::update(gdl::Clock const& clock, UNUSED Binput& input)
{
  _timer -= clock.getElapsed();
}

bool		ABomb::isExplosed() const
{
  if (_timer <= 0.0f)
    return (true);
  return (false);
}
