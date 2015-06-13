//
// UnbreakableWall.cpp for Bomberman in /home/jibb/rendu/cpp_bomberman/src/bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Sat May 16 06:29:55 2015 Jean-Baptiste Grégoire
// Last update Sat May 16 06:29:57 2015 Jean-Baptiste Grégoire
//

# include "UnbreakableWall.hh"

UnbreakableWall::UnbreakableWall(Board &board): AObj(board, 0, 0)
{
  _type = UNBREAKABLE_WALL;
  _id = Board::Wall;
}

UnbreakableWall::~UnbreakableWall()
{

}
