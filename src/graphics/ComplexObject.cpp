//
// ComplexObject.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Wed May 27 18:16:38 2015 Jamais
// Last update Fri Jun 12 09:04:48 2015 Jamais
//

#include		"ComplexObject.hh"
#include		"Cube.hh"
#include		"GeometryFactory.hh"

ComplexObject::ComplexObject() : AGameObject(), _nbParts(0)
{
}

ComplexObject::~ComplexObject()
{

}

Geometric*      	ComplexObject::operator[](unsigned int index)
{
  return _spareParts[index];
}


void		ComplexObject::push_back(Geometric *elem)
{
  _spareParts.push_back(elem);
  _nbParts += 1;
}

bool		ComplexObject::initialize()
{
  for (std::vector<Geometric*>::iterator it = _spareParts.begin(); it != _spareParts.end(); it++)
    {
      if (!(*it)->initialize())
  	return false;
    }
  return true;
}

void		ComplexObject::update(gdl::Clock const& clock, gdl::Input& input)
{
  for (std::vector<Geometric*>::iterator it = _spareParts.begin(); it != _spareParts.end(); it++)
    {
      (*it)->update(clock, input);
    }
}

void		ComplexObject::draw(gdl::AShader& shader, gdl::Clock const& clock)
{
  for (std::vector<Geometric*>::iterator it = _spareParts.begin(); it != _spareParts.end(); it++)
    {
      (*it)->draw(shader, clock);
    }
}

Geometric*	ComplexObject::getSparePart(unsigned int index)
{
  return _spareParts[index];
}

void		ComplexObject::setSparePart(Geometric* const sparePart, unsigned int index)
{
  std::vector<Geometric*>::iterator it;
  unsigned int i = 0;

  for (it = _spareParts.begin(); i != index && it != _spareParts.end(); it++)
    ++i;
  _spareParts.insert(it, sparePart);
  _nbParts += 1;
}

void		ComplexObject::translate(glm::vec3 const& moveVector)
{
  AGameObject::translate(moveVector);
  for (std::vector<Geometric*>::iterator it = _spareParts.begin(); it != _spareParts.end(); it++)
    (*it)->translate(moveVector);
}

void		ComplexObject::rotate(glm::vec3 const& axis, float angle)
{
  AGameObject::rotate(axis, angle);
  for (std::vector<Geometric*>::iterator it = _spareParts.begin(); it != _spareParts.end(); it++)
    (*it)->rotate(axis, angle);
}

void		ComplexObject::scale(glm::vec3 const& scaleVector)
{
  AGameObject::scale(scaleVector);
  for (std::vector<Geometric*>::iterator it = _spareParts.begin(); it != _spareParts.end(); it++)
    (*it)->scale(scaleVector);
}
