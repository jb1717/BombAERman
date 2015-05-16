//
// AGameObject.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/includes/gameEngine
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sat May 16 20:46:07 2015 Jamais
// Last update Sat May 16 20:51:00 2015 Jamais
//

#ifndef			___AGAMEOBJECT_HH___
# define		___AGAMEOBJECT_HH___

# include		"basics.hh"
# include		"graphics.hh"

class			AGameObject
{
public:
  AGameObject();
  ~AGameObject();

public:
  virtual void	setTexture(gdl::Texture const&);

public:
  virtual bool	initialize();
  virtual void	update(gdl::Clock const& clock, gdl::Input &input);
  virtual void	draw(gdl::AShader& shader, gdl::Clock const& clock) = 0;

public:
  void	translate(glm::vec3 const&);
  void	rotate(glm::vec3 const&, float);
  void	scale(glm::vec3 const&);
  glm::mat4	getTransformation();

protected:
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;
};

#endif			/* !___AGAMEOBJECT_HH___ */
