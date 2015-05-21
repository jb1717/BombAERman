//
// AObj.cpp for Bomberman in /home/jibb/rendu/cpp_bomberman/src/bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri May 15 22:18:52 2015 Jean-Baptiste Grégoire
// Last update Sun May 17 19:54:23 2015 David Tran
//

#include "AObj.hh"

AObj::AObj(Board &board, float x, float y) : _board(board), _x(x), _y(y)
{

}

void  AObj::setPosition(float x, float y)
{
  _x = x;
  _y = y;
}

std::pair<float, float> AObj::getPosition() const
{
  return (std::pair<float, float>(_x, _y));
}

void	AObj::setId(int id)
{
  _id = id;
}

int		AObj::getId(void) const
{
  return (_id);
}

entityType AObj::getType(void) const
{
	return (_type);
}


AObj::~AObj()
{

}
