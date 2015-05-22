//
// Cube.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sat May 16 22:31:54 2015 Jamais
// Last update Thu May 21 07:03:01 2015 Jamais
//

#include	"Cube.hh"

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
    // back face //
  _geometry.setColor(glm::vec4(1, 1, 1, 0));

  //  _geometry.setColor(glm::vec4(0.99, 0.80, 0.35, 1));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));

  // front face
  //  _geometry.setColor(glm::vec4(1.0f, 0.40f, 0.2, 1));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));

  // left face
  //  _geometry.setColor(glm::vec4(0.2, 1, 0.5, 1));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));

  // right face
  //  _geometry.setColor(glm::vec4(0.85, 0.0f, 0.17, 1));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));

  // upper face
  //  _geometry.setColor(glm::vec4(1, 0.0f, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));

  // downside face
  // _geometry.setColor(glm::vec4(0.5, 0.5, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));

  _geometry.build();
  return false;
}

// bool		Cube::initialize()
// {
//   _geometry.setColor(glm::vec4(0.99, 0.80, 0.35, 1));

//   _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
//   _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));
//   _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
//   _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));

//   _geometry.setColor(glm::vec4(1.0f, 0.40f, 0.2, 1));
//   _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
//   _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));
//   _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
//   _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));

//   _geometry.setColor(glm::vec4(0.2, 1, 0.5, 1));
//   _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
//   _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));
//   _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
//   _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));

//   _geometry.setColor(glm::vec4(0.85, 0.0f, 0.17, 1));
//   _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
//   _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));
//   _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
//   _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));

//   _geometry.setColor(glm::vec4(1, 0.0f, 1, 1));
//   _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
//   _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));
//   _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
//   _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));

//   _geometry.setColor(glm::vec4(0.5, 0.5, 1, 1));
//   _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 0.0f));
//   _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 0.0f));
//   _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));	_geometry.pushUv(glm::vec2(1.0f, 1.0f));
//   _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));	_geometry.pushUv(glm::vec2(0.0f, 1.0f));

//   _geometry.build();
//   return false;
// }

void		Cube::update(UNUSED gdl::Clock const& clock, UNUSED gdl::Input &input)
{
  // if (input.getKey(SDLK_UP))
  //   translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  // if (input.getKey(SDLK_DOWN))
  //   translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
  // if (input.getKey(SDLK_LEFT))
  //   translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  // if (input.getKey(SDLK_RIGHT))
  //   translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
}

void		Cube::draw(gdl::AShader &shader, UNUSED gdl::Clock const& clock)
{
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
