//
// Bomb.hh for bomberman in /home/tran_0/rendu/cpp_bomberman/include
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Sat May  2 15:53:03 2015 David Tran
// Last update Wed May 20 14:04:06 2015 David Tran
//

#ifndef BOMB_HH_
# define BOMB_HH_

# include <chrono>
# include <iostream>
# include "AObj.hh"
# include "Board.hh"
# include "Crate.hh"

class	Bomb : public AObj
{
public:
  Bomb(Board &Board, bool Launch = false, char Range = 2);
  ~Bomb();
public:
  bool			isLaunched() const;
  void			triggerLaunch();
  bool			explosion_check();
public:
  char			getRange() const;
  void			setRange(char const &);
  void			run();
  int			explosion();
private:
  bool					launched;
  std::chrono::steady_clock::time_point	_time;
  char					range;
};

#endif // !Bomb_HH_
