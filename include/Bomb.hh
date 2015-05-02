//
// Bomb.hh for bomberman in /home/tran_0/rendu/cpp_bomberman/include
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Sat May  2 15:53:03 2015 David Tran
// Last update Sun May  3 01:09:17 2015 David Tran
//

#ifndef BOMB_HH_
# define BOMB_HH_

class	Bomb
{
public:
  Bomb(char Range = 0, bool Launch = false);
  ~Bomb();
public:
  char		getRange() const;
  void		setRange(char const &);
  bool		isLaunched();
  void		triggerLaunch();
private:
  char		range;
  bool		launched;
};

#endif // !Bomb_HH_
