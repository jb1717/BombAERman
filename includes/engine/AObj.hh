//
// AObj.hh for Bomberman in /home/jibb/rendu/cpp_bomberman/src/bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri May 15 22:18:39 2015 Jean-Baptiste Grégoire
// Last update Tue May 19 21:35:40 2015 David Tran
//

#ifndef AOBJ_HH_
# define AOBJ_HH_

# include <stddef.h>
# include <utility>

class Board;

class AObj
{
public:
  AObj(Board &board, float x = 0, float y = 0);
  ~AObj();

public:
	void				setPosition(float x, float y);
	std::pair<float, float>		getPosition() const;
	void				setId(size_t);
	int				getId(void) const;
protected:
  Board 	&_board;
  float		_x;
  float		_y;
  int			_id;
};

#endif // !AOBJ
