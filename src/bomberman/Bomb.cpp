//
// bomb.cpp for bomberman in /home/tran_0/rendu/cpp_bomberman/include
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Sun May  3 01:03:38 2015 David Tran
// Last update Wed May 20 14:04:33 2015 David Tran
//

#include "Bomb.hh"

Bomb::Bomb(Board &Board, bool Launch, char Range) : AObj(Board), launched(Launch), range(Range)
{
  _type = BOMB;
  _id = Board::Bomb;
}

Bomb::~Bomb()
{}

bool	Bomb::isLaunched() const
{
  return (launched);
}

void	Bomb::triggerLaunch()
{
  launched = !launched;
}

void	Bomb::explosion()
{
  int	x = _x, y = _y;
  std::vector<AObj *> tmp;
  for (int i = 1; i <= range; ++i)
  {
    if (y - i > 0)
      {
	tmp = _board.getSquareObjects(x, y - i);
	if (tmp.size() != 0 && (tmp.front()->getType() == UNBREAKABLE_WALL || (tmp.front()->getType() == CRATE && !reinterpret_cast<Crate *>(tmp.front())->isBreak())))
	  {
	    _board.deleteEntity(x, y - i);
	    if (tmp.front()->getType() != UNBREAKABLE_WALL)
	      _board.setExplosion(x, y - i);
	    i = range + 1;
	  }
	else
	  {
	    _board.deleteEntity(x, y - i);
	    _board.setExplosion(x, y - i);
	  }
      }
  }
  for (int i = 1; i < range + 1; ++i)
  {
    if (static_cast<size_t>(y + i) < _board.getHeight())
      {
	tmp = _board.getSquareObjects(x, y + i);
	if (tmp.size() != 0 && (tmp.front()->getType() == UNBREAKABLE_WALL || (tmp.front()->getType() == CRATE && !reinterpret_cast<Crate *>(tmp.front())->isBreak())))
	  {
	    _board.deleteEntity(x, y + i);
	    if (tmp.front()->getType() != UNBREAKABLE_WALL)
	    _board.setExplosion(x, y + i);
	    i = range + 1;
	  }
	else
	  {
	    _board.deleteEntity(x, y + i);
	    _board.setExplosion(x, y + i);
	  }
      }
  }
  for (int i = 1; i < range + 1; ++i)
  {
    if (x - i > 0)
      {
	tmp = _board.getSquareObjects(x - i, y);
	if (tmp.size() != 0 && (tmp.front()->getType() == UNBREAKABLE_WALL || (tmp.front()->getType() == CRATE && !reinterpret_cast<Crate *>(tmp.front())->isBreak())))
	  {
	    _board.deleteEntity(x - i, y);
	    if (tmp.front()->getType() != UNBREAKABLE_WALL)
	    _board.setExplosion(x - i, y);
	    i = range + 1;
	  }
	else
	  {
	    _board.deleteEntity(x - i, y);
	    _board.setExplosion(x - i, y);
	  }
      }
  }
  for (int i = 1; i < range + 1; ++i)
  {
    if (static_cast<size_t>(x + i) < _board.getWidth())
      {
	tmp = _board.getSquareObjects(x + i, y);
	if (tmp.size() != 0 && (tmp.front()->getType() == UNBREAKABLE_WALL || (tmp.front()->getType() == CRATE && !reinterpret_cast<Crate *>(tmp.front())->isBreak())))
	  {
	    _board.deleteEntity(x + i, y);
	    if (tmp.front()->getType() != UNBREAKABLE_WALL)
	    _board.setExplosion(x + i, y);
	    i = range + 1;
	  }
	else
	  {
	    _board.deleteEntity(x + i, y);
	    _board.setExplosion(x + i, y);
	  }
      }
  }
  _board.deleteEntity(x, y);
}

bool	Bomb::explosion_check()
{
  return (true);
}

char	Bomb::getRange() const
{
  return (range);
}

void	Bomb::setRange(char const &Range)
{
  range = Range;
}

void			Bomb::run()
{
  triggerLaunch();
  while (!explosion_check())
    {
      usleep(10);
    }
  launched = !launched;
}
