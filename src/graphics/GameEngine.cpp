//
// GameEngine.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:23:57 2015 Jamais
// Last update Sat Jun  6 01:43:22 2015 Jamais
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

#include <unistd.h>

Camera		camera;
AGameModel	*perso;
bool		test = false;
bool		fallen = false;
std::vector<AGameObject *> _skyfall;
Cube		*c;
AGameObject	*Floor;
Skybox		*sk;
GeometryFactory *factory;
std::vector<AObj *> objs;
VideoContext	*V;
AGameObject *	lolilol;

BasicBomb	*bomb;
Character	*hero;
gdl::Texture	*texFloor;
gdl::Texture	*texCrate;
gdl::Texture	*texWall;


GameEngine::GameEngine() : Game()
{
  _videoContext = VideoContext::instanciate();
  texFloor = new gdl::Texture();
  texFloor->load("./assets/themes/default/default.floor.tga");
  texCrate = new gdl::Texture();
  texCrate->load("./assets/themes/default/default.crate.tga");
  texWall = new gdl::Texture();
  texWall->load("./assets/themes/default/default.wall.tga");
  hero = new Character(glm::vec3(0.0f, 0.0f, 0.0f), MAIN_CHARACTER);
  hero->scale(glm::vec3(0.002f, 0.002f, 0.002f));
  hero->setCurrentAnim(0);
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

bool		GameEngine::initialize()
{
  if (!camera.setupCamera(*_videoContext))
      return false;

  if (!_shader.load(FRAGMENT_SHADER, GL_FRAGMENT_SHADER)
      || !_shader.load(VERTEX_SHADER, GL_VERTEX_SHADER)
      || !_shader.build())
    return false;

  glEnable(GL_SCISSOR_TEST);
  camera.refreshPosition();

  _shader.bind();
  _shader.setUniform("view", camera.getTransformationMatrix());
  _shader.setUniform("projection", camera.getProjectionMatrix());

  sk = new Skybox;
  return true;
}

bool		GameEngine::getEvent()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;

  if (_input.getMouseWheel().y)
    camera.zoom( 0.05 * _input.getMouseWheel().y);

  if (_input.getKey(SDLK_SPACE) && test == false)
    {
      test = true;
    }

  return true;
}


bool		GameEngine::update()
{
  if (getEvent() == false)
    return false;

  _videoContext->updateContext(_clock, _input);
  camera.update(_clock, _input);

  _shader.setUniform("view", camera.getTransformationMatrix());
  _shader.setUniform("projection", camera.getProjectionMatrix());

  for (auto it = _board->getFullBoard().begin(); it != _board->getFullBoard().end(); it++)
    {
      for (auto itk = (*it).begin(); itk != (*it).end(); itk++)
	{
	  (*itk)->getGameObj()->update(_clock, _input);
	}
    }
  for (auto it = _board->getPlayers().begin(); it != _board->getPlayers().end(); it++)
    {
      (*it)->getGameObj()->update(_clock, _input, camera);
    }

  return true;
}

void		GameEngine::draw()
{
  _shader.setUniform("view", camera.getTransformationMatrix());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  sk->draw(_shader, _clock);

  int x = 0;
  for (auto it = _board->getFullBoard().begin(); it != _board->getFullBoard().end(); it++)
    {
      for (auto itk = (*it).begin(); itk != (*it).end(); itk++)
	{
	  (*itk)->getGameObj()->draw(_shader, _clock);
	  ++x;
	}
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

void		GameEngine::setInput(gdl::Input const& input)
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

gdl::Input	GameEngine::getInput() const
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
