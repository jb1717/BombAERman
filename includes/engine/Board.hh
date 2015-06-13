//
// Board.hh for Bomberman in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Wed May  6 13:22:05 2015 Jean-Baptiste Grégoire
// Last update Sat Jun 13 01:45:56 2015 Jean-Baptiste Grégoire
//

#ifndef Board_HH_
# define Board_HH_

# include <cmath>
# include <string>
# include <vector>
# include "AObj.hh"
# include "AGameObject.hh"
# include "AFX.hh"
# include "Explosion.hh"

# define MAP_EMPTY_CHAR	'o'

class		Player;

class		Board
{
public:
  enum Direction
    {
      North = 0, West, South, East
    };
  enum	IDType
    {
      Explode = -4, Bomb = -3, CrateID = -2, Wall = -1, NoID = 0
    };

public:
  Board(size_t length, size_t width);
  ~Board();

public:
  bool			initialize();
  void			initGameObjects();

public:
  bool  placeEntity(float x, float y, entityType type, long int id, Direction dir = North);
  bool  placeEntity(float x, float y, AObj *entity);
  bool  moveEntity(float x, float y, long int id, Direction dir);
  void	deleteEntity(float x, float y, long int id = 0, bool breakWall = false);
  void	setExplosion(float x, float y);
  void  popEntity(int x, int y, long int id);
  void	removePlayer(long int id);
  bool	collideAround(AObj *, long int x, long int y);
  bool	checkOneCollision(std::vector<AObj *> field, AObj *);

public:
  std::vector<std::vector<AObj *> >	&getFullBoard();
  std::vector<Player *>  &getPlayers();
  std::vector<AObj *> &getSquareObjects(size_t x, size_t y);
  std::vector<AObj *>   &operator[](size_t);
  size_t                getWidth() const;
  size_t                getHeight() const;
  size_t                size() const;

private:
  AObj	*createEntity(Board &board, entityType type);
  AObj  *removeFromSquare(int x, int y, long int id);
  void  updatePos(float x, float y, AObj *obj);
  std::vector<AObj *> &getCase(int at);

private:
  std::vector<std::vector<AObj *> > _board;
  std::vector<Player *> _players;
  size_t	_xLength;
  size_t	_yLength;
};

#endif // !Board_HH_
