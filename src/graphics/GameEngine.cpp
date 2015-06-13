//
// GameEngine.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:23:57 2015 Jamais
// Last update Fri Jun 12 09:42:11 2015 Jamais
//

#include	"GameEngine.hh"
#include	"Cube.hh"
#include	"Camera.hh"
#include	"BasicBomb.hh"
#include	"Character.hh"
#include	"Skybox.hh"
#include	"GeometryFactory.hh"
#include	"ComplexObject.hh"
#include	"GraphicString.hh"
#include	"Board.hh"
#include	"AObj.hh"
#include	"Crate.hh"
#include	"Player.hh"
#include	"Bomb.hh"
#include	"AssetManager.hh"
#include	"AFX.hh"
#include	"ParticleSystem.hh"

#include	<unistd.h>

/**/
Camera		camera;
Camera		menuCam;

Skybox		*sk;
AGameModel*	bomb;
gdl::Texture	*texFloor;
gdl::Texture	*texCrate;
gdl::Texture	*texWall;
gdl::Texture*	texMenu;

bool		GUI = true;
GraphicString*	s;
GraphicString*	playerIndic;
Geometric* bombChooser;
Geometric* menu;
ParticleSystem*	psystem;

AFX*			effect;

Geometric*		ground;
GameEngine::GameEngine() : Game()
{
  _videoContext = VideoContext::instanciate();
  auto		asset = AssetManager::instance();
  texCrate = (*THEME((*THEME_HANDLER(asset["themes"]))["default"]))["crate"];
  texWall = (*THEME((*THEME_HANDLER(asset["themes"]))["default"]))["wall"];
  texMenu = (*THEME((*THEME_HANDLER(asset["themes"]))["GUI"]))["menu"];
  bomb = new BasicBomb();
}

bool		GameEngine::createMap(UNUSED std::string const& confFilePath)
{
   return true;
}

bool		GameEngine::setupGame(Board* board)
{
  _board = board;
  return true;
}

bool		GameEngine::loadShader()
{
  if (!_shader.load(FRAGMENT_SHADER, GL_FRAGMENT_SHADER)
      || !_shader.load(VERTEX_SHADER, GL_VERTEX_SHADER)
      || !_shader.build())
    return false;

  _shader.bind();

  return true;
}

bool		GameEngine::initialize()
{
  auto factory = GeometryFactory::instanciate();

  if (!camera.setupCamera(*_videoContext))
      return false;

  if (!loadShader())
    return false;

  glEnable(GL_SCISSOR_TEST);
  camera.refreshPosition();

  /**/
  menuCam.setPosition(glm::vec3(0, 0, -3));
  menuCam.refreshPosition();
  /**/
  /**/
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_FLAT);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
  /**/

  camera.lockShader(_shader, true);

  /**/
  sk = new Skybox();
  sk->generate("default");
  /**/

  auto asset = AssetManager::instance();


  bombChooser = new Geometric();
  bombChooser->setGeometry(factory->getGeometry(GeometryFactory::PLANE));
  bombChooser->setTexture(*(*THEME((*THEME_HANDLER(asset["themes"]))["default"]))["GUIBomb"]);
  bombChooser->setPosition(glm::vec3(-1.90, -1.25, 0.0));

  s = new GraphicString("LOADING");
  s->render(*factory);
  s->translate(glm::vec3(-5, 15, 25));

  bomb->setPosition(bombChooser->getPosition());
  bomb->translate(glm::vec3(0, -0.10, 0));
  bomb->scale(glm::vec3(0.40, 0.40, 0.40));
  bomb->setColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
  menu = new Geometric(glm::vec3(0, 0, -2));
  menu->setGeometry(factory->getGeometry(GeometryFactory::VERTICAL_PLANE));
  menu->setTexture(*texMenu);

  ground = new Geometric(glm::vec3(0, -0.00f, 0));
  ground->setGeometry(factory->getGeometry(GeometryFactory::CUBE));
  ground->setTexture(*(*THEME((*THEME_HANDLER(asset["themes"]))["default"]))["floor"]);
  ground->scale(glm::vec3(_board->getHeight()  -1.0f, 1, _board->getWidth() -1.0f));

  /*
  ** Special Effect of explosion :: folow it in update and draw */
  effect = new AFX(glm::vec3(0 , 2, 0));
  effect->setScale(glm::vec3(2, 2, 2));
  effect->resetFrame();

  return true;
}

bool		GameEngine::getEvent()
{
  bomber::Event event;

  if (_input._default.getKey(SDLK_ESCAPE) || _input._default.getInput(SDL_QUIT) ||
      _input.handleEvent(event, bomber::Event::Start))
    return false;

  if (_input._default.getMouseWheel().y) {
    camera.zoom(0.05 * _input._default.getMouseWheel().y);
  }
  if (_input._default.getKey(SDLK_f))
    GUI = !GUI;

  if (_input._default.getKey(SDLK_SPACE))
    {
      effect->resetFrame();
    }

  return true;
}


bool		GameEngine::update()
{
  static int	i = 0;
  static float frame = 0.0f;

  if (getEvent() == false)
    return false;
  _videoContext->updateContext(_clock, _input);
  camera.update(_clock, _input);
  camera.lockShader(_shader);
  ++i;
  effect->update(_clock, _input, camera);
  std::stringstream sstrm;
  frame += _clock.getElapsed();
  if (frame >= 1.0f)
    {
      sstrm << i;
      s->setText(sstrm.str());
      s->translate(glm::vec3(-10, 7, 12));
      s->scale(glm::vec3(1.5, 1.5, 1.5));
      sstrm.str("");
      i = 0;
      frame = 0.0f;
    }
  bomb->update(_clock, _input);
  for (auto it = _board->getPlayers().begin(); it != _board->getPlayers().end(); it++)
    {
      glm::vec3 save = (*it)->getGameObj()->getPosition();
      (*it)->getGameObj()->update(_clock, _input, camera);
      glm::vec3 p = (*it)->getGameObj()->getPosition();
      if (_board->collideAround((*it), p.x, p.z))
	(*it)->getGameObj()->setPosition(save);
      else
      (*it)->setPos(LOGICAL_POSITION(p.x, p.z));
      if (static_cast<Character *>((*it)->getGameObj())->_bombing)
	(*it)->triggerOneBomb();
    }
  return true;
}

void		GameEngine::draw()
{
  camera.lockShader(_shader);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  sk->draw(_shader, _clock);
  ground->draw(_shader, _clock);
  for (auto it = _board->getFullBoard().begin(); it != _board->getFullBoard().end(); it++)
    for (auto itk = (*it).begin(); itk != (*it).end(); itk++)
    	(*itk)->getGameObj()->draw(_shader, _clock);
  effect->draw(_shader, _clock);
  if (GUI)
    {
      menuCam.lockShader(_shader);
       bomb->draw(_shader, _clock);
      bombChooser->draw(_shader, _clock);
      s->draw(_shader, _clock);
      menu->draw(_shader, _clock);

    }
  _videoContext->flush();
}

void		GameEngine::setVideoContext(VideoContext* const videoContext)
{
  _videoContext = videoContext;
}

void		GameEngine::setClock(gdl::Clock const& clock)
{
  _clock = clock;
}

void		GameEngine::setInput(Binput const& input)
{
  _input = input;
}

void		GameEngine::setShader(gdl::BasicShader const& shader)
{
  _shader = shader;
}

VideoContext*	GameEngine::getVideoContext() const
{
  return _videoContext;
}

gdl::Clock	GameEngine::getClock() const
{
  return _clock;
}

Binput	GameEngine::getInput() const
{
  return _input;
}

gdl::BasicShader	GameEngine::getShader() const
{
  return _shader;
}


GameEngine::~GameEngine()
{
  for (size_t i = 0; i < _objects.size(); ++i)
    delete _objects[i];
}
