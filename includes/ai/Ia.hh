//
// Ia.hh for Bomberman in /home/patoche/rendu/CPP/cpp_bomberman
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Mon May 18 15:12:42 2015 Hugo Prenat
// Last update Thu May 21 16:07:30 2015 Hugo Prenat
//

#ifndef IA_HH_
# define IA_HH_

# include "../engine/Player.hh"
# include "Luainter.hh"

class Ia : public Player
{
public:
  Ia(std::string const &fileName, Board &Board);
  ~Ia();

private:
  std::string	_fileName;
};

#endif // !IA_HH_
