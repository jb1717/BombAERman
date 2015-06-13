//
// UnbreakableWall.hh for Bomberman in /home/jibb/rendu/cpp_bomberman/src/bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Sat May 16 06:30:08 2015 Jean-Baptiste Grégoire
// Last update Sat May 16 06:30:10 2015 Jean-Baptiste Grégoire
//

#ifndef UNBREAKABLEWALL_HH_
# define UNBREAKABLEWALL_HH_

# include "AObj.hh"
# include "Board.hh"

class Board;

class UnbreakableWall : public AObj
{
public:
  UnbreakableWall(Board &board);
  ~UnbreakableWall();
};

#endif // !UNBREAKABLEWALL_HH_
