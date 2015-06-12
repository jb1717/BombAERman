//
// Cube.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sat May 16 22:31:54 2015 Jamais
// Last update Fri Jun 12 00:14:47 2015 Jamais
//

#include	"Cube.hh"
#include	"GeometryFactory.hh"

Cube::Cube() : AGameObject(), _speed(100.0f)
{}

Cube::Cube(glm::vec3 const& position) : AGameObject(position), _speed(50.0f)
{}

Cube::Cube(glm::vec3 const& position, glm::vec3 const& rotation, glm::vec3 const& scale) :
  AGameObject(position, rotation, scale), _speed(10.0f)
{}

Cube::Cube(AGameObject const& model) : AGameObject(model)
{
  _position = model.getPosition();
  _rotation = model.getRotation();
  _scale = model.getScale();
  _speed = 75.0f;
}

Cube&		Cube::operator=(AGameObject const& model)
{
  _position = model.getPosition();
  _rotation = model.getRotation();
  _scale = model.getScale();
  _speed = 75.0f;
  return (*this);
}

Cube::~Cube()
{}

void		Cube::setTexture(gdl::Texture const& texture)
{
  _texture = texture;
}

float		Cube::getSpeed() const
{
  return _speed;
}


bool		Cube::initialize()
{
  //   // back face //
  // _geometry.setColor(glm::vec4(1, 1, 1, 1));
  // _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  // _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));
  // _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  // _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));

  // // front face
  // _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  // _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));
  // _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  // _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));

  // // left face
  // _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  // _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));
  // _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  // _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));

  // // right face
  // _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  // _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));
  // _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  // _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));

  // // upper face
  // _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  // _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));
  // _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  // _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));

  // // downside face
  // _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  // _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));
  // _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  // _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));

  // _geometry.build();
  auto factory = GeometryFactory::instanciate();
  _geometry = factory->getGeometry(GeometryFactory::CUBE);
  return true;
}

void		Cube::update(UNUSED gdl::Clock const& clock, UNUSED gdl::Input &input)
{
}

void		Cube::draw(gdl::AShader &shader, UNUSED gdl::Clock const& clock)
{
  _texture.bind();
  // glEnable (GL_BLEND);
  // glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
