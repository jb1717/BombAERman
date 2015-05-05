//
// Core.cpp for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue May  5 17:48:04 2015 David Tran
// Last update Tue May  5 18:19:32 2015 David Tran
//

#include "Core.hh"

Core::Core(Map &map) : _map(map)
{

}

~Core::Core()
{}


void	Core::addPlayer()
{
  _players.push_back(new Player(1, true, _map));
}
