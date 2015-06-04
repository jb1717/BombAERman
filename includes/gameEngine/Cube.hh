//
// Cube.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/includes/gameEngine
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sat May 16 22:22:44 2015 Jamais
// Last update Wed Jun  3 19:28:14 2015 Jamais
//

#ifndef			___CUBE_HH___
# define		___CUBE_HH___

# include		"graphics.hh"

# include		"AGameObject.hh"

class			Cube : public AGameObject
{
protected:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;
  float			_speed;

public:
  Cube();
  Cube(glm::vec3 const& position);
  Cube(glm::vec3 const& position, glm::vec3 const& rotation, glm::vec3 const& scale);
  Cube(AGameObject const& model);
  virtual ~Cube();

public:
  Cube&		operator=(AGameObject const& model);

public:
  float		getSpeed() const;

public:
  virtual bool		initialize();
  virtual void		update(gdl::Clock const& clock, gdl::Input& input);
  virtual void		draw(gdl::AShader &shader, gdl::Clock const& clock);

public:
  virtual void		setTexture(gdl::Texture const& texture);

};

#endif			/* !___CUBE_HH___ */
