//
// Geometric.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/includes/gameEngine
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Mon May 18 17:47:06 2015 Jamais
// Last update Wed Jun  3 19:28:13 2015 Jamais
//

#ifndef			___GEOMETRIC_HH___
# define		___GEOMETRIC_HH___

# include		"graphics.hh"

# include		"AGameObject.hh"

class			Geometric : public AGameObject
{
protected:
  gdl::Texture		_texture;
  gdl::Geometry		_geometry;

protected:
  float			_speed;

protected:
  GLenum		_target;
  GLenum		_pname;
  GLint			_param;
  bool			_textureActive;

public:
  Geometric();
  Geometric(glm::vec3 const& position);
  Geometric(glm::vec3 const& position, glm::vec3 const& rotation, glm::vec3 const& scale);
  Geometric(AGameObject const& model);
  virtual ~Geometric();

public:
  Geometric&		operator=(AGameObject const& model);

public:
  float			getSpeed() const;

public:
  virtual bool		initialize();
  virtual void		update(gdl::Clock const& clock, gdl::Input& input);
  virtual void		draw(gdl::AShader &shader, gdl::Clock const& clock);

public:
  virtual void		setTexture(gdl::Texture const& texture);
  virtual void		setGeometry(gdl::Geometry const& geometry);

public:
  gdl::Texture		getTexture() const;
  gdl::Geometry		getGeometry() const;
};

#endif			/* !___GEOMETRIC_HH___ */
