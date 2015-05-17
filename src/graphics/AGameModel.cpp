//
// AGameModel.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 03:55:12 2015 Jamais
// Last update Sun May 17 04:08:03 2015 Jamais
//

#include	"AGameModel.hh"

AGameModel::AGameModel() : AGameObject()
{
  _transformMatrix = glm::translate(glm::mat4(1.0f), _position);
  _speed = 10.0f;
}

AGameModel::AGameModel(glm::vec3 const& position) : AGameObject(position)
{
  _transformMatrix = glm::translate(glm::mat4(1.0f), _position);
  _speed = 10.0f;
}

AGameModel::AGameModel(std::string const& filePath) : AGameObject()
{
  _transformMatrix = glm::translate(glm::mat4(1.0f), _position);
  _speed = 10.0f;
  load(filePath);
}

AGameModel::AGameModel(glm::vec3 const& position, std::string const& filePath) : AGameObject(position)
{
  _transformMatrix = glm::translate(glm::mat4(1.0f), _position);
  _speed = 10.0f;
  load(filePath);
}

AGameModel::~AGameModel()
{

}

void		AGameModel::draw(gdl::AShader& shader, gdl::Clock const& clock)
{
  Model::draw(shader, getTransformation(), clock.getElapsed());
}

void	       	AGameModel::update(UNUSED gdl::Clock const& clock, UNUSED gdl::Input& input)
{

}
