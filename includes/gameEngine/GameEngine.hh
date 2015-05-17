//
// GameEngine.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:15:24 2015 Jamais
// Last update Sun May 17 02:31:52 2015 Jamais
//

#ifndef			___GAMEENGINE_HH___
# define		___GAMEENGINE_HH___

# include		"basics.hh"
# include		"graphics.hh"

# include		"VideoContext.hh"
# include		"AGameObject.hh"

# define		FRAGMENT_SHADER		"shaders/fragmentShader"
# define		VERTEX_SHADER		"shaders/vertexShader"

class			GameEngine : public gdl::Game
{
public:
  GameEngine();
  ~GameEngine();

public:
  bool			initialize();
  bool			update();
  void			draw();

private:
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;

private:
  std::vector<AGameObject*>	_objects;

private:
  VideoContext		*_videoContext;
};

#endif			/* !___GAMEENGINE_HH___ */
