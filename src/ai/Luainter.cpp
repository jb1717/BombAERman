//
// Luainter.cpp for Bomberman in /home/patoche/Rendu/CPP/cpp_bomberman/src/ai/
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Thu May 21 15:34:11 2015 Hugo Prenat
// Last update Thu May 21 16:16:15 2015 Hugo Prenat
//

#include "Luainter.hh"

Luainter::Luainter(): _L(luaL_newstate())
{
  luaL_openlibs(_L);
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

void	Luainter::ExecuteFile(const std::string& fileName)
{
  int state;

  if (fileName == "")
    return ;
  state = luaL_dofile(_L, fileName.c_str());
  report_errors(state);
}

void	Luainter::ExecuteString(const std::string& expression)
{
  int state;

  if (expression == "")
    return ;
  state = luaL_dostring(_L, expression.c_str());
  report_errors(state);
}
