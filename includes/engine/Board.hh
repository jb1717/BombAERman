//
// Board.hh for Bomberman in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Wed May  6 13:22:05 2015 Jean-Baptiste Grégoire
// Last update Sun May 17 21:23:55 2015 David Tran
//

#ifndef Board_HH_
# define Board_HH_

# include <cmath>
# include <string>
# include <vector>
# include "AObj.hh"

# define MAP_EMPTY_CHAR	'o'

class		Player;

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
  bool	placeEntity(float x, float y, entityType type, size_t id, Direction dir = North);
  bool	moveEntity(float x, float y, size_t id, Direction dir);
  ~Board();

public:
  std::vector<Player *>  &getPlayers();
  AObj  *removeFromSquare(int x, int y, size_t id);
  void  updatePos(float x, float y, AObj *obj);

private:
  AObj	*createEntity(Board &board, entityType type);

private:
  std::vector<std::vector<AObj *> > _board;
  std::vector<Player *> _players;
  size_t	_xLength;
  size_t	_yLength;
};

#endif // !Board_HH_
