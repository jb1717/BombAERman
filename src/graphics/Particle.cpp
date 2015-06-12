//
// Particle.cpp for  in /home/Jamais/partcilebomb
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Tue Jun  9 03:26:25 2015 Jamais
// Last update Fri Jun 12 06:16:52 2015 Jamais
//

#include "Particle.hh"

Particle::Particle(float life, float fade, glm::vec3 const& gravity, glm::vec4 const& color) : Geometric(
													 glm::vec3(0, 0, 0),
													 glm::vec3(0, 0, 0),
													 glm::vec3(0.10f, 0.10f, 0.10f)
													 ),
											       _life(life),
											       _fade(fade),
											       _gravity(gravity),
											       _color(color),
											       _active(false)
{
  _direction = glm::vec3(0.001, 0.001, 0.001);
  _start = -0.1f;
}

Particle::~Particle()
{}

void			Particle::setColor(glm::vec4 const& color)
{
  auto f = GeometryFactory::instanciate();

  setGeometry(f->getGeometry(GeometryFactory::VERTICAL_PLANE));
  _geometry.build();
}

void			Particle::update(gdl::Clock const& clock, Binput& input)
{
  // _life -= clock.getElapsed();
  // _fade -= 0.01f;
  // if (_start > 0.0f)
  //   _start -= clock.getElapsed();
  // _start = -1.0f;
  // else
  //   {
  _rotation.x += 0.01f;
  translate(_direction);
  _direction.y = _direction.y - 0.01f /*_gravity.y*/;
    // }
  // if (_life <= 0.0f)
  //   _active = false;
}
