//
// Collider.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Thu May 21 20:39:01 2015 Jamais
// Last update Thu May 21 21:20:45 2015 Jamais
//

#ifndef			___COLLIDER_HH___
# define		___COLLIDER_HH___

# include		"basics.hh"
# include		"graphics.hh"

class			AGameObject;

class			Collider
{
private:
  glm::vec3		_refVector;
  glm::vec3		_refPosition;

private:
  AGameObject const&   	_body;

private:
  bool			overlap(glm::vec3 const& refPosition, glm::vec3 const& refSize, glm::vec3 const& targetPosition, glm::vec3 const& targetSize) const;

public:
  Collider(AGameObject const& body);
  //  Collider(glm::vec3 const& refVector);
  //  Collider(Collider const& model);
  ~Collider();

public:
  glm::vec3		getRefVector() const;

public:
  void			setRefVector(glm::vec3 const& refVector);

public:
  bool			collide(AGameObject const& gameObject) const;
  bool			collide(glm::vec3 const& targetRefVector, glm::vec3 const& targetPosition) const;

};

#endif			/* !___COLLIDER_HH___ */
