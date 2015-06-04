//
// GameEngine.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:23:57 2015 Jamais
// Last update Thu Jun  4 20:03:54 2015 Jamais
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

#include <unistd.h>

Camera		camera;
AGameModel	*perso;
BasicBomb	*bomb;
bool		test = false;
bool		fallen = false;
std::vector<AGameObject *> _skyfall;
Cube		*c;
AGameObject	*Floor;
Skybox		*sk;
GeometryFactory *factory;

GameEngine::GameEngine() : Game()
{
  _videoContext = new VideoContext(1920, 1280, "Afghanistan : 1994 ...");
}

AGameObject	*GameEngine::findObject(int x, UNUSED int y, int z)
{
  std::vector<AGameObject*>::iterator i;
  for (i = _objects.begin(); i != _objects.end(); i++)
    {
      if ((*i)->getPosition().x == x && (*i)->getPosition().z == z && (*i)->getPosition().y == 0.5)
	return *i;
      if ((*i)->getPosition().x == x && (*i)->getPosition().z == z && (*i)->getPosition().y == -0.5)
	return *i;
    }
  return NULL;
}

bool		GameEngine::createMap(UNUSED std::string const& confFilePath)
{
  std::ifstream	file;
  std::string	s;
  gdl::Texture	*texture  = new gdl::Texture();
  gdl::Texture	*secretCrate = new gdl::Texture();
  gdl::Texture	*floor = new gdl::Texture();
  gdl::Texture	*wall = new gdl::Texture();

  // int	y;
  // int	ys;
  // int	x;
  // int	i = 0;


  texture->load(CRATE1);
  //  texture->load("./assets/Textures/transparencyTag.tga");
  secretCrate->load(CRATE2);
  wall->load(CRATE1);
  floor->load(FLOOR1);
  // floor->load("~/Pictures/A.tga");
  //  texture->load("./assets/Textures/transparencyTag.tga");
  // srand(time(NULL));
  // file.open(confFilePath.c_str());
  // if (!file.is_open())
  //   return false;
  // getline(file, s, '\n');
  // ys = (int)(std::atoi(s.c_str())) / 2;
  for (int x = -25; x < 25; x++)
    {
      for (int y = -25; y < 25; y++)
	{
	  AGameObject *cell = new Cube(glm::vec3(x, 0, y));

	  cell->setTexture(*floor);
	  cell->initialize();
	  _objects.push_back(cell);

	  if (x == -25 || y == -25 || x == 24 || y == 24)
	    {
	      cell = new Cube(glm::vec3(x, 1, y));
	    }
	}
    }
  Floor = new Cube(glm::vec3(0, -1.2, 0), glm::vec3(0, 0, 0), glm::vec3(49, 2, 49));
  Floor->setTexture(*floor);
  Floor->initialize();
  //  _objects.push_back(Floor);

  ComplexObject *cx = new ComplexObject;
  cx->scale(glm::vec3(0.5, 0.5, 0.5));
  _objects.push_back(cx);

  GraphicString*	gs = new GraphicString("G");
  GeometryFactory	gf;
  gs->render(gf);
  std::cout << std::boolalpha << gs->initialize() << std::endl;;
  //  gs->translate(glm::vec3(0, 5, 0));
  _objects.push_back(gs);
  return true;
}

bool		GameEngine::setupGame(std::string const& filePath)
{
  perso = new Character(glm::vec3(0.0f, 0.0f, 0.0f), "./assets/Models/Bombinette.fbx");
  perso = new Character(glm::vec3(0.0f, 0.0f, 0.0f), "./assets/Models/TestExplosion.fbx");
  perso = new Character(glm::vec3(0.0f, 0.0f, 0.0f), MAIN_CHARACTER);
  perso->scale(glm::vec3(0.002f, 0.002f, 0.002f));
  perso->setCurrentAnim(0);
  _objects.push_back(perso);

  return createMap(filePath);
}

bool		GameEngine::initialize()
{
  if (!_videoContext->init())
    return false;

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
      glm::vec3 p;

      p = perso->getPosition();
      p.y = 0.5;

      bomb = new BasicBomb();
      bomb->setTimer(20.0);
      bomb->translate(p);
      bomb->translate(glm::vec3(0, 0, 0));
      _objects.push_back(bomb);
      test = true;
    }

  return true;
}



bool		GameEngine::Animation()
{
  std::vector<AGameObject *>::iterator i;
  float q;

  for (i = _objects.begin(); i != _objects.end(); i++)
    {
      AGameObject *current = *i;

      if (current->getPosition().y != -0.5 && current->getPosition().y != 0.5)
	{
	  AGameObject *test = findObject(current->getPosition().x, 0, current->getPosition().z);

	  q = float(rand() % 50) * -0.0001;
	  if (!current->collide(*test))
	    current->translate(glm::vec3(0, q, 0));
	}
    }
  return true;
}

bool		GameEngine::update()
{
  if (getEvent() == false)
    return false;

  _videoContext->updateContext(_clock, _input);
  camera.update(_clock, _input);
  perso->update(_clock, _input, camera);
  _shader.setUniform("view", camera.getTransformationMatrix());
  _shader.setUniform("projection", camera.getProjectionMatrix());
  if (_input.getKey(SDLK_h))
    {
      _videoContext->stop();
     sleep(2);
      if (_videoContext->init() == false)
	std::cout << "DOMMAGE" << std::endl;
    }
  if (test == true)
    {
      bomb->update(_clock, _input);
      if (!bomb->collide(*Floor))
  	bomb->translate(glm::vec3(0, -0.01, 0));
    }
  for (size_t i = 0; i < _skyfall.size(); ++i)
    {
      if (_skyfall[i]->collide(*Floor) == false)
	{
	  _skyfall[i]->translate(glm::vec3(0, -0.01, 0));
	  _skyfall[i]->update(_clock, _input);
	}
    }
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->update(_clock, _input);
  if (bomb && bomb->getTimer() <= 0.0 && test == true)
    {
       _objects.pop_back();
       delete bomb;
      test = false;
    }
  return true;
}

void		GameEngine::draw()
{
  _shader.setUniform("view", camera.getTransformationMatrix());
  // glScissor(0, 0, 1920, 1280);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  sk->draw(_shader, _clock);
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);
  //  _videoContext->flush();
  // glScissor(1600, 960, 320, 320);
  // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // glm::mat4 ty(1.0f);
  // // ty = glm::rotate(ty, 90.0f, glm::vec3(1.0, 0.0, 0.0));
  // ty = glm::translate(ty, glm::vec3(0.0, 150, -50.0));
  // ty = glm::scale(ty, glm::vec3(0.1, 0.1, 0.1));
  // _shader.setUniform("view", ty);
  // sk->draw(_shader, _clock);
  // for (size_t i = 0; i < _objects.size(); ++i)
  //   _objects[i]->draw(_shader, _clock);
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
  delete _videoContext;
}
