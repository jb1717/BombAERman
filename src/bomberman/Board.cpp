//
// Board.cpp for Bomberman in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Wed May  6 13:21:36 2015 Jean-Baptiste Grégoire
// Last update Wed May 13 15:48:19 2015 Jean-Baptiste Grégoire
//

#include "Board.hh"
#include "Player.hh"
#include "Crate.hh"
#include "UnbreakableWall.hh"


Board::Board(size_t xLength, size_t yLength) : _xLength(xLength), _yLength(yLength)
{

}

AObj  *Board::createEntity(Board &board, entityType type)
{
  switch (type)
  {
    case PLAYER:
      return (new Player(board));
    case CRATE:
      return (new Crate(board));
    case UNBREACKABLE_WALL:
      return (new UnbreakableWall(board));
    default:
      return (NULL);
  }
}

bool	Board::placeEntity(size_t x, size_t y, entityType type, size_t id, Direction dir)
{
  int	to = y * _xLength + x;
  AObj	*obj;

  if (_board[to].empty())
    {
      obj = createEntity(*this, type);
      if (!obj)
        return (false);
      if (type != PLAYER)
        obj->setPosition(x, y);
      else
        reinterpret_cast<Player *>(obj)->playerSpawn(x, y, dir, id);
      _board[to].push_back(obj);
      return (true);
    }
  return (false);
}

bool	Board::moveEntity(size_t x, size_t y, size_t id, Direction dir)
{
  int	from = y * _xLength + x;
  int	to;
  AObj	*tmp = NULL;

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
  std::vector<AObj *>::iterator it;
  for (it = _board[from].begin(); it != _board[from].end(); ++it)
  {
    if ((*it)->getId() == id)
    {
      tmp = *it;
      break ;
    }
  }
  if (!tmp)
    return (false);
  _board[from].erase(it);
  _board[to].push_back(tmp);
  return (true);
}

std::vector<Player *>  &Board::getPlayers()
{
  return (_players);
}


Board::~Board()
{

}
