//
// AObj.hh for Bomberman in /home/jibb/rendu/cpp_bomberman/src/bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri May 15 22:18:39 2015 Jean-Baptiste Grégoire
// Last update Fri May 15 22:18:42 2015 Jean-Baptiste Grégoire
//

#ifndef AOBJ_HH_
# define AOBJ_HH_

# include <utility>
# include "Map.hh"

class AObj
{
public:
  AObj(Map &map, size_t x = 0, size_t y = 0);
  ~AObj();

public:
	void	setPosition(size_t x, size_t y);
	std::pair<size_t, size_t>	getPosition() const;

protected:
  Map 	&_map;
  size_t	_x;
  size_t	_y;
};

#endif // !AOBJ