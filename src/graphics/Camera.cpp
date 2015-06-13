//
// Camera.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 06:14:11 2015 Jamais
// Last update Fri Jun 12 05:41:21 2015 Jamais
//

#include	"Camera.hh"

Camera::Camera(int Id, glm::vec3 const& position, glm::vec3 const& target, glm::vec3 const& focus) :
  _camId(Id), _position(position), _target(target), _focus(focus),
  _rotation(0, 0, 0), _zoom(1, 1, 1), _spin(1, 0, 1),
  _fovy(60.0f), _ratio(800.0f / 600.0f), _zNear(0.001f), _zFar(100000.0f)
{

}

Camera::~Camera()
{}

void		Camera::lockShader(gdl::AShader& shader, bool setColor, glm::vec4 const& color) const
{
  if (setColor)
    shader.setUniform(SHADER_CURRENT_COLOR, color);
  shader.setUniform(SHADER_TRANSFORMATION_MATRIX, getTransformationMatrix());
  shader.setUniform(SHADER_PROJECTION_MATRIX, getProjectionMatrix());
}

bool		Camera::setupCamera(VideoContext const& context)
{
  float		ratio;

  if ((ratio = static_cast<float>(context.getScreenWidth()) / static_cast<float>(context.getScreenHeight())) == 0.0f)
    return false;
  setRatio(ratio);
  return true;
}

void		Camera::update(UNUSED gdl::Clock const& clock, Binput& input)
{
  bomber::Event event;

  if (input._default.getMouseWheel().y)
    zoom(0.05 * input._default.getMouseWheel().y);
  if (input._default.getKey(SDL_BUTTON_LEFT))
    rotate(glm::vec3(0, 1, 0), static_cast<float>(input._default.getMouseDelta().x));
  if (input._default.getKey(SDL_BUTTON_RIGHT))
    {
      glm::vec3	delta(input._default.getMouseDelta().x * -0.1, input._default.getMouseDelta().y * 0.1, 0);
      _target += delta;
    }
  if (input._default.getKey(SDLK_KP_PLUS) || input.handleEvent(event, bomber::Event::TriggerLT))
    rotate(glm::vec3(-1, 0, 0), 0.10f);
  if (input._default.getKey(SDLK_KP_MINUS) || input.handleEvent(event, bomber::Event::TriggerRT))
    rotate(glm::vec3(1, 0, 0), 0.10f);
  if (input._default.getKey(SDLK_UP) || input.handleEvent(event, bomber::Event::JoyRightUp))
    move(glm::vec3(0, 0, 1));
  if (input._default.getKey(SDLK_DOWN) || input.handleEvent(event, bomber::Event::JoyRightDown))
    move(glm::vec3(0, 0, -1));
  if (input._default.getKey(SDLK_LEFT) || input.handleEvent(event, bomber::Event::JoyRightLeft))
    move(glm::vec3(1, 0, 0));
  if (input._default.getKey(SDLK_RIGHT) || input.handleEvent(event, bomber::Event::JoyRightRight))
    move(glm::vec3(-1, 0, 0));
  if (_position == _target)
    _target += glm::vec3(1, 1, 1);
  refreshPosition();
}

void		Camera::refreshPosition()
{
  _projectionMatrix = glm::perspective(_fovy, _ratio, _zNear, _zFar);
  _transformationMatrix = glm::lookAt(_position, _target, _focus);
  _transformationMatrix = glm::scale(_transformationMatrix, _zoom);
  _transformationMatrix = glm::rotate(_transformationMatrix, _rotation.x, glm::vec3(1, 0, 0));
  _transformationMatrix = glm::rotate(_transformationMatrix, _rotation.y, glm::vec3(0, 1, 0));
  _transformationMatrix = glm::rotate(_transformationMatrix, _rotation.z, glm::vec3(0, 0, 1));
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

glm::vec3	Camera::getSpin() const
{
  return _spin;
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

void		Camera::setSpin(glm::vec3 const& spin)
{
  _spin = spin;
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
  _zoom.x +=  zoomRatio;
  _zoom.y +=  zoomRatio;
  _zoom.z +=  zoomRatio;
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

glm::mat4		Camera::pivot(glm::vec3 const& spin)
{
  _spin += spin;
  return _transformationMatrix;
}

void			Camera::move(glm::vec3 const& direction)
{
  _target += direction;
  _position += direction;
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
