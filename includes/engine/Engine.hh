//
// Engine.hh for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue May  5 17:48:33 2015 David Tran
// Last update Sat May 16 06:17:08 2015 David Tran
//

#ifndef Engine_HH_
# define Engine_HH_

# include <unistd.h>
# include <iostream>
# include <vector>
# include "Board.hh"
# include "Player.hh"
# include "EThread.hh"

class	EThread;

class	Engine
{
public:
  Engine(Board &board);
  ~Engine();
public:
  void		run();
public:
  Board		&getBoard() const;
private:
  Board				&_board;
};

void	*launch_player(void *);

#endif // !Engine_HH_
