//
// AObj.cpp for Bomberman in /home/jibb/rendu/cpp_bomberman/src/bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri May 15 22:18:52 2015 Jean-Baptiste Grégoire
// Last update Fri May 15 22:18:55 2015 Jean-Baptiste Grégoire
//

#include "AObj.hh"

AObj::AObj(Map &map, size_t x, size_t y) : _map(map), _x(x), _y(y)
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

AObj::~AObj()
{

}
