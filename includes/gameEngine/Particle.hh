//
// Particle.hh for  in /home/Jamais/partcilebomb
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Tue Jun  9 03:18:18 2015 Jamais
// Last update Fri Jun 12 06:03:04 2015 Jamais
//

#ifndef			___PARTICLE_HH___
# define		___PARTICLE_HH___

# include	"graphics.hh"
# include	"Geometric.hh"
# include	"GeometryFactory.hh"

class		Particle : public Geometric
{
  /*to be passed in private */
public:
  float		_life;
  float		_fade;
  glm::vec3	_gravity;
  glm::vec4	_color;
  glm::vec3	_direction;
  bool		_active;
  float		_start;

public:
  Particle(float life = 10.0f,
	   float fade = 10.0f,
	   glm::vec3 const& gravity = glm::vec3(0, 0, 0),
	   glm::vec4 const& color = glm::vec4(1, 1, 1, 1));
  ~Particle();
  void		update(gdl::Clock const& clock, Binput& input);
  void		setColor(glm::vec4 const& color);
};

#endif			/* !___PARTICLE_HH___ */
