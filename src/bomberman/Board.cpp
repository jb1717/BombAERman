//
// Board.cpp for Bomberman in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Wed May  6 13:21:36 2015 Jean-Baptiste Grégoire
// Last update Tue May 19 17:59:00 2015 Jean-Baptiste Grégoire
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
    // case CRATE:
    //   return (new Crate(board));
    case UNBREACKABLE_WALL:
      return (new UnbreakableWall(board));
    default:
      return (NULL);
    }
}

bool	Board::placeEntity(float x, float y, entityType type, size_t id, Direction dir)
{
  int	to = static_cast<int>(y) * _xLength + static_cast<int>(x);
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

bool	Board::placeEntity(float x, float y, AObj *entity)
{
  int	to = static_cast<int>(y) * _xLength + static_cast<int>(x);

  if (!_board[to].empty())
    return (false);
  _board[to].push_back(entity);
  return (true);
}

void  Board::deleteEntity(float x, float y, int id, bool breakWall)
{
  int	posx = static_cast<int>(x), posy = static_cast<int>(y);
  std::vector<AObj *>	tmp = _board[posy * _xLength + posx];

  for (std::vector<AObj *>::iterator it = tmp.begin(); it != tmp.end();)
  {
    if (id == 0)
    {
      if ((*it)->getId() == Wall && breakWall == false)
      {
        ++it;
        continue ;
      }
      delete *it;
      it = tmp.erase(it);
    }
    else if (id == (*it)->getId())
    {
      delete *it;
      it = tmp.erase(it);
    }
  }
}

AObj	*Board::removeFromSquare(int x, int y, int id)
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

std::vector<AObj *> &Board::getSquareObjects(size_t x, size_t y)
{
  return (_board[y * _xLength + x]);
}


std::vector<Player *>  &Board::getPlayers()
{
  return (_players);
}

Board::~Board()
{

}
