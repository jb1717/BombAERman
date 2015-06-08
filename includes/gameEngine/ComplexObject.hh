//
// ComplexObject.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sat May 23 00:57:11 2015 Jamais
// Last update Wed Jun  3 19:28:14 2015 Jamais
//

#ifndef			___COMPLEX_OBJECT_HH___
# define		___COMPLEX_OBJECT_HH___

# include		"graphics.hh"

# include		"AGameObject.hh"
# include		"Geometric.hh"

class			ComplexObject : public AGameObject
{
protected:
  glm::vec3		_position;
  glm::vec3		_rotation;
  glm::vec3		_scale;

protected:
  std::vector<Geometric *>	_spareParts;

protected:
  int			_nbParts;

public:
  ComplexObject();
  ~ComplexObject();

public:
  virtual void	       		push_back(Geometric *elem);
  Geometric*   			operator[](unsigned int index);


public:
  bool			       	initialize();
  virtual void	       		update(gdl::Clock const& clock, gdl::Input &input);
  virtual void			draw(gdl::AShader& shader, gdl::Clock const& clock);

public:
  virtual void	       		translate(glm::vec3 const& moveVector);
  virtual void	       		rotate(glm::vec3 const& axis, float angle);
  virtual void	       		scale(glm::vec3 const& scaleVector);


public:
  Geometric*		       	getSparePart(unsigned int index);

public:
  void				setSparePart(Geometric* const sparePart, unsigned int index);
};

#endif			/* !___COMPLEX_OBJECT_HH___ */
