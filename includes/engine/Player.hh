//
// Player.hh for Bomberman in /home/tran_0/rendu/cpp_bomberman/include
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Sun May  3 01:20:37 2015 David Tran
// Last update Sun May 17 21:21:20 2015 David Tran
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <vector>
# include <utility>
# include "Board.hh"
# include "Bomb.hh"
# include "AObj.hh"

# define PLAYER_CHAR	'p'

class	Player : public AObj
{
public:
  Player(Board &Board);
  ~Player();
public: // Principal functions
  bool					playerSpawn(float x, float y, Board::Direction direction, size_t id);
  bool					turnLeft();
  bool					turnRight();
  bool					goAhead();
  bool					goBack();
  bool					selectDirection(Board::Direction);
  void					run_user();
public: // Player Safety
  bool					is_Alive() const;
  void					triggerAlive();

public: // Player Bomb tools
  void					addBomb();
  std::vector<Bomb*>			getBombs() const;
  std::vector<Bomb*>::const_iterator	getBombIt() const;
  bool					triggerOneBomb();
  void					powerUpRange();
public: // Speed Power-up
  char					getSpeed() const;
  void					setSpeed(char const &);

private:
  bool			_isAlive;
  std::vector<Bomb *>	_bombs;
  char			_speed;
  Board::Direction	_dir;
};

#endif // !PLAYER_HH
