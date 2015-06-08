//
// Luainter.hh for Bomberman in /home/patoche/Rendu/CPP/cpp_bomberman/includes/ai/
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Thu May 21 15:36:38 2015 Hugo Prenat
// Last update Mon Jun  8 23:01:19 2015 Hugo Prenat
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
  void		executeFile(const std::string& fileName);
  void		executeString(const std::string& expression);
  void		addFunc(int (*func)(lua_State*), std::string const name);

private:
  void		report_errors(int state);

private:
  lua_State*	_L;
};

#endif // !LUAINTER_HH_
