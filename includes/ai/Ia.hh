//
// Ia.hh for Bomberman in /home/patoche/rendu/CPP/cpp_bomberman
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Mon May 18 15:12:42 2015 Hugo Prenat
// Last update Mon Jun  8 23:20:58 2015 Hugo Prenat
//

#ifndef IA_HH_
# define IA_HH_

# include "../engine/Player.hh"
# include "Luainter.hh"

class		Ia : public Player
{
public:
  Ia(std::string const &fileName, Board &Board);
  ~Ia();

public:
  Board&	getBoard() const;

public:
  bool		userAction();
  void		run_user();

private:
  int		_key;
  std::string	_fileName;
  Luainter	_lua;
};

#endif // !IA_HH_
