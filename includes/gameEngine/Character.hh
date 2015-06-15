//
// Character.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Thu May 21 01:55:08 2015 Jamais
// Last update Sat Jun 13 23:32:10 2015 Jean-Baptiste Grégoire
//

#ifndef			___CHARACTER_HH___
# define		___CHARACTER_HH___

# include		"graphics.hh"
# include   "Binput.hh"
# include		"AGameModel.hh"

enum		eAction
  {
    MOVE	= 1,
    BOMBING,
    DEFAULT
  };

class			Character : public AGameModel
{
public:
  Character();
  Character(glm::vec3 const& position);
  Character(std::string const& filePath);
  Character(glm::vec3 const& position, std::string const& filePath);
  ~Character();

public:
  void      		update(Binput& input, Camera const& camera);
  void      		update(gdl::Clock const& clock, Binput& input, Camera const& camera, long int id = 0);

public:
  glm::mat4		getTransformation() const;
  void			addSpeed();

public:
  bool			_bombing;
public:
};

#endif			/* !___CHARACTER_HH___ */
