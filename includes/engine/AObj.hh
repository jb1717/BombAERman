//
// AObj.hh for Bomberman in /home/jibb/rendu/cpp_bomberman/src/bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri May 15 22:18:39 2015 Jean-Baptiste Grégoire
// Last update Sat Jun 13 01:11:30 2015 Jean-Baptiste Grégoire
//

#ifndef AOBJ_HH_
# define AOBJ_HH_

# include <stddef.h>
# include <utility>
# include "AGameObject.hh"

enum entityType
  {
    BOMB = 0, PLAYER, UNBREAKABLE_WALL, CRATE, NONE, END = NONE
  };

class	Board;

class AObj
{
public:
  AObj(Board &board, float x = 0, float y = 0);
  ~AObj();

public:
  void				setPos(float x, float y);
  std::pair<float, float>	getPos() const;
  void				setId(long int);
  long int			getId(void) const;
public:
  AGameObject			*getGameObj() const;
  void				setGameObj(AGameObject *);
public:
  entityType			getType(void) const;

protected:
  Board 	&_board;
  entityType	_type;
  float		_x;
  float		_y;
  long int	_id;
  AGameObject	*_gameObj;
};

#endif // !AOBJ
