//
// Core.cpp for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue May  5 17:48:04 2015 David Tran
// Last update Thu May  7 14:21:19 2015 David Tran
//

#include "Core.hh"

Core::Core(Map &map, int players) : _map(map), _nbPlayers(players)
{}

Core::~Core()
{}


void	Core::addPlayer()
{
  _players.push_back(new EThread);
}

void	Core::create_all_players()
{
  int	i = 0;

  while (i < _nbPlayers)
    {
      addPlayer();
      i++;
    }
}

Map	&Core::getMap() const
{
  return (_map);
}

void	Core::launch_players()
{
  std::vector<EThread *>::iterator	it = _players.begin();

  while (it != _players.end())
    {
      (*it)->launch(launch_player, this);
      it++;
    }
}

void	Core::run()
{
  create_all_players();
  launch_players();
}
