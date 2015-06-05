//
// AObj.hh for Bomberman in /home/jibb/rendu/cpp_bomberman/src/bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri May 15 22:18:39 2015 Jean-Baptiste Grégoire
// Last update Wed May 20 12:03:50 2015 David Tran
//

#ifndef AOBJ_HH_
# define AOBJ_HH_

# include <stddef.h>
# include <utility>
# include "AGameObject.hh"

enum entityType
  {
    BOMB = 0, PLAYER, CRATE, UNBREAKABLE_WALL, NONE, END = NONE
  };

class	Board;

class AObj : public AGameObject
{
public:
  AObj(Board &board, float x = 0, float y = 0);
  ~AObj();

public:
	void				setPos(float x, float y);
	std::pair<float, float>		getPos() const;
	void				setId(int);
	int				getId(void) const;
  entityType getType(void) const;
protected:
  Board 	&_board;
  entityType	_type;
  float		_x;
  float		_y;
  int		_id;
};

#endif // !AOBJ
