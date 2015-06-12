//
// BasicBomb.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Wed May 20 21:13:09 2015 Jamais
// Last update Fri Jun 12 03:59:52 2015 Jamais
//

#ifndef			___BASIC_BOMB_HH___
# define		___BASIC_BOMB_HH___

# include		"graphics.hh"

# include		"ABomb.hh"

class			BasicBomb : public ABomb
{
public:
  BasicBomb();
  ~BasicBomb();

public:
  void			update(gdl::Clock const& clock, Binput& input);
};

#endif			/* !___BASIC_BOMB_HH___ */
