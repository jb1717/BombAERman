//
// Board.hh for Bomberman in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Wed May  6 13:22:05 2015 Jean-Baptiste Grégoire
// Last update Wed May 13 21:34:49 2015 Jean-Baptiste Grégoire
//

#ifndef Board_HH_
# define Board_HH_

# include <string>
# include <vector>
# include "AObj.hh"

# define MAP_EMPTY_CHAR	'o'

class		Board
{
public:
  enum Direction
    {
      North = 0, West, South, East
    };

  enum entityType
  {
      PLAYER = 0, CRATE, UNBREACKABLE_WALL
  };

public:
  Board(size_t length, size_t width);
  bool	placeEntity(size_t x, size_t y, entityType type, Direction dir = North);
  // bool	moveEntity(size_t x, size_t y, Direction dir);
  ~Board();

private:
  AObj	*createEntity(Board &board, entityType type);

private:
  std::vector<std::vector<AObj *> > _board;
  size_t	_xLength;
  size_t	_yLength;
};

#endif // !Board_HH_
