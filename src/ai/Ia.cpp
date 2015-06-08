//
// Ia.cpp for Bomberman in /home/patoche/rendu/CPP/cpp_bomberman
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Mon May 18 15:23:47 2015 Hugo Prenat
// Last update Mon Jun  8 23:20:50 2015 Hugo Prenat
//

#include "Ia.hh"

static int	mapToStr(lua_State *L)
{
  int	argc = lua_gettop(L);
  Ia	*tmp;

  if (argc != 1)
    return (0);
  tmp = static_cast<Ia *> (lua_touserdata(L, lua_gettop(L)));
  if (tmp == NULL)
    return (0);
  tmp->getBoard().getFullBoard();
  return (2);
}

Ia::Ia(std::string const &fileName, Board &Board) : Player(Board),
						    _fileName(fileName)
{
	std::cout << "je créé l'IA" << std::endl;
  _key = -1;
  lua_pushlightuserdata(_lua.getState(), this);
  lua_setglobal(_lua.getState(), "iaPtr");
  _lua.executeFile(_fileName);
  _lua.addFunc(mapToStr, "mapToStr");
}

Ia::~Ia()
{

}

void	Ia::run_user()
{
  while (is_Alive())
    {
      if (!userAction())
        return ; // If Negative , throw
      checkPosPowerUp();
    }
}

bool	Ia::userAction()
{
  int	keyPressed = _key;

  if (keyPressed < 0)
    return (false);
  else if (keyPressed < 4)
    return (selectDirection(static_cast<Board::Direction>(keyPressed)));
  else if (keyPressed == 4)
    return (triggerOneBomb());
  return (false);
}

Board&	Ia::getBoard() const
{
  return (_board);
}
