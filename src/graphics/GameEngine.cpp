//
// GameEngine.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:23:57 2015 Jamais
// Last update Sun Jun  7 19:34:00 2015 Jamais
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

#include <unistd.h>


/**/
Camera		camera;
Camera		menuCam;
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

AGameObject	*bomb;
Character	*hero;
gdl::Texture	*texFloor;
gdl::Texture	*texCrate;
gdl::Texture	*texWall;
gdl::Texture*	ex1;
gdl::Texture*	ex2;
gdl::Texture*	ex3;
gdl::Texture*	texMenu;

bool		GUI = true;

AFX*	effect;
GraphicString*	s;
GraphicString*	s2;
AGameObject *falling;
AGameObject *sol;
Geometric *choice;
Geometric* button;

GameEngine::GameEngine() : Game()
{
  _videoContext = VideoContext::instanciate();
  texFloor = new gdl::Texture();
  texFloor->load("./assets/themes/default/default.floor.tga", true);
  texCrate = new gdl::Texture();
  texCrate->load("./assets/themes/default/default.crate.tga", true);
  texWall = new gdl::Texture();
  texWall->load("./assets/themes/default/default.wall.tga", true);
  texMenu = new gdl::Texture();
  texMenu->load("./assets/themes/default/default.menu.tga");
  ex1 = new gdl::Texture();
  ex2 = new gdl::Texture();
  ex3 = new gdl::Texture();
  ex1->load("./assets/Textures/explosions1.tga");
  ex2->load("./assets/Textures/explosions2.tga");
  ex3->load("./assets/Textures/explosions3.tga");
  hero = new Character(glm::vec3(0.0f, 0.0f, 0.0f), MAIN_CHARACTER);
  hero->scale(glm::vec3(0.002f, 0.002f, 0.002f));
  hero->setCurrentAnim(0);
  bomb = new BasicBomb();
   sol = new Cube();
   sol->setTexture(*texFloor);
   sol->scale(glm::vec3(10, 1000, 10));
   sol->translate(glm::vec3(4.5, -499.5, 4.5));
   sol->initialize();
  // bomb = new Cube();
  // bomb->setTexture(*texFloor);
  // bomb->initialize();
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
  /**/
  menuCam.setPosition(glm::vec3(0, 0, -1));
  menuCam.refreshPosition();
  /**/
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_FLAT);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
  _shader.bind();
  _shader.setUniform("view", camera.getTransformationMatrix());
  _shader.setUniform("projection", camera.getProjectionMatrix());

  sk = new Skybox;
  // falling = new Cube(glm::vec3(5, 10, 5));
  // falling->setTexture(*texFloor);
  falling = new Character(glm::vec3(3 ,10, 3));
  falling->scale(glm::vec3(0.002, 0.002, 0.002));
  reinterpret_cast<Character*>(falling)->load("./assets/Models/marvin.fbx");
  //  falling->initialize();

  effect = new AFX();
  factory = GeometryFactory::instanciate();

  // choice = new Cube();
  choice = new Geometric();
  choice->setGeometry(factory->getGeometry(GeometryFactory::VERTICAL_PLANE));
  choice->setTexture(*texMenu);
  choice->scale(glm::vec3(0.5, 0.5, 0.5));

  // choice->translate(glm::vec3(0.25, 0, 0));
  choice->initialize();

  gdl::Texture *GuiBomb = new gdl::Texture;
  std::cout << GuiBomb->load("./assets/themes/default/default.GUIBomb.tga") << std::endl;
  button = new Geometric();
  button->setGeometry(factory->getGeometry(GeometryFactory::PLANE));
  button->setTexture(*GuiBomb);
  button->scale(glm::vec3(0.40, 0.50, 0.40));
  button->setPosition(glm::vec3(-0.60, -0.30, 0.0));
  button->initialize();
  Geometric *g = new Geometric();
  g->setGeometry(factory->getGeometry(GeometryFactory::PLANE));
  g->setTexture(*ex1);
  g->rotate(glm::vec3(1, 0, 0), 90);
  g->scale(glm::vec3(1.5f, 1.5f, 1.5f));
  effect->push_back(g);

  g = new Geometric();
  g->setGeometry(factory->getGeometry(GeometryFactory::PLANE));
  g->setTexture(*ex1);
  g->rotate(glm::vec3(1, 0, 0), 90);
  g->scale(glm::vec3(1.75f, 1.75f, 1.75f));
  effect->push_back(g);
  g = new Geometric();
  g->setGeometry(factory->getGeometry(GeometryFactory::PLANE));
  g->setTexture(*ex1);

  g->rotate(glm::vec3(1, 0, 0), 90);
  g->scale(glm::vec3(2.0f, 2.0f, 2.0f));
  effect->push_back(g);

  effect->initialize();
  effect->translate(glm::vec3(5, 1, 5));
  effect->rotate(glm::vec3(1, 0, 0), 90);

  s2 = new GraphicString("AIOH");
  s2->render(*factory);
  choice = (*s2)[0];
  gdl::Texture *kio = new gdl::Texture;
  kio->load("./assets/fonts/B.tga");
  choice->setTexture(*kio);
  choice->initialize();
  s2->initialize();
  s = new GraphicString("BOMBERMAN 3D");
  s2->translate(glm::vec3(0, 0, 0));
  s2->scale(glm::vec3(150, 150, 150));
  //g = new Geometric();
  //  g->setGeometry(factory->getGeometry(GeometryFactory::PLANE));
  //  gdl::Texture *l = new gdl::Texture();
  //  l->load("./assets/fonts/A.tga");
  // g->setTexture(*l);
  // s->push_back(g);
  s->render(*factory);
  std::string d(" BONJOUR AND YO()");
  *s = d;
  //  s->translate(glm::vec3(5, 2, 5));
  s->initialize();
  s->scale(glm::vec3(0.10, 0.10, 0.10));
  // s->setPosition(camera.getPosition());
  //bomb->translate(glm::vec3(5, 5, 5));
  bomb->setPosition(button->getPosition());
  bomb->translate(glm::vec3(0, -0.10, 0));
  bomb->scale(glm::vec3(0.20, 0.20, 0.20));
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
  if (_input.getKey(SDLK_f))
    {
      GUI = !GUI;
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
  s->update(_clock, _input);
  s2->update(_clock, _input);
  // s->setPosition(camera.getPosition());
  // s->translate(glm::vec3(cos(camera.getRotation().y), 0, sin(camera.getRotation().y)));
  bool	collide = false;
  glm::vec3 p;
  AGameObject *player = _board->getPlayers().front()->getGameObj();

  p = player->getPosition();
  for (auto it = _board->getPlayers().begin(); it != _board->getPlayers().end(); it++)
    {
      (*it)->getGameObj()->update(_clock, _input, camera);
    }
  for (auto it = _board->getFullBoard().begin(); it != _board->getFullBoard().end(); it++)
    {
      int i = 0;
      for (auto itk = (*it).begin(); itk != (*it).end(); itk++)
	{
	  (*itk)->getGameObj()->update(_clock, _input);
	  if (i == 0 && player->collide(*(*itk)->getGameObj()))
	    {
	      if ((*itk)->getGameObj()->getPosition().y >= 1.0)
		collide = true;
	    }
	  ++i;
	}
    }
  if (collide == true)
    player->setPosition(p);

  effect->update(_clock, _input, camera);
  return true;
}

void		GameEngine::draw()
{
  _shader.setUniform("view", camera.getTransformationMatrix());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  sk->draw(_shader, _clock);
  sol->draw(_shader, _clock);
  int x = 0;
  for (auto it = _board->getFullBoard().begin(); it != _board->getFullBoard().end(); it++)
    {
      for (auto itk = (*it).begin(); itk != (*it).end(); itk++)
	{
	  (*itk)->getGameObj()->draw(_shader, _clock);
	  ++x;
	}
    }
    effect->translate(glm::vec3(0, 0, 1));
  effect->draw(_shader, _clock);
  effect->translate(glm::vec3(0, 0, -1));
  effect->draw(_shader, _clock);
  // s2->draw(_shader, _clock);
  //     falling->draw(_shader, _clock);
  //     s->draw(_shader, _clock);

  if (GUI)
    {
      _shader.setUniform("view", menuCam.getTransformationMatrix());
      _shader.setUniform("projection", menuCam.getProjectionMatrix());
      choice->draw(_shader, _clock);
      bomb->draw(_shader, _clock);
      s2->draw(_shader, _clock);
      // falling->draw(_shader, _clock);
      s->draw(_shader, _clock);
      button->draw(_shader, _clock);
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
