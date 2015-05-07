//
// Map.cpp for Bomberman in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Wed May  6 13:21:36 2015 Jean-Baptiste Grégoire
// Last update Thu May  7 14:15:16 2015 Jean-Baptiste Grégoire
//

#include "Map.hh"

Map::Map(size_t xLength, size_t yLength) : _xLength(xLength), _yLength(yLength)
{

}

bool	Map::moveEntity(size_t x, size_t y, Direction dir)
{
  int	from = y * _xLength + x;
  int	to;
  char	c;

  switch (dir)
    {
    case North:
      if (y > 0)
        to = from - _yLength;
      else
        to = -1;
    case South:
      if (y < _yLength)
        to = from + _yLength;
      else
        to = -1;
    case East:
      if (x > 0)
        to = from - 1;
      else
        to = -1;
    case West:
      if (x < _xLength)
        to = from + 1;
      else
        to = -1;
    default: return(false);
    }
  if (to == -1)
    return (false);
  c = _map[from];
  _map[from] = MAP_EMPTY_CHAR;
  _map[to] = c;
  return (true);
}

Map::~Map()
{

}
