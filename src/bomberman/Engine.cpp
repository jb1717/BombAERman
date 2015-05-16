//
// Engine.cpp for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue May  5 17:48:04 2015 David Tran
// Last update Sat May 16 05:48:16 2015 David Tran
//

#include "Engine.hh"

Engine::Engine(Board &Board, int players) : _Board(Board), _nbPlayers(players)
{}

Engine::~Engine()
{}


void	Engine::addPlayer()
{
  _players.push_back(new EThread);
}

void	Engine::create_all_players()
{
  int	i = 0;

  while (i < _nbPlayers)
    {
      addPlayer();
      i++;
    }
}

Board	&Engine::getBoard() const
{
  return (_Board);
}

void	Engine::launch_players()
{
  std::vector<EThread *>::iterator	it = _players.begin();

  while (it != _players.end())
    {
      (*it)->launch(launch_player, this);
      it++;
    }
}

void	Engine::run()
{
  while (42)
    {
      if (getBoard().size() <= 1)
	return ;
      usleep(1000);
    }
}
