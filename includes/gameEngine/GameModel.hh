//
// GameModel.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Tue May 19 23:32:53 2015 Jamais
// Last update Wed Jun  3 19:28:13 2015 Jamais
//

#ifndef			___GAME_MODEL_HH___
# define		___GAME_MODEL_HH___

# include		"graphics.hh"

# include		"AGameObject.hh"
# include		"AGameModel.hh"

class			GameModel : public AGameModel
{
protected:
  float			_timer;

public:
  GameModel();
  GameModel(glm::vec3 const& position);
  GameModel(std::string const& filePath);
  GameModel(glm::vec3 const& position, std::string const& filePath);

public:
  ~GameModel();

public:
  void			draw(gdl::AShader& shader, gdl::Clock const& clock);
  void			update(gdl::Clock const& clock, gdl::Input &input);

public:
  void			setTimer(float timer);

public:
  float			getTimer() const;
};

#endif			/* !___GAME_MODEL_HH___ */
