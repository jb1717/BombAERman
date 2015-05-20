//
// Camera.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 06:14:11 2015 Jamais
// Last update Tue May 19 23:50:50 2015 Jamais
//

#include	"Camera.hh"

Camera::Camera(int Id, glm::vec3 const& position, glm::vec3 const& target, glm::vec3 const& focus) :
  _camId(Id), _position(position), _target(target), _focus(focus),
  _rotation(0, 0, 0), _zoom(100, 100, 100),
  _fovy(60.0f), _ratio(800.0f / 600.0f), _zNear(0.1f), _zFar(100.0f)
{

}

Camera::~Camera()
{}

bool		Camera::setupCamera(VideoContext const& context)
{
  float		ratio;

  if ((ratio = context.getScreenWidth() / context.getScreenHeight()) == 0.0f)
    return false;
  setRatio(ratio);
  return true;
}

void		Camera::update()
{
  _projectionMatrix = glm::perspective(_fovy, _ratio,_zNear, _zFar);
  _transformationMatrix = glm::lookAt(_position, _target, _focus);
  _transformationMatrix = glm::rotate(_transformationMatrix, _rotation.x, glm::vec3(1, 0, 0));
  _transformationMatrix = glm::rotate(_transformationMatrix, _rotation.y, glm::vec3(0, 1, 0));
  _transformationMatrix = glm::rotate(_transformationMatrix, _rotation.z, glm::vec3(0, 0, 1));
  _transformationMatrix = glm::translate(_transformationMatrix, _position);
  _transformationMatrix = glm::scale(_transformationMatrix, _zoom);
}

int		Camera::getId() const
{
  return _camId;
}

glm::mat4	Camera::getTransformationMatrix() const
{
  return _transformationMatrix;
}

glm::mat4	Camera::getProjectionMatrix() const
{
  return _projectionMatrix;
}

glm::vec3	Camera::getPosition() const
{
  return _position;
}

glm::vec3	Camera::getTarget() const
{
  return _target;
}

glm::vec3	Camera::getFocus() const
{
  return _focus;
}

glm::vec3	Camera::getRotation() const
{
  return _rotation;
}

glm::vec3	Camera::getZoom() const
{
  return _zoom;
}

float		Camera::getFovy() const
{
  return _fovy;
}

float		Camera::getRatio() const
{
  return _ratio;
}

float		Camera::getZNear() const
{
  return _zNear;
}

float		Camera::getZFar() const
{
  return _zFar;
}

void		Camera::setTransformationMatrix(glm::mat4 const& transformationMatrix)
{
  _transformationMatrix = transformationMatrix;
}

void		Camera::setProjectionMatrix(glm::mat4 const& projectionMatrix)
{
  _projectionMatrix = projectionMatrix;
}

void		Camera::setPosition(glm::vec3 const& position)
{
  _position = position;
}

void		Camera::setTarget(glm::vec3 const& targetPosition)
{
  _target = targetPosition;
}

void		Camera::setRotation(glm::vec3 const& rotation)
{
  _rotation = rotation;
}

void		Camera::setZoom(glm::vec3 const& zoom)
{
  _zoom = zoom;
}

glm::mat4		Camera::translate(glm::vec3 const& translation)
{
  _transformationMatrix = glm::translate(_transformationMatrix, translation);
  _position += translation;
  return _transformationMatrix;
}

glm::mat4		Camera::translate(glm::mat4 const& transformMatrix, glm::vec3 const& translation)
{
  _transformationMatrix = glm::translate(transformMatrix, translation);
  _position += translation;
  return _transformationMatrix;
}

glm::mat4		Camera::rotate(glm::vec3 const& axis, float angle)
{
  _transformationMatrix = glm::rotate(_transformationMatrix, angle, axis);
  _rotation += axis * angle;
  return _transformationMatrix;
}

glm::mat4		Camera::rotate(glm::mat4 const& transformMatrix, glm::vec3 const& axis, float angle)
{
  _transformationMatrix = glm::rotate(transformMatrix, angle, axis);
  _rotation += axis * angle;
  return _transformationMatrix;
}

glm::mat4		Camera::zoom(float zoomRatio)
{
  _transformationMatrix = glm::scale(_transformationMatrix, glm::vec3(1 + zoomRatio,
								      1 + zoomRatio,
								      1 + zoomRatio));
  return _transformationMatrix;
}

glm::mat4		Camera::zoom(glm::vec3 const& zoom)
{
  _transformationMatrix = glm::scale(_transformationMatrix, zoom);
  _zoom *= zoom;
  return _transformationMatrix;
}

glm::mat4		Camera::zoom(glm::mat4 const& transformMatrix, glm::vec3 const& zoom)
{
  _transformationMatrix = glm::scale(transformMatrix, zoom);
  _zoom *= zoom;
  return _transformationMatrix;
}

void			Camera::setFovy(float fovy)
{
  _fovy = fovy;
}

void			Camera::setRatio(float ratio)
{
  _ratio = ratio;
}

void			Camera::setZNear(float zNear)
{
  _zNear = zNear;
}

void			Camera::setZFar(float zFar)
{
  _zFar = zFar;
}
