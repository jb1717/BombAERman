//
// AObj.cpp for Bomberman in /home/jibb/rendu/cpp_bomberman/src/bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri May 15 22:18:52 2015 Jean-Baptiste Grégoire
// Last update Sat Jun 13 01:49:31 2015 Jean-Baptiste Grégoire
//

#include "AObj.hh"

AObj::AObj(Board &board, float x, float y) : _board(board), _x(x), _y(y)
{
  _gameObj = NULL;
  _id = reinterpret_cast<long int>(this);
}

void  AObj::setPos(float x, float y)
{
  _x = x;
  _y = y;
}

std::pair<float, float> AObj::getPos() const
{
  return (std::pair<float, float>(_x, _y));
}

void	AObj::setId(long int id)
{
  _id = id;
}

long int	AObj::getId(void) const
{
  return (_id);
}

entityType AObj::getType(void) const
{
  return (_type);
}

AGameObject	*AObj::getGameObj() const
{
  return (_gameObj);
}

void		AObj::setGameObj(AGameObject *newone)
{
  _gameObj = newone;
}

AObj::~AObj()
{

}
