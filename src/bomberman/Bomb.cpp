//
// bomb.cpp for bomberman in /home/tran_0/rendu/cpp_bomberman/include
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Sun May  3 01:03:38 2015 David Tran
// Last update Thu May  7 23:25:57 2015 David Tran
//

#include "Bomb.hh"

Bomb::Bomb(Map &map, bool Launch, char Range) : AObj(map), launched(Launch), range(Range)
{}

Bomb::~Bomb()
{}

bool	Bomb::isLaunched() const
{
  return (launched);
}

void	Bomb::triggerLaunch(int x, int y)
{
  launched = !launched;
  _start = (launched) ? std::clock() : 0;
  setPosition(x, y);
}

bool	Bomb::explosion_check()
{
  if (launched && (std::clock() - _start) / CLOCKS_PER_SEC > 3)
    return (true);
  return (false);
}

char	Bomb::getRange() const
{
  return (range);
}

void	Bomb::setRange(char const &Range)
{
  range = Range;
}

void			Bomb::run()
{

}
