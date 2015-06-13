//
// GameEngine.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:15:24 2015 Jamais
// Last update Fri Jun 12 03:09:54 2015 Jamais
//

#ifndef			___GAMEENGINE_HH___
# define		___GAMEENGINE_HH___

# include		<mutex>
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
extern std::mutex	_mutex;

# define		FRAGMENT_SHADER		"shaders/fragmentShader"
# define		VERTEX_SHADER		"shaders/vertexShader"

/*
** This macro is used to get the logical position from the x & z position of a AGameObject. **/
# define		LOGICAL_POSITION(x, y)				\
  (((x) - (((_board)->getWidth()) / (2))) < 0)			?	(((x) - ((_board)->getWidth()) / (2)) * (-1))		\
												:	((x) - ((_board)->getWidth()) / (2))				\
												,												\
  (((y) - ((_board)->getHeight()) / (2)) < 0)			?	(((y) - ((_board)->getHeight()) / (2)) * (-1))		\
												:	(((y) - ((_board)->getHeight()) / (2)))				\


extern Camera camera;

class			GameEngine : public gdl::Game
{
public:
  GameEngine();
  ~GameEngine();

public:
  bool			initialize();
  bool			loadShader();
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
  void			setInput(Binput const& input);
  void			setShader(gdl::BasicShader const& shader);

public:
  VideoContext*		getVideoContext() const;
  gdl::Clock		getClock() const;
  Binput  		getInput() const;
  gdl::BasicShader	getShader() const;

private:
  gdl::Clock		_clock;
  Binput		    _input;
  gdl::BasicShader	_shader;

private:
  std::vector<AGameObject*>	_objects;

private:
  VideoContext		*_videoContext;
  Board			*_board;
};

#endif			/* !___GAMEENGINE_HH___ */
