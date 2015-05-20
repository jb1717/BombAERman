//
// Board.hh for Bomberman in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Wed May  6 13:22:05 2015 Jean-Baptiste Grégoire
// Last update Tue May 19 22:27:04 2015 Jean-Baptiste Grégoire
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
  enum	IDType
  {
    Bomb = -3, CrateID = -2, Wall = -1, NoID = 0
  };

public:
  Board(size_t length, size_t width);
  ~Board();

public:
  bool  placeEntity(float x, float y, entityType type, size_t id, Direction dir = North);
  bool  placeEntity(float x, float y, AObj *entity);
  bool  moveEntity(float x, float y, size_t id, Direction dir);
  void	deleteEntity(float x, float y, int id = 0, bool breakWall = false);
  void	setExplosion(float x, float y);

public:
  std::vector<Player *>  &getPlayers();
  std::vector<AObj *> &getSquareObjects(size_t x, size_t y);

private:
  AObj	*createEntity(Board &board, entityType type);
  AObj  *removeFromSquare(int x, int y, int id);
  void  updatePos(float x, float y, AObj *obj);

private:
  std::vector<std::vector<AObj *> > _board;
  std::vector<Player *> _players;
  size_t	_xLength;
  size_t	_yLength;
};

#endif // !Board_HH_
