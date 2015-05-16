//
// Engine.hh for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Tue May  5 17:48:33 2015 David Tran
// Last update Mon May 11 18:49:52 2015 David Tran
//

#ifndef Engine_HH_
# define Engine_HH_

# include <vector>
# include "Board.hh"
# include "Player.hh"
# include "EThread.hh"

class	EThread;

class	Engine
{
public:
  Engine(Board &Board, int players);
  ~Engine();
public:
  void		addPlayer();
  void		launch_players();
  void		create_all_players();
  void		run();
public:
  Board		&getBoard() const;
private:
  std::vector<EThread *>	_players;
  Board				&_Board;
  int				_nbPlayers;
};

void	*launch_player(void *);

#endif // !Engine_HH_
