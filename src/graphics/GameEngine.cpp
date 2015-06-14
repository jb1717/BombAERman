//
// GameEngine.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:23:57 2015 Jamais
// Last update Sun Jun 14 17:35:32 2015 Jamais
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
#include	"Bonus.hh"

#include	<unistd.h>

/**/
Camera		camera;
Camera		menuCam;

Skybox		*sk;
AGameModel*	bomb;
gdl::Texture	*texFloor;
gdl::Texture	*texCrate;
gdl::Texture	*texWall;
gdl::Texture	*texCrate2;
gdl::Texture	*texCrate3;
gdl::Texture*	texMenu;

bool		GUI = true;
GraphicString*	s;
GraphicString*	playerIndic;
Geometric* bombChooser;
Geometric* menu;
ParticleSystem*	psystem;

AFX*			effect;

Geometric*		ground;
Bonus*			bn;
AGameModel*	test;
#define		LIMIT(x, limit)	(((x) < 0) ? 0 : ((x) > (limit)  ? (limit) : (x)))

GameEngine::GameEngine() : Game()
{
  _videoContext = VideoContext::instanciate();
  auto		asset = AssetManager::instance();
  texCrate = (*THEME((*THEME_HANDLER(asset["themes"]))["default"]))["crate"];
  texCrate2 = (*THEME((*THEME_HANDLER(asset["themes"]))["default"]))["crate2"];
  texCrate3 = (*THEME((*THEME_HANDLER(asset["themes"]))["default"]))["crate3"];
  texWall = (*THEME((*THEME_HANDLER(asset["themes"]))["default"]))["wall"];
  texMenu = (*THEME((*THEME_HANDLER(asset["themes"]))["GUI"]))["menu"];
  //bomb = new BasicBomb();
  bomb = &((*MODEL_HANDLER(asset["models"]))["PumpkinBomb.fbx"]);
  bomb->scale(glm::vec3(0.002, 0.002, 0.002));

  bn = new Bonus(glm::vec3(0, 0,  0));
  bn->load("./assets/models/bonusPower.fbx");
  bn->setPosition(glm::vec3(0, 5, 0));
  bn->setColor(glm::vec4(1.0f, 0.8f, 0.8f, 1.0f));
  // bn->load("./assets/models/bonusPower.fbx");
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

  ground = new Geometric(glm::vec3(0, 0.f, 0));
  ground->setGeometry(factory->getGeometry(GeometryFactory::HORIZONTAL_PLANE));
  ground->setTexture(*(*THEME((*THEME_HANDLER(asset["themes"]))["default"]))["ground"]);
  ground->scale(glm::vec3(_board->getHeight()  -1.0f, _board->getWidth(), _board->getWidth() -1.0f));
  ground->translate(glm::vec3(0, 0, 0));

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

  return true;
}

bool		GameEngine::update()
{
  std::lock_guard<std::mutex> lock(_mutex);
  static int	i = 0;
  static float frame = 0.0f;

  if (getEvent() == false)
    return false;
  _videoContext->updateContext(_clock, _input);
  camera.update(_clock, _input);
  camera.lockShader(_shader);
  ++i;
  //  effect->update(_clock, _input, camera);
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
  bn->rotate(glm::vec3(0, 1, 0), 1);
  for (auto it = _board->getPlayers().begin(); it != _board->getPlayers().end(); it++)
    {
      if ((*it)->getGameObj() && ((*it)->getId() == 1 || (*it)->getId() == 2))
	{
	  glm::vec3 save = (*it)->getGameObj()->getPosition();
	  (*it)->getGameObj()->update(_clock, _input, camera, (*it)->getId());
	  glm::vec3 p = (*it)->getGameObj()->getPosition();
	  if (_board->collideAround((*it), p.x, p.z))
	    (*it)->getGameObj()->setPosition(save);
	  else
	    {
	      _board->moveEntity((((save.x) - (((_board)->getWidth()) / (2))) < 0) ?	(((save.x) - ((_board)->getWidth()) / (2)) * (-1)) : ((save.x) - ((_board)->getWidth()) / (2)),
	      		 (((save.z) - ((_board)->getHeight()) / (2)) < 0) ? (((save.z) - ((_board)->getHeight()) / (2)) * (-1)) : (((save.z) - ((_board)->getHeight()) / (2))),
	      		 (((p.x) - (((_board)->getWidth()) / (2))) < 0) ? (((p.x) - ((_board)->getWidth()) / (2)) * (-1)) : ((p.x) - ((_board)->getWidth()) / (2)),
	      		 (((p.z) - ((_board)->getHeight()) / (2)) < 0) ? (((p.z) - ((_board)->getHeight()) / (2)) * (-1)) : (((p.z) - ((_board)->getHeight()) / (2))),
	      		 (*it)->getId());
	      // (*it)->setPos(LOGICAL_POSITION(p.x, p.z));
	    }
	  if ((*it) && (*it)->getGameObj() && reinterpret_cast<Character *>((*it)->getGameObj())->_bombing)
	    (*it)->triggerOneBomb();
	  (*it)->update_bombs(_clock, _input);
	}
    }
  return true;
}

void		GameEngine::draw()
{
  std::vector <AGameObject*>	explosions;

  camera.lockShader(_shader, true);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  sk->draw(_shader, _clock);
  ground->draw(_shader, _clock);
  _mutex.lock();
  for (auto it = _board->getFullBoard().begin(); it != _board->getFullBoard().end(); it++)
    {
      for (auto itk = (*it).begin(); itk != (*it).end(); itk++)
	if ((*itk) && (*itk)->getGameObj())
	  {
	    if ((*itk)->getId() == -4)
	      {
		static_cast<AFX *>((*itk)->getGameObj())->update(_clock, _input, camera);
		explosions.push_back((*itk)->getGameObj());
	      }
	    else
	      (*itk)->getGameObj()->draw(_shader, _clock);
	  }
    }
  for (auto it = explosions.begin(); it != explosions.end(); it++)
    (*it)->draw(_shader, _clock);
  _mutex.unlock();
  if (GUI)
    {
      menuCam.lockShader(_shader);
      bomb->draw(_shader, _clock);
      bombChooser->draw(_shader, _clock);
      s->draw(_shader, _clock);
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
