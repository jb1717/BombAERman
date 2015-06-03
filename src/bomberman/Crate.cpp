//
// Crate.cpp for Bomberman in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Wed May  6 11:59:20 2015 Jean-Baptiste Grégoire
// Last update Wed May  6 13:19:18 2015 Jean-Baptiste Grégoire
//

#include "Crate.hh"

Crate::Crate(Board &board) : AObj(board, 0, 0), Cube(), _break(false)
{
  _type = CRATE;
  _bonus = static_cast<Crate::BonusType>(std::rand() % 4); // remember to initialize the seed !
}

Crate::BonusType	Crate::getBonus() const
{
  return (_bonus);
}

void		Crate::breakIt()
{
  _break = true;
}

bool		Crate::isBreak() const
{
  return (_break);
}

Crate::~Crate()
{

}
