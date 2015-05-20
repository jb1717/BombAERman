//
// Ia.hh for Bomberman in /home/patoche/rendu/CPP/cpp_bomberman
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Mon May 18 15:12:42 2015 Hugo Prenat
// Last update Mon May 18 17:28:11 2015 Hugo Prenat
//

#ifndef IA_HH_
# define IA_HH_

# include "../engine/Player.hh"

class Ia : public Player
{
public:
  Ia(std::string const &fileName, Board &Board);
  ~Ia();
};

#endif // !IA_HH_
