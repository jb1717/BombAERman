//
// AGameObject.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sat May 16 20:52:10 2015 Jamais
// Last update Sat May 16 21:18:55 2015 Jamais
//

#include	"AGameObject.hh"

AGameObject::AGameObject() : _position(0, 0, 0), _rotation(0, 0, 0), _scale(1, 1, 1)
{}

AGameObject::~AGameObject() {}

void		AGameObject::setTexture(gdl::Texture const& ) {}
bool		AGameObject::initialize() { return true; }

void		AGameObject::update(UNUSED gdl::Clock const& clock, UNUSED gdl::Input &input)
{}

void		AGameObject::translate(glm::vec3 const& v)
{
  _position += v;
}

void		AGameObject::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

void		AGameObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4	AGameObject::getTransformation()
{
  glm::mat4	transform(1);

  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::translate(transform, _position);
  transform = glm::scale(transform, _scale);
  return transform;
}
