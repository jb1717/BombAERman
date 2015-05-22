//
// Engine.cpp for Bomberman in /home/tran_0/rendu/cpp_bomberman
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Tue May  5 17:48:04 2015 David Tran
// Last update Fri May 22 01:49:56 2015 Jamais
//

#include "Engine.hh"

Engine::Engine(Board &board, UNUSED size_t x, UNUSED size_t y) : _board(board)
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
