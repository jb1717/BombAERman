//
// AObject.cpp for test in /home/Jamais/cpp_bomberman/includes/gameEngine
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sat May 16 21:09:42 2015 Jamais
// Last update Sat May 16 21:18:42 2015 Jamais
//

#include "AObject.hpp"
#include "basics.hh"

AObject::AObject()   :
  _position(0, 0, 0), // On initialise la position a 0
  _rotation(0, 0, 0), // pareil pour la rotation
  _scale(1, 1, 1) // l'echelle est mise a 1
{
}

AObject::~AObject() {}

void AObject::setTexture(gdl::Texture const& ) {}

bool AObject::initialize()
{
  return (true);
}

void AObject::update(UNUSED gdl::Clock const &clock, UNUSED gdl::Input &input)
{}

void AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

void AObject::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}
void AObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}
glm::mat4 AObject::getTransformation()
{
  glm::mat4 transform(1);

  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));

  transform = glm::translate(transform, _position);

  transform = glm::scale(transform, _scale);
  return (transform);
}
