//
// Character.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Thu May 21 20:35:59 2015 Jamais
// Last update Fri May 22 02:00:33 2015 Jamais
//

#include		"Character.hh"

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
  if (input.getKey(SDLK_z))
    translate(glm::vec3(0, 0, 0.01 * _speed));
  if (input.getKey(SDLK_s))
    translate(glm::vec3(0, 0, -0.01 * _speed));
  if (input.getKey(SDLK_q))
    translate(glm::vec3(0.01 * _speed, 0, 0));
  if (input.getKey(SDLK_d))
    translate(glm::vec3(-0.01 * _speed, 0, 0));
  // if (input.getKey(SDLK_z))
  //   move(glm::vec3(0, 0, 0.01 * _speed));
  // if (input.getKey(SDLK_s))
  //   move(glm::vec3(0, 0, -0.01 * _speed));
  // if (input.getKey(SDLK_q))
  //   move(glm::vec3(0.01 * speed, 0, 0));
  // if (input.getKey(SDLK_d))
  //   move(glm::vec3(-0.01 * speed, 0, 0));
}
