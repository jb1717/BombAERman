//
// Luainter.hh for Bomberman in /home/patoche/Rendu/CPP/cpp_bomberman/includes/ai/
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Thu May 21 15:36:38 2015 Hugo Prenat
// Last update Thu May 21 16:15:35 2015 Hugo Prenat
//

#ifndef LUAINTER_HH_
# define  LUAINTER_HH_

# include <string>
# include <iostream>

# include "lua.hh"

class Luainter {
public:
  Luainter();
  ~Luainter();

public:
  lua_State*	getState() const;

public:
  void		ExecuteFile(const std::string& fileName);
  void		ExecuteString(const std::string& expression);

private:
  void		report_errors(int state);

private:
  lua_State*	_L;
};

#endif // !LUAINTER_HH_
