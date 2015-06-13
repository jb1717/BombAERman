//
// Bonus.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Fri Jun 12 23:10:03 2015 Jamais
// Last update Sat Jun 13 05:25:53 2015 Jamais
//

#ifndef			___BONUS_HH___
# define			___BONUS_HH___

# include		"graphics.hh"
# include		"AGameModel.hh"

class			Bonus : public AGameModel
{
public:
  Bonus();
  Bonus(glm::vec3 const& position);
  ~Bonus();

public:
  void			update(gdl::Clock const& clock, Binput& input);
};

#endif			/* !___BONUS_HH___ */
