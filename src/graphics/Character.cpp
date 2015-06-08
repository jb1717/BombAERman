//
// Character.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Thu May 21 20:35:59 2015 Jamais
// Last update Sat Jun  6 02:36:27 2015 Jamais
//

#include		"Character.hh"
#include		"GameEngine.hh"
#include		<cmath>

Character::Character() : AGameModel()
{
}

Character::Character(glm::vec3 const& position) : AGameModel(position)
{

}

Character::Character(std::string const& filePath) : AGameModel(filePath)
{

}

Character::Character(glm::vec3 const& position, std::string const& filePath) : AGameModel(position, filePath)
{

}


Character::~Character()
{

}


void			Character::update(UNUSED gdl::Clock const& clock, UNUSED gdl::Input& input)
{
}

void			Character::update(UNUSED gdl::Input& input, UNUSED Camera const& camera)
{
}

void			Character::update(UNUSED gdl::Clock const& clock, gdl::Input& input, Camera const& camera)
{
  float		angle = camera.getRotation().y * M_PI / 180;

   if (input.getKey(SDLK_z))
    {
      _rotation.y = -1 * camera.getRotation().y;
      translate(glm::vec3(-sin(angle) * _speed, 0, cos(angle) * _speed));
    }
  if (input.getKey(SDLK_s))
    {
      _rotation.y = 180 - camera.getRotation().y;
      translate(glm::vec3(sin(angle) * _speed, 0, -cos(angle) * _speed));
    }
  if (input.getKey(SDLK_q))
    {
      _rotation.y = 90.0 - camera.getRotation().y;
      translate(glm::vec3(cos(angle) * _speed, 0, sin(angle) * _speed));
    }
  if (input.getKey(SDLK_d))
    {
      _rotation.y = 270.0 - camera.getRotation().y;
      translate(glm::vec3(-cos(angle) * _speed, 0, -sin(angle) * _speed));
    }
  if (input.getKey(SDLK_a))
    {
      _rotation.y = camera.getRotation().y + 45.0;
      translate(glm::vec3(cos(camera.getRotation().y + 45.0) * _speed, 0, sin(camera.getRotation().y + 45) * _speed));
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
