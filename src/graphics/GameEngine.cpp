//
// GameEngine.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:23:57 2015 Jamais
// Last update Fri May 22 02:36:00 2015 Jamais
//

#include	"GameEngine.hh"
#include	"Cube.hh"
#include	"Camera.hh"
#include	"BasicBomb.hh"
#include	"Character.hh"

Camera		camera;
AGameModel	*perso;
AGameObject	*skybox;
//BasicBomb	*bomb;
Cube		*bomb;
bool		test = false;
AGameObject	*ref;
float		timer;

GameEngine::GameEngine() : Game()
{
  _videoContext = new VideoContext(1280, 960, "Afghanistan : 1994 ...");
  _videoContext = new VideoContext(1920, 1280, "Afghanistan : 1994 ...");
}

bool		GameEngine::createMap(std::string const& confFilePath)
{
  std::ifstream	file;
  std::string	s;
  gdl::Texture	*texture  = new gdl::Texture();
  gdl::Texture	*secretCrate = new gdl::Texture();
  gdl::Texture	*floor = new gdl::Texture();
  gdl::Texture	*wall = new gdl::Texture();

  int	y;
  int	ys;
  int	x;
  int	i = 0;

  texture->load("./assets/Textures/crate.tga");
  secretCrate->load("./assets/Textures/DangerousCrate.tga");
  wall->load("./assets/Textures/wall1.tga");
  floor->load("./assets/Textures/paves1.tga");
  file.open(confFilePath.c_str());
  if (!file.is_open())
    return false;
  getline(file, s, '\n');
  ys = std::atoi(s.c_str()) / 2;
  y = -1 * ys;
  while (getline(file, s, '\n'))
    {
      x = -1 * (s.size() / 2);
      i = 0;
      while (s[i])
	{
	  AGameObject	*cell;
	  cell = new Cube(glm::vec3(x, -1, y));
	  cell->setTexture(*floor);
	  cell->initialize();
	  _objects.push_back(cell);

	  if (y == -1 * ys || y == ys || i == 0 || i == static_cast<int>(s.size()))
	    {
	      cell = new Cube(glm::vec3(x, 0, y));
	      cell->setTexture(*wall);
	      cell->initialize();
	      _objects.push_back(cell);
	    }
	  else if (s[i] != ' ')
	    {
	      cell = new Cube(glm::vec3(x, 0, y));
	      if (abs(x + y)  % 3 == 0)
		cell->setTexture(*secretCrate);
	      else
		cell->setTexture(*texture);
	      cell->initialize();
	      _objects.push_back(cell);
	    }
	  ++x;
	  ++i;
	}
      ++y;
    }
    return true;
}

bool		GameEngine::setupGame(std::string const& filePath)
{
  gdl::Texture	*skyTexture = new gdl::Texture;

  //  perso = new AGameModel(glm::vec3(10.0f, -0.5f, 0.0f), "./assets/Models/marvin.fbx");
  //  perso = new Character(glm::vec3(10.0f, -0.5f, 0.0f), "./assets/Models/marvin.fbx");
  //  perso = new Character(glm::vec3(10.0f, 0.0f, 0.0f), "./assets/Models/test.fbx");
  perso = new Character(glm::vec3(10.0f, 0.0f, 0.0f), "./assets/Models/pumpkinScaled.fbx");
  perso->scale(glm::vec3(0.5, 0.5, 0.5));
  //  perso->scale(glm::vec3(0.002f, 0.002f, 0.002f));
  perso->setCurrentAnim(0);
  _objects.push_back(perso);

  skyTexture->load("./assets/Textures/Desert1.tga");
  skybox = new Cube(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(1000, 1000, 1000));
  skybox->setTexture(*skyTexture);
  skybox->initialize();

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
  camera.refreshPosition();
  _shader.bind();
  _shader.setUniform("view", camera.getTransformationMatrix());
  _shader.setUniform("projection", camera.getProjectionMatrix());


  return true;
}

bool		GameEngine::getEvent()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;

  if (_input.getMouseWheel().y)
    camera.zoom( 0.05 * _input.getMouseWheel().y);
  perso->update(_clock, _input);
  if (_input.getKey(SDLK_SPACE) && test == false)
    {
      glm::vec3 p;
      gdl::Texture *k = new gdl::Texture;

      k->load("./assets/Textures/DangerousCrate.tga");
      // bomb = new BasicBomb();
      bomb = new Cube();
      bomb->setTexture(*k);
      bomb->initialize();
      // bomb->setTimer(2.0);
      timer = 2.0;
      p = perso->getPosition();
      p.y = 0.5;
      bomb->translate(p);
      _objects.push_back(bomb);
      test = true;
      std::vector<AGameObject *>::iterator i;
      for (i = _objects.begin(); i != _objects.end(); i++)
	{
	  if ((*i)->getPosition().x == p.x && (*i)->getPosition().z == p.z)
	    {
	      ref = *i;

	      break;
	    }
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

  if (bomb && test == true)
    {
      // std::cout << "Bomb (x z) : " << bomb->getPosition().x << "  " << bomb->getPosition().y << "  " << bomb->getPosition().z << std::endl;
      // std::cout << "Ref (x z) : " << ref->getPosition().x << "  " << ref->getPosition().y  << " " << ref->getPosition().z << std::endl;
      if (bomb->collide(*ref) == false)
	{
	  bomb->translate(glm::vec3(0, -0.1f, 0));
	}
    }
  timer -= _clock.getElapsed();
  _shader.setUniform("view", camera.getTransformationMatrix());
  _shader.setUniform("projection", camera.getProjectionMatrix());
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->update(_clock, _input);
  // if (bomb && bomb->getTimer() <= 0.0 && test == true)
  //   {
  //     _objects.pop_back();
  //     test = false;
  //   }
  if (bomb && timer <= 0.0 && test == true)
    {
      _objects.pop_back();
      test = false;
    }
  return true;
}

void		GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  skybox->draw(_shader, _clock);

  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);
  _videoContext->flush();
}

GameEngine::~GameEngine()
{
  for (size_t i = 0; i < _objects.size(); ++i)
    delete _objects[i];
  delete _videoContext;
}
