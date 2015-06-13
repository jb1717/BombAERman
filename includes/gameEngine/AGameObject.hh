//
// AGameObject.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/includes/gameEngine
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sat May 16 20:46:07 2015 Jamais
// Last update Sat Jun 13 23:44:38 2015 Jean-Baptiste Grégoire
//

#ifndef			___AGAMEOBJECT_HH___
# define		___AGAMEOBJECT_HH___

# include		"graphics.hh"
# include   "Binput.hh"
# include		"Collider.hh"

class			Camera;

class			AGameObject
{
protected:
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;

protected:
  glm::vec4	_color;

protected:
  Collider	*_hitBox;

public:
  AGameObject();
  AGameObject(glm::vec3 const& position);
  AGameObject(glm::vec3 const& position, glm::vec3 const& rotation, glm::vec3 const& scale);
  AGameObject(AGameObject const& model);
  virtual ~AGameObject();

public:
  AGameObject&		operator=(AGameObject const& model);

public:
  virtual void		setTexture(gdl::Texture const& texture);

public:
  virtual bool		initialize();
  virtual void		update(gdl::Clock const& clock, Binput &input);
  virtual void		update(gdl::Clock const& clock, Binput &input, Camera const& camera, long int id = 0);
  virtual void		update(Camera const& camera, gdl::Input& input);
  virtual void		draw(UNUSED gdl::AShader& shader, UNUSED gdl::Clock const& clock) {}

public:
  virtual void	       	translate(glm::vec3 const& translation);
  virtual void 		rotate(glm::vec3 const& axis, float angle);
  virtual void	       	scale(glm::vec3 const& scale);

public:
  glm::vec3			getPosition() const;
  glm::vec3			getRotation() const;
  glm::vec3			getScale() const;
  glm::vec4			getColor() const;

public:
  virtual glm::mat4    	getTransformation() const;

public:
  void				setPosition(glm::vec3 const& position);
  void				setRotation(glm::vec3 const& rotation);
  void				setScale(glm::vec3 const& scale);
  void				setColor(glm::vec4 const& color);

public:
  bool				collide(AGameObject const& body) const;
};

#endif			/* !___AGAMEOBJECT_HH___ */
