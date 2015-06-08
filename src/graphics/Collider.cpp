//
// Collider.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Thu May 21 20:46:52 2015 Jamais
// Last update Mon May 25 07:24:14 2015 Jamais
//

#include		"Collider.hh"
#include		"AGameObject.hh"

Collider::Collider(AGameObject const& body) : _body(body)
{
  _refVector = _body.getScale();
  _refPosition = _body.getPosition();
}

// Collider::Collider(glm::vec3 const& refVector) : _refVector(refVector)
// {

// }

// Collider::Collider(Collider const& model)
// {
//   _refVector = model.getRefVector();
// }

Collider::~Collider()
{
}

glm::vec3		Collider::getRefVector() const
{
  return _refVector;
}

void			Collider::setRefVector(glm::vec3 const& refVector)
{
  _refVector = refVector;
}

bool			Collider::collide(AGameObject const& gameObject) const
{
  return overlap(_body.getPosition(), _body.getScale(), gameObject.getPosition(), gameObject.getScale());
}

bool			Collider::collide(glm::vec3 const& targetRefVector, glm::vec3 const& targetPosition) const
{
  return overlap(_body.getPosition(), _body.getScale(), targetPosition, targetRefVector);
}

bool			Collider::overlap(glm::vec3 const& refPosition, glm::vec3 const& refSize, glm::vec3 const& targetPosition, glm::vec3 const& targetSize) const
{
  glm::vec3		half(0.5, 0.5, 0.5);
  glm::vec3		up1(refPosition + refSize * half);
  glm::vec3		up2(targetPosition + targetSize * half);
  glm::vec3		down1(refPosition - refSize * half);
  glm::vec3		down2(targetPosition - targetSize * half);
  glm::vec3		result(0, 0, 0);

  if ((down1.x > down2.x && down1.x < up2.x) || (up1.x > down2.x && up1.x < up2.x))
    result.x = 1.0f;
  if ((down1.y > down2.y && down1.y < up2.y) || (up1.y > down2.y && up1.y < up2.y))
    result.y = 1.0f;
  if ((down1.z > down2.z && down1.z < up2.z) || (up1.z > down2.z && up1.z < up2.z))
    result.z = 1.0f;
  if ((targetPosition.x > down1.x && targetPosition.x < up1.x) || (refPosition.x > down2.x && refPosition.x < up2.x))
    result.x = 1.0f;
  if ((targetPosition.y > down1.y && targetPosition.y < up1.y) || (refPosition.y > down2.y  && refPosition.y < up2.y))
    result.y = 1.0f;
  if ((targetPosition.z > down1.z && targetPosition.z < up1.z) || (refPosition.z > down2.z && refPosition.z < up2.z))
    result.z = 1.0f;
  if (result.x != 0 && result.y != 0 && result.z != 0)
    return true;
  return false;
}
