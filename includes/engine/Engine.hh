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
# include "GameEnine.hh"

# define UNUSED __attribute__((unused))

class	EThread;

class	Engine
{
public:
  Engine(Board &board, size_t, size_t);
  ~Engine();
public:
  void		run();
public:
  Board		&getBoard() const;
private:
  Board				&_board;
  GameEngine			engine;
};

void	*launch_player(void *);

#endif // !Engine_HH_
