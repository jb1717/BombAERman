//
// Geometric.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Mon May 18 17:50:11 2015 Jamais
// Last update Sun Jun  7 13:56:22 2015 Jamais
//

#include	"Geometric.hh"

Geometric::Geometric() : AGameObject(), _speed(100.0f)
{}

Geometric::Geometric(glm::vec3 const& position) : AGameObject(position), _speed(50.0f)
{}

Geometric::Geometric(glm::vec3 const& position, glm::vec3 const& rotation, glm::vec3 const& scale) :
  AGameObject(position, rotation, scale), _speed(10.0f)
{}

Geometric::Geometric(AGameObject const& model) : AGameObject(model)
{
  _position = model.getPosition();
  _rotation = model.getRotation();
  _scale = model.getScale();
  _speed = 75.0f;
}

Geometric&		Geometric::operator=(AGameObject const& model)
{
  _position = model.getPosition();
  _rotation = model.getRotation();
  _scale = model.getScale();
  _speed = 75.0f;
  return (*this);
}

Geometric::~Geometric()
{}

void		Geometric::setTexture(gdl::Texture const& texture)
{
  _texture = texture;
}

float		Geometric::getSpeed() const
{
  return _speed;
}


bool		Geometric::initialize()
{
  _geometry.setColor(glm::vec4(1, 1, 1, 0.5));
  _geometry.pushVertex(glm::vec3(5, 0, -5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushVertex(glm::vec3(5, 0, 5));    	_geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushVertex(glm::vec3(-5, 0, 5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(-5, 0, -5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.build();
  return false;
}

void		Geometric::update(UNUSED gdl::Clock const& clock, UNUSED gdl::Input &input)
{

}

void		Geometric::draw(gdl::AShader &shader, UNUSED gdl::Clock const& clock)
{
  _texture.bind();
  // glEnable(GL_BLEND);
  // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  _geometry.draw(shader, getTransformation(), GL_QUADS);
  //  glEnable(GL_DEPTH_TEST);
}

void		Geometric::setGeometry(gdl::Geometry const& geometry)
{
  _geometry = geometry;
  _geometry.build();
}


gdl::Texture   	Geometric::getTexture() const
{
  return _texture;
}

gdl::Geometry	Geometric::getGeometry() const
{
  return _geometry;
}
