//
// Bomb.hh for bomberman in /home/tran_0/rendu/cpp_bomberman/include
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Sat May  2 15:53:03 2015 David Tran
// Last update Mon May  4 18:41:22 2015 David Tran
//

#ifndef BOMB_HH_
# define BOMB_HH_

class	Bomb
{
public:
  Bomb(bool Launch = false, char Range = 2);
  ~Bomb();
public:
  bool		isLaunched() const;
  void		triggerLaunch();
public:
  char		getRange() const;
  void		setRange(char const &);
private:
  bool		launched;
  char		range;
};

#endif // !Bomb_HH_
