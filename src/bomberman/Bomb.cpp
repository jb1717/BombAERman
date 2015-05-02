//
// bomb.cpp for bomberman in /home/tran_0/rendu/cpp_bomberman/include
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Sun May  3 01:03:38 2015 David Tran
// Last update Sun May  3 01:45:18 2015 David Tran
//

#include "Bomb.hh"

Bomb::Bomb(bool Launch) : launched(Launch)
{}

Bomb::~Bomb()
{}

bool	Bomb::isLaunched() const
{
  return (launched);
}

void	Bomb::triggerLaunch()
{
  (launched == false) ? (launched = true) : (launched = false);
}
