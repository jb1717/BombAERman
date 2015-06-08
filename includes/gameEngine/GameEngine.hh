//
// GameEngine.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:15:24 2015 Jamais
// Last update Mon Jun  8 06:59:00 2015 Jamais
//

#ifndef			___GAMEENGINE_HH___
# define		___GAMEENGINE_HH___

# include		"graphics.hh"

# include		"VideoContext.hh"
# include		"AGameObject.hh"
# include		"AGameModel.hh"
# include		"Camera.hh"
# include		"Board.hh"
# include		"AObj.hh"

# include		"BasicBomb.hh"
# include		"Character.hh"

extern AGameModel	*bomb;
extern Character	*hero;
extern gdl::Texture	*texFloor;
extern gdl::Texture	*texCrate;
extern gdl::Texture	*texWall;
extern VideoContext	*V;

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
  bool			setupGame(Board* board);
  bool			getEvent();

public:
  void			updateCell(std::vector<AObj *>& cellVector);
  void			drawCell(std::vector<AObj *>& cellVector);

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
  Board			*_board;
};

#endif			/* !___GAMEENGINE_HH___ */
