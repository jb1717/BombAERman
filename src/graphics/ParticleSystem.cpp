//
// ParticleSystem.cpp for  in /home/Jamais/partcilebomb
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Tue Jun  9 03:36:46 2015 Jamais
// Last update Fri Jun 12 06:17:22 2015 Jamais
//

#include		"ParticleSystem.hh"
#include		<algorithm>

ParticleSystem::ParticleSystem(glm::vec3 const& position, size_t nbParticles, float particleSpeed) : ComplexObject(), _position(position), _nbParticles(nbParticles), _particlesSpeed(particleSpeed)
{

}

void			ParticleSystem::resetParticle(Particle *fragment)
{
  fragment->_active = true;
  fragment->_life = -10.0f;
  //  fragment->_life = (float)(rand() % 100) * 0.01f + 0.05f;
  fragment->_fade = float(rand() % 100) / 1000.0f + 0.003f;
  fragment->_direction = glm::vec3(((float)((rand() % 50) - 25.0f) * 10.0f) / (_particlesSpeed * 10.0f),
  				   ((float)((rand() % 50) - 25.0f) * 10.0f) / (_particlesSpeed * 10.0f),
				   ((float)((rand() % 50) - 25.0f) * 10.0f) / (_particlesSpeed * 10.0f));
  fragment->_gravity = glm::vec3(0.0f, -0.001f, 0.0f);
  fragment->_start = 0.1 * (rand() % _nbParticles);
  fragment->rotate(glm::vec3(1, 0, 0), rand() % 120);
  fragment->rotate(glm::vec3(0, 1, 0), rand() % 120 + 120.0f);
  fragment->rotate(glm::vec3(0, 0, 1), rand() % 120 + 240.0f);
  fragment->setPosition(_position);
  fragment->setScale(glm::vec3(0.05, 0.05, 0.05));
  glm::vec4 c((float)(rand() % 100) / 100,
	      (float)(rand() % 100) / 100,
	      (float)(rand() % 100) / 100,
	      1.0f
	      );
  fragment->setGeometry(_factory->getGeometry(GeometryFactory::VERTICAL_PLANE, c, true));
}

void			ParticleSystem::generate()
{
  auto		asset = AssetManager::instance();
  Particle*	particle;

  AGameObject::translate(glm::vec3((float)(rand() % 50) - 25.0f,
				   0,
				   (float)(rand() % 50) - 25.0f
				   ));
  _factory = GeometryFactory::instanciate();
  _particleTexture = (*THEME((*THEME_HANDLER(asset["themes"]))["misc"]))["particle"];
  for (size_t i = 0; i < _nbParticles; i++)
    {
      particle = new Particle();
      resetParticle(particle);
      glm::vec4 c((float)(rand() % 100) / 100,
		  (float)(rand() % 100) / 100,
		  (float)(rand() % 100) / 100,
		  1.0f
		  );
      particle->setGeometry(_factory->getGeometry(GeometryFactory::VERTICAL_PLANE, c, true));
      particle->setTexture(*_particleTexture);
      particle->initialize();
      _particles.push_back(particle);
    }
  sort();
}

void			ParticleSystem::reset()
{
  for (size_t i = 0; i < _nbParticles; i++)
    {
      resetParticle(_particles[i]);
    }
  sort();
}

bool			ParticleSystem::operator()(Particle const *particle1, Particle const *particle2)
{
  return particle1->_direction.z >= particle2->_direction.z ? true : false;
}

void			ParticleSystem::sort()
{
  std::stable_sort (_particles.begin(), _particles.end(), *this);
  // for (auto i = _particles.begin(); i != _particles.end(); i++)
  //   std::cout << "[" << (*i)->_direction.z << "] < " << std::endl;
}

void			ParticleSystem::update(gdl::Clock const& clock, Binput& input)
{
  for (size_t i = 0; i < _nbParticles; i++)
    {
      if (_particles[i]->_active)
	{
	  _particles[i]->update(clock, input);
	  // if (_particles[i]->_start > 0.1f)
	  //   _particles[i]->setPosition(_position);
	}
    }
  sort();
}

void			ParticleSystem::draw(gdl::AShader& shader, gdl::Clock const& clock)
{
  for (size_t i = 0; i < _nbParticles; i++)
    {
      if (_particles[i]->_active && _particles[i]->_start < 0.1f)
	_particles[i]->draw(shader, clock);
    }
}
