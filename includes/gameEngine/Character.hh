//
// Character.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Thu May 21 01:55:08 2015 Jamais
// Last update Fri May 22 01:58:34 2015 Jamais
//

#ifndef			___CHARACTER_HH___
# define		___CHARACTER_HH___

# include		"basics.hh"
# include		"graphics.hh"

# include		"AGameModel.hh"

class			Character : public AGameModel
{
public:
  Character();
  Character(glm::vec3 const& position);
  Character(std::string const& filePath);
  Character(glm::vec3 const& position, std::string const& filePath);
  ~Character();

public:
  void			update(gdl::Clock const& clock, gdl::Input& input);

};

#endif			/* !___CHARACTER_HH___ */
