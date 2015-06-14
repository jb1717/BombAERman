//
// AFX.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sat Jun  6 04:02:46 2015 Jamais
// Last update Sun Jun 14 16:58:54 2015 Jamais
//

#include	"AFX.hh"
#include	"AssetManager.hh"
#include	"GeometryFactory.hh"

AFX::AFX(glm::vec3 const& v) : ComplexObject(), _index(0), _timer(0.5), _frameTimer(0.15)
{
  Geometric *g;
  auto		factory = GeometryFactory::instanciate();
  auto		asset = AssetManager::instance();

  _position = v;
  for (int i = 0; i < 5; i++)
    {
      g = new Geometric(_position, _rotation, glm::vec3(2, 2 ,2));
      g->setGeometry(factory->getGeometry(GeometryFactory::VERTICAL_PLANE));
      g->setTexture(*(*THEME((*THEME_HANDLER(asset["themes"]))["misc"]))["explosions2"]);
      g->scale(glm::vec3(1 + (5 - i), 1 + (5 - i), 1 + (5 - i)));
      g->scale(glm::vec3(0.15, 0.15, 0.15));
      g->rotate(glm::vec3(0, 0, 1), i * 10);
      g->translate(glm::vec3((0.2 * i - 0.5)  * 0.15, (0.2 * i - 0.5) * 0.15 , (-0.1 * i) * 0.15));
      _spareParts.push_back(g);
    }
}

void		AFX::resetFrame()
{
  _color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
  for (int i = 0; i < 5; i++)
    {
      _spareParts[i]->setPosition(_position);
      _spareParts[i]->setScale(glm::vec3(2, 2, 2));
      _spareParts[i]->setRotation(_rotation);
      _spareParts[i]->scale(glm::vec3(1 + (5 - i), 1 + (5 - i), 1 + (5 - i)));
      _spareParts[i]->scale(glm::vec3(0.15, 0.15, 0.15));
      _spareParts[i]->rotate(glm::vec3(0, 0, 1), i * 10);
      _spareParts[i]->translate(glm::vec3((0.2 * i - 0.5)  * 0.15, (0.2 * i - 0.5) * 0.15 , (-0.1 * i) * 0.15));
    }
}


AFX::~AFX()
{}

void		AFX::update(gdl::Clock const& clock, UNUSED Binput& input)
{
  _timer -= clock.getElapsed();
}

void		AFX::update(gdl::Clock const& clock, UNUSED Binput& input, Camera const& camera)
{
 _timer -= clock.getElapsed();
  for (size_t i = 0; i < _spareParts.size(); i++)
    {
      // _spareParts[i]->setRotation(glm::vec3(0, 10 * cos(camera.getRotation().y), 1));
      _spareParts[i]->AGameObject::update(clock, input, camera);
      _spareParts[i]->rotate(glm::vec3(0, 0, rand() % 10 * 0.15), -1);
      if (_timer >= 0.0f)
	_spareParts[i]->scale(glm::vec3(1.01, 1.01, 1.01));
      else
	_spareParts[i]->scale(glm::vec3(0.99, 0.99, 0.99));
    }
  _color.g *= 0.99;
  _color.b *= 0.99;
  _color.a *= 0.99;
}

void		AFX::draw(gdl::AShader& shader, gdl::Clock const& clock)
{
  if (_timer >= -1.0f)
    {
      shader.setUniform(SHADER_CURRENT_COLOR, _color);
      for (size_t i = 0; i < _spareParts.size(); i++)
	_spareParts[i]->draw(shader, clock);
      shader.setUniform(SHADER_CURRENT_COLOR,  glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    }
}

void		AFX::setTimer(float time)
{
  _timer = time;
  _frameTimer = time;
}
