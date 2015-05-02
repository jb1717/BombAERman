//
// bomb.cpp for bomberman in /home/tran_0/rendu/cpp_bomberman/include
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Sun May  3 01:03:38 2015 David Tran
// Last update Sun May  3 01:11:41 2015 David Tran
//

#include "Bomb.hh"

Bomb::Bomb(char Range, bool Launch) : range(Range), launched(Launch)
{}

Bomb::~Bomb()
{}

char	Bomb::getRange() const
{
  return (range);
}

void	Bomb::setRange(char const &Range)
{
  range = Range;
}


bool	Bomb::isLaunched()
{
  return (launched);
}

void	Bomb::triggerLaunch()
{
  (launched == false) ? (launched = true) : (launched = false);
}
