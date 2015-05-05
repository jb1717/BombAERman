//
// Bomb.hh for bomberman in /home/tran_0/rendu/cpp_bomberman/include
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Sat May  2 15:53:03 2015 David Tran
// Last update Tue May  5 17:41:37 2015 David Tran
//

#ifndef BOMB_HH_
# define BOMB_HH_

# include <ctime>
# include <iostream>

class	Bomb
{
public:
  Bomb(bool Launch = false, char Range = 2);
  ~Bomb();
public:
  bool			isLaunched() const;
  void			triggerLaunch(int x, int y);
  bool			explosion_check();
public:
  char			getRange() const;
  void			setRange(char const &);
  std::pair<int, int>	get_coord() const;
private:
  bool			launched;
  std::clock_t		_start;
  char			range;
  std::pair<int, int>	_coord;
};

#endif // !Bomb_HH_
