//
// Engine.cpp for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue May  5 17:48:04 2015 David Tran
// Last update Sun May 17 21:16:30 2015 David Tran
//

#include "Engine.hh"

Engine::Engine(Board &board, size_t x, size_t y) : _board(board)
{}

Engine::~Engine()
{}


Board	&Engine::getBoard() const
{
  return (_board);
}

void	Engine::run()
{
  while (42)
    {
      if (_board.getPlayers().size() <= 1)
	     return ;
      usleep(1000);
    }
}
