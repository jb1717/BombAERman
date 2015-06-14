//
// Engine.hh for Bomberman in /home/tran_0/rendu/cpp_bomberman
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Tue May  5 17:48:33 2015 David Tran
// Last update Sun May 17 15:05:40 2015 David Tran
//

#ifndef Engine_HH_
# define Engine_HH_

# include <unistd.h>
# include <iostream>
# include <vector>
# include "Board.hh"
# include "Player.hh"
# include "EThread.hh"
# include "GameEngine.hh"
# include "Ia.hh"
# include "AssetManager.hh"

# define UNUSED __attribute__((unused))

class	EThread;

class	Engine
{
public:
  Engine(Board &board);
  ~Engine();
public:
  bool		initialize(int, int, std::string const &);
  bool		launch_game();
  void		run();
  bool		players_thread();
  bool		checkRealAlive();
public:
  Board		&getBoard() const;
private:
  Board				&_board;
  GameEngine			*engine;
  int				_nbPlay;
  int				_nbIa;
  std::vector<EThread *>	_players;
};

void	*launch_play(void *);
void	*launch_ia(void *);

#endif // !Engine_HH_
