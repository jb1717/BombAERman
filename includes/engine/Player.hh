//
// Player.hh for Bomberman in /home/tran_0/rendu/cpp_bomberman/include
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Sun May  3 01:20:37 2015 David Tran
// Last update Wed May 20 12:00:49 2015 David Tran
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <vector>
# include <utility>
# include "EThreadPool.hh"
# include "Board.hh"
# include "Bomb.hh"
# include "AObj.hh"
# include "Crate.hh"

# define PLAYER_CHAR	'p'

class	Bomb;
class	EThreadPool;

class	Player : public AObj
{
public:
  Player(Board &Board);
  ~Player();
public: // Principal functions
  bool					playerSpawn(float x, float y, Board::Direction direction, int id);
  bool					turnLeft();
  bool					turnRight();
  bool					goAhead();
  bool					goBack();
  bool					selectDirection(Board::Direction);
  void					run_user();
  bool					userAction();
  int					commandValue();
  void					checkPosPowerUp();
public: // Player Safety
  bool					is_Alive() const;
  void					triggerAlive();

public: // Player Bomb tools
  void					addBomb();
  std::vector<Bomb *>			getBombs() const;
  std::vector<Bomb *>::const_iterator	getBombIt() const;
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
  EThreadPool		*_bombThread;
};

#endif // !PLAYER_HH
