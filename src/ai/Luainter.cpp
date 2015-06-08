//
// Luainter.cpp for Bomberman in /home/patoche/Rendu/CPP/cpp_bomberman/src/ai/
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Thu May 21 15:34:11 2015 Hugo Prenat
// Last update Mon Jun  8 23:01:14 2015 Hugo Prenat
//

#include "Luainter.hh"

Luainter::Luainter(): _L(luaL_newstate())
{
  _L = luaL_newstate();
  if (_L == NULL)

  luaL_openlibs(_L);
  luaopen_base(_L);
  luaopen_table(_L);
  luaopen_io(_L);
  luaopen_string(_L);
  luaopen_math(_L);
}

lua_State*	Luainter::getState() const
{
  return (_L);
}

Luainter::~Luainter()
{
  lua_close(_L);
}

void	Luainter::report_errors(int state)
{
  if (state != 0)
    {
      std::cerr << "ERR: " << lua_tostring(_L, state) << std::endl;
      lua_pop(_L, 1);
    }
}

void	Luainter::executeFile(const std::string& fileName)
{
  int state;

  if (fileName == "")
    return ;
  state = luaL_dofile(_L, fileName.c_str());
  report_errors(state);
}

void	Luainter::executeString(const std::string& expression)
{
  int state;

  if (expression == "")
    return ;
  state = luaL_dostring(_L, expression.c_str());
  report_errors(state);
}

void	Luainter::addFunc(int (*func)(lua_State*), std::string const name)
{
  lua_pushcfunction(_L, func);
  lua_setglobal(_L, name.c_str());
}
