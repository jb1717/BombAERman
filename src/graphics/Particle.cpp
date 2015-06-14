//
// Particle.cpp for  in /home/Jamais/partcilebomb
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Tue Jun  9 03:26:25 2015 Jamais
// Last update Sun Jun 14 14:57:21 2015 Jamais
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
  _color = color;
}

void			Particle::update(UNUSED gdl::Clock const& clock, UNUSED Binput& input)
{
  _life -= clock.getElapsed();
  _fade -= 0.01f;
  if (_start > 0.0f)
    _start -= clock.getElapsed();
  else
    {
  _rotation.x += 0.01f;
  translate(_direction);
  _direction.y = _direction.y - 0.01f * _gravity.y;
    }
  if (_life <= 0.0f)
    _active = false;
}
