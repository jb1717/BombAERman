//
// Bomb.hh for bomberman in /home/tran_0/rendu/cpp_bomberman/include
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Sat May  2 15:53:03 2015 David Tran
// Last update Sun May  3 01:45:03 2015 David Tran
//

#ifndef BOMB_HH_
# define BOMB_HH_

class	Bomb
{
public:
  Bomb(bool Launch = false);
  ~Bomb();
public:
  bool		isLaunched() const;
  void		triggerLaunch();
private:
  bool		launched;
};

#endif // !Bomb_HH_
