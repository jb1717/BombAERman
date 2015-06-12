//
// AGameModel.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 03:55:12 2015 Jamais
// Last update Fri Jun 12 04:03:21 2015 Jamais
//

#include	"AGameModel.hh"
#include	"Camera.hh"

AGameModel::AGameModel() : AGameObject()
{
  _transformMatrix = glm::translate(glm::mat4(1.0f), _position);
  _speed = 0.2f;
}

AGameModel::AGameModel(glm::vec3 const& position) : AGameObject(position)
{
  _transformMatrix = glm::translate(glm::mat4(1.0f), _position);
  _speed = 0.2f;
}

AGameModel::AGameModel(std::string const& filePath) : AGameObject()
{
  _transformMatrix = glm::translate(glm::mat4(1.0f), _position);
  _speed = 0.2f;
  load(filePath);
}

AGameModel::AGameModel(glm::vec3 const& position, std::string const& filePath) : AGameObject(position)
{
  _transformMatrix = glm::translate(glm::mat4(1.0f), _position);
  _speed = 0.2f;
  load(filePath);
}

AGameModel::~AGameModel()
{

}

void		AGameModel::draw(gdl::AShader& shader, gdl::Clock const& clock)
{
  shader.setUniform(SHADER_CURRENT_COLOR, _color);
  Model::draw(shader, getTransformation(), clock.getElapsed());
  shader.setUniform(SHADER_CURRENT_COLOR, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
}

void	       	AGameModel::update(UNUSED gdl::Clock const& clock, UNUSED Binput& input)
{

}

void	       	AGameModel::update(UNUSED gdl::Clock const& clock, UNUSED Binput& input, UNUSED Camera const& camera)
{}

void	       	AGameModel::update(UNUSED Binput& input, UNUSED Camera const& camera)
{}
