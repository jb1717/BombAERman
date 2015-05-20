//
// Camera.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 05:42:13 2015 Jamais
// Last update Tue May 19 23:48:33 2015 Jamais
//

#ifndef			___CAMERA_HH___
# define		___CAMERA_HH___

# include		"basics.hh"
# include		"graphics.hh"
# include		"VideoContext.hh"

class			Camera
{
protected:
  int			_camId;

protected:
  glm::mat4		_transformationMatrix;
  glm::mat4		_projectionMatrix;

protected:
  glm::vec3		_position;
  glm::vec3		_target;
  glm::vec3		_focus;
  glm::vec3		_rotation;
  glm::vec3		_zoom;

protected:
  float			_fovy;
  float			_ratio;
  float			_zNear;
  float			_zFar;

public:
  Camera(
	 int Id = 0,
	 glm::vec3 const& position = glm::vec3(0, 10, -15),
	 glm::vec3 const& target = glm::vec3(0, 0, 0),
	 glm::vec3 const& focus = glm::vec3(0, 1, 0)
	 );
  ~Camera();

public:
  bool			setupCamera(VideoContext const& context);
  void			update();

public:
  int			getId() const;

public:
  glm::mat4		getTransformationMatrix() const;
  glm::mat4		getProjectionMatrix() const;

public:
  glm::vec3		getPosition() const;
  glm::vec3		getTarget() const;
  glm::vec3		getFocus() const;
  glm::vec3		getRotation() const;
  glm::vec3		getZoom() const;

public:
  float			getFovy() const;
  float			getRatio() const;
  float			getZNear() const;
  float			getZFar() const;

public:
  void			setTransformationMatrix(glm::mat4 const& transformationMatrix);
  void			setProjectionMatrix(glm::mat4 const& projectionMatrix);

public:
  void			setPosition(glm::vec3 const& position);
  void			setTarget(glm::vec3 const& targetPosition);
  void			setFocus(glm::vec3 const& focusPosition);
  void			setRotation(glm::vec3 const& rotation);
  void			setZoom(glm::vec3 const& rotation);

public:
  glm::mat4    		translate(glm::vec3 const& translation);
  glm::mat4    		translate(glm::mat4 const& transformMatrix, glm::vec3 const& translation);

public:
  glm::mat4    		rotate(glm::vec3 const& axis, float angle);
  glm::mat4    		rotate(glm::mat4 const& transformMatrix, glm::vec3 const& axis, float angle);

public:
  glm::mat4		zoom(float);
  glm::mat4    		zoom(glm::vec3 const& zoom);
  glm::mat4    		zoom(glm::mat4 const& transformMatrix, glm::vec3 const& zoom);

public:
  void			setFovy(float fovy);
  void			setRatio(float ratio);
  void			setZNear(float zNear);
  void			setZFar(float zFar);
};

#endif			/* !___CAMERA_HH___ */
