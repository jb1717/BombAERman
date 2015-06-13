//
// Character.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Thu May 21 20:35:59 2015 Jamais
// Last update Fri Jun 12 00:58:05 2015 Jamais
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
  if (input._default.getKey(SDLK_SPACE))
    {
      _bombing = true;
    }
}

void			Character::update(UNUSED gdl::Clock const& clock, Binput& input, Camera const& camera)
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
  if (input._default.getKey(SDLK_SPACE))
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
