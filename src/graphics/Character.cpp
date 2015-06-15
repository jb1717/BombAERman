//
// Character.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Thu May 21 20:35:59 2015 Jamais
// Last update Sat Jun 13 23:53:24 2015 Jean-Baptiste Grégoire
//

#include		"Character.hh"
#include		"GameEngine.hh"
#include		<cmath>

Character::Character() : AGameModel(), _bombing(false)
{

}

Character::Character(glm::vec3 const& position) : AGameModel(position), _bombing(false)
{
}

Character::Character(std::string const& filePath) : AGameModel(filePath), _bombing(false)
{

}

Character::Character(glm::vec3 const& position, std::string const& filePath) : AGameModel(position, filePath), _bombing(false)
{

}


Character::~Character()
{

}


void			Character::update(Binput& input, Camera const& camera)
{
  float			angle = camera.getRotation().y * M_PI / 180;
  bomber::Event	event;

  _bombing = false;
   if (input._default.getKey(SDLK_z) || input.handleEvent(event, bomber::Event::JoyMiddleUp))
    {
      _rotation.y = -1 * camera.getRotation().y;
      translate(glm::vec3(-sin(angle) * _speed, 0, cos(angle) * _speed));
    }
  if (input._default.getKey(SDLK_s) || input.handleEvent(event, bomber::Event::JoyMiddleDown))
    {
      _rotation.y = 180 - camera.getRotation().y;
      translate(glm::vec3(sin(angle) * _speed, 0, -cos(angle) * _speed));
    }
  if (input._default.getKey(SDLK_q) || input.handleEvent(event, bomber::Event::JoyMiddleLeft))
    {
      _rotation.y = 90.0 - camera.getRotation().y;
      translate(glm::vec3(cos(angle) * _speed, 0, sin(angle) * _speed));
    }
  if (input._default.getKey(SDLK_d) || input.handleEvent(event, bomber::Event::JoyMiddleRight))
    {
      _rotation.y = 270.0 - camera.getRotation().y;
      translate(glm::vec3(-cos(angle) * _speed, 0, -sin(angle) * _speed));
    }
  if (input._default.getKey(SDLK_a))
    {
      _rotation.y = camera.getRotation().y + 45.0;
      translate(glm::vec3(cos(camera.getRotation().y + 45.0) * _speed, 0, sin(camera.getRotation().y + 45) * _speed));
    }
  if (input._default.getKey(SDLK_SPACE) || input.handleEvent(event, bomber::Event::Free3))
    {
      _bombing = true;
    }
}

void			Character::update(UNUSED gdl::Clock const& clock, Binput& input, Camera const& camera, long int id)
{
  float			angle = camera.getRotation().y * M_PI / 180;
  bomber::Event	event;

  _bombing = false;
  if ((id == 1 && input._default.getKey(SDLK_z)) || (id == 2 && (input.handleEvent(event, bomber::Event::JoyMiddleUp) || input._default.getKey(SDLK_KP_5))))
    {
      _rotation.y = -1 * camera.getRotation().y;
      translate(glm::vec3(-sin(angle) * _speed, 0, cos(angle) * _speed));
    }
  if ((id == 1 && input._default.getKey(SDLK_s)) || (id == 2 && (input.handleEvent(event, bomber::Event::JoyMiddleDown) || input._default.getKey(SDLK_KP_2))))
    {
      _rotation.y = 180 - camera.getRotation().y;
      translate(glm::vec3(sin(angle) * _speed, 0, -cos(angle) * _speed));
    }
  if ((id == 1 && input._default.getKey(SDLK_q)) || (id == 2 && (input.handleEvent(event, bomber::Event::JoyMiddleLeft) || input._default.getKey(SDLK_KP_1))))
    {
      _rotation.y = 90.0 - camera.getRotation().y;
      translate(glm::vec3(cos(angle) * _speed, 0, sin(angle) * _speed));
    }
  if ((id == 1 && input._default.getKey(SDLK_d)) || (id == 2 && (input.handleEvent(event, bomber::Event::JoyMiddleRight) || input._default.getKey(SDLK_KP_3))))
    {
      _rotation.y = 270.0 - camera.getRotation().y;
      translate(glm::vec3(-cos(angle) * _speed, 0, -sin(angle) * _speed));
    }
  if ((id == 1 && input._default.getKey(SDLK_a))|| (id == 2 && input._default.getKey(SDLK_KP_4)))
    {
      _rotation.y = camera.getRotation().y + 45.0;
      translate(glm::vec3(cos(camera.getRotation().y + 45.0) * _speed, 0, sin(camera.getRotation().y + 45) * _speed));
    }
  if ((id == 1 && input._default.getKey(SDLK_SPACE)) || (id == 2 && (input.handleEvent(event, bomber::Event::Free3) || input._default.getKey(SDLK_KP_ENTER))))
    {
      _bombing = true;
    }
}

glm::mat4			Character::getTransformation() const
{
  glm::mat4			model(1.0f);

  model = glm::translate(model, _position);
  model = glm::rotate(model, _rotation.y, glm::vec3(0, 1, 0));
  model = glm::scale(model, _scale);
  return model;
}

void				Character::addSpeed()
{
  _speed += 0.1f;
}
