//
// Core.hh for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue May  5 17:48:33 2015 David Tran
// Last update Tue May  5 18:19:44 2015 David Tran
//

#ifndef CORE_HH_
# define CORE_HH_

# include <vector>
# include "Map.hh"
# include "Player.hh"

class	Core
{
public:
  Core(Map &map);
  ~Core();
public:
  void		addPlayer();
private:
  std::vector<Player *>		_players;
  Map				&_map
};

#endif // !CORE_HH_
