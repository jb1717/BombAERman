#ifndef			___AGAME_MODEL_HH___
# define		___AGAME_MODEL_HH___

# include		"graphics.hh"

# include		"Model.hh"
# include		"AGameObject.hh"

class			AGameModel : public AGameObject, public gdl::Model
{
protected:
  glm::mat4		_transformMatrix;
  float			_speed;

public:
  AGameModel();
  AGameModel(glm::vec3 const& position);
  AGameModel(std::string const& filePath);
  AGameModel(glm::vec3 const& position, std::string const& filePath);

public:
  virtual ~AGameModel();

public:
  virtual void		draw(gdl::AShader& shader, gdl::Clock const& clock);

public:
  virtual void		update(gdl::Clock const& clock, gdl::Input &input);

};

#endif			/* !___AGAME_MODEL_HH___ */
