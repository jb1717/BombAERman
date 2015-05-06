//
// Crate.hh for Bomberman in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Wed May  6 11:59:37 2015 Jean-Baptiste Grégoire
// Last update Wed May  6 13:15:41 2015 Jean-Baptiste Grégoire
//

#ifndef CRATE_HH_
# define CRATE_HH_

# include <cstdlib>

class		Crate
{
public:
  enum	BonusType
    {
      SPEED = 0, RANGE, ADD, NONE
    };

public:
  Crate();
  BonusType	getBonus() const;
  ~Crate();

private:
  BonusType	_bonus;
};

#endif // !CRATE_HH_
