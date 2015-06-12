//
// ParticleSystem.hh for  in /home/Jamais/partcilebomb
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Tue Jun  9 03:33:58 2015 Jamais
// Last update Fri Jun 12 06:03:25 2015 Jamais
//

#ifndef				___PARTICLE_SYSTEM_HH___
# define			___PARTICLE_SYSTEM_HH___

# include	"graphics.hh"
# include	"Particle.hh"
# include	"ComplexObject.hh"
# include	"AssetManager.hh"

class				ParticleSystem : public ComplexObject
{
  gdl::Texture*			_particleTexture;
  glm::vec3			_position;
  size_t			_nbParticles;
  float				_particlesSpeed;
  std::vector<Particle* >	_particles;
  GeometryFactory*		_factory;
  void				resetParticle(Particle *fragment);

public:
  ParticleSystem(glm::vec3 const& position, size_t nbParticles, float particlesSpeed = 2000.0f);
  ~ParticleSystem() {}
  void		generate();
  void		update(gdl::Clock const& clock, Binput& input);
  void		reset();
  bool		operator()(Particle const*, Particle const*);
  void		sort();
  void		draw(gdl::AShader& shader, gdl::Clock const& clock);
};


#endif				/* !___PARTICLE_SYSTEM_HH___ */
