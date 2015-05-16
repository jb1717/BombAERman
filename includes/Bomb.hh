//
// Bomb.hh for bomberman in /home/tran_0/rendu/cpp_bomberman/include
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Sat May  2 15:53:03 2015 David Tran
// Last update Sat May 16 06:51:42 2015 David Tran
//

#ifndef BOMB_HH_
# define BOMB_HH_

# include <chrono>
# include <iostream>
# include "AObj.hh"

class	Bomb : public AObj
{
public:
  Bomb(Board &Board, bool Launch = false, char Range = 2);
  ~Bomb();
public:
  bool			isLaunched() const;
  void			triggerLaunch(int x, int y);
  bool			explosion_check();
public:
  char			getRange() const;
  void			setRange(char const &);
  void			run();
private:
  bool					launched;
  std::chrono::steady_clock::time_point	time;
  char					range;
};

#endif // !Bomb_HH_
