//
// AObj.cpp for Bomberman in /home/jibb/rendu/cpp_bomberman/src/bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri May 15 22:18:52 2015 Jean-Baptiste Grégoire
// Last update Sat May 16 08:22:14 2015 David Tran
//

#include "AObj.hh"

AObj::AObj(Board &board, size_t x, size_t y) : _board(board), _x(x), _y(y)
{

}

void  AObj::setPosition(size_t x, size_t y)
{
  _x = x;
  _y = y;
}

std::pair<size_t, size_t> AObj::getPosition() const
{
  return (std::pair<size_t, size_t>(_x, _y));
}

void	AObj::setId(size_t Id)
{
  _id = Id;
}

size_t	AObj::getId(void) const
{
  return (_id);
}

AObj::~AObj()
{

}
