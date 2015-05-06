//
// Player.hh for Bomberman in /home/tran_0/rendu/cpp_bomberman/include
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Sun May  3 01:20:37 2015 David Tran
// Last update Wed May  6 17:42:05 2015 David Tran
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <vector>
# include "Map.hh"
# include "Bomb.hh"

class	Player
{
public:
  Player(char Speed, bool alive, Map &map);
  ~Player();
public: // Principal functions
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
  bool			isAlive;
  std::vector<Bomb *>	bombs;
  char			speed;
  Map			&_map;
};

#endif // !PLAYER_HH
