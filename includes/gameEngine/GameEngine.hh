//
// GameEngine.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:15:24 2015 Jamais
// Last update Wed Jun  3 19:28:13 2015 Jamais
//

#ifndef			___GAMEENGINE_HH___
# define		___GAMEENGINE_HH___

# include		"graphics.hh"

# include		"VideoContext.hh"
# include		"AGameObject.hh"
# include		"AGameModel.hh"
# include		"Camera.hh"

# define		FRAGMENT_SHADER		"shaders/fragmentShader"
# define		VERTEX_SHADER		"shaders/vertexShader"

extern Camera camera;

class			GameEngine : public gdl::Game
{
public:
  GameEngine();
  ~GameEngine();

public:
  bool			initialize();
  bool			update();
  void			draw();

public:
  bool			createMap(std::string const& confFilePath);
  bool			setupGame(std::string const& filePath);
  bool			getEvent();
  bool			Animation();
  AGameObject*		findObject(int, int, int);

public:
  void			setVideoContext(VideoContext* const videoContext);
  void			setClock(gdl::Clock const& clock);
  void			setInput(gdl::Input const& input);
  void			setShader(gdl::BasicShader const& shader);

public:
  VideoContext*		getVideoContext() const;
  gdl::Clock		getClock() const;
  gdl::Input		getInput() const;
  gdl::BasicShader	getShader() const;

private:
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;

private:
  std::vector<AGameObject*>	_objects;

private:
  VideoContext		*_videoContext;
};

#endif			/* !___GAMEENGINE_HH___ */
