//
// Board.cpp for Bomberman in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Wed May  6 13:21:36 2015 Jean-Baptiste Grégoire
// Last update Mon May 18 20:24:03 2015 Jean-Baptiste Grégoire
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

bool	Board::placeEntity(float x, float y, entityType type, size_t id, Direction dir)
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
	{
	  reinterpret_cast<Player *>(obj)->playerSpawn(x, y, dir, id);
	  _players.push_back(reinterpret_cast<Player *>(obj));
	}
      _board[to].push_back(obj);
      return (true);
    }
  return (false);
}

AObj	*Board::removeFromSquare(int x, int y, size_t id)
{
  AObj	*tmp;

  for (std::vector<AObj *>::iterator it = _board[y * _xLength + x].begin(); it != _board[y * _xLength + x].end(); ++it)
    {
      if ((*it)->getId() == id)
	{
	  tmp = *it;
	  _board[y * _xLength + x].erase(it);
	  break ;
	}
    }
  for (std::vector<AObj *>::iterator it = _board[y * _xLength + x + 1].begin(); it != _board[y * _xLength + x].end(); ++it)
    {
      if ((*it)->getId() == id)
	{
	  tmp = *it;
	  _board[y * _xLength + x].erase(it);
	  break ;
	}
    }
  for (std::vector<AObj *>::iterator it = _board[((y + 1) * _xLength) + x].begin(); it != _board[y * _xLength + x].end(); ++it)
    {
      if ((*it)->getId() == id)
	{
	  tmp = *it;
	  _board[y * _xLength + x].erase(it);
	  break ;
	}
    }
  for (std::vector<AObj *>::iterator it = _board[((y + 1)* _xLength) + x + 1].begin(); it != _board[y * _xLength + x].end(); ++it)
    {
      if ((*it)->getId() == id)
	{
	  tmp = *it;
	  _board[y * _xLength + x].erase(it);
	  break ;
	}
    }
  return (tmp);
}

void	Board::updatePos(float x, float y, AObj *obj)
{
  float	intPartX, intPartY;
  int	intx = static_cast<int>(x), inty = static_cast<int>(y);

  std::modf(x, &intPartX);
  std::modf(x, &intPartY);
  if (x < intPartX + 0.5)
    _board[inty * _xLength + intx].push_back(obj);
  else if (x > intPartX + 0.5)
    _board[inty * _xLength + intx + 1].push_back(obj);
  else
    {
      _board[inty * _xLength + intx].push_back(obj);
      _board[inty * _xLength + intx + 1].push_back(obj);
    }
  if (y < intPartY + 0.5)
    _board[inty * _xLength + intx].push_back(obj);
  else if (y > intPartY + 0.5)
    _board[inty + 1* _xLength + intx].push_back(obj);
  else
    {
      _board[inty * _xLength + intx].push_back(obj);
      _board[((inty + 1) * _xLength) + intx].push_back(obj);
    }
}

bool	Board::moveEntity(float x, float y, size_t id, Direction dir)
{
  float	toX = x, toY = y;
  int posX = static_cast<int>(x), posY = static_cast<int>(y);
  AObj	*tmp = NULL;

  switch (dir)
    {
    case North:
      if (y > 0)
        toY -= 0.1;
      else
        toY = -1.0;
    case South:
      if (y < _yLength)
        toY += 0.1;
      else
        toY = -1.0;
    case East:
      if (x > 0)
        toX -= 0.1;
      else
        toX = -1.0;
    case West:
      if (x < _xLength)
        toX += 0.1;
      else
        toX = -1.0;
    default: return(false);
    }
  if (toX == -1.0 || toY == -1.0)
    return (false);
  tmp = removeFromSquare(posX, posY, id);
  updatePos(toX, toY, tmp);
  return (true);
}

std::vector<Player *>  &Board::getPlayers()
{
  return (_players);
}

Board::~Board()
{

}
