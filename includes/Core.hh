//
// Core.hh for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue May  5 17:48:33 2015 David Tran
// Last update Thu May  7 14:21:15 2015 David Tran
//

#ifndef CORE_HH_
# define CORE_HH_

# include <vector>
# include "Map.hh"
# include "Player.hh"
# include "EThread.hh"

class	EThread;

class	Core
{
public:
  Core(Map &map, int players);
  ~Core();
public:
  void		addPlayer();
  void		launch_players();
  void		create_all_players();
public:
  Map		&getMap() const;
private:
  std::vector<EThread *>	_players;
  Map				&_map;
  int				_nbPlayers;
};

void	*launch_player(void *);

#endif // !CORE_HH_
