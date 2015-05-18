//
// GameEngine.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:23:57 2015 Jamais
// Last update Mon May 18 12:28:04 2015 Jamais
//

#include	"GameEngine.hh"
#include	"Cube.hh"
#include	"Camera.hh"

Camera		camera;
AGameModel	*perso;

GameEngine::GameEngine() : Game()
{
  _videoContext = new VideoContext(1280, 960, "Afghanistan : 1994 ...");
}

bool		GameEngine::createMap(std::string const& confFilePath)
{
  std::ifstream	file;
  std::string	s;
  // int	h = 100;
  // int	w = 100;
  gdl::Texture *texture  = new gdl::Texture();
  gdl::Texture *lava1 = new gdl::Texture();
  gdl::Texture *metal = new gdl::Texture();
  int	y;
  int	x;
  int	i = 0;

  texture->load("./assets/Textures/crate.tga");
  lava1->load("./assets/Textures/lava1.tga");
  metal->load("./assets/Textures/floor1.tga");
  file.open(confFilePath.c_str());
  if (!file.is_open())
    return false;
  getline(file, s, '\n');
  y = -1 * std::atoi(s.c_str()) / 2;
  while (getline(file, s, '\n'))
    {
      x = -1 * (s.size() / 2);
      i = 0;
      while (s[i])
	{
	  AGameObject	*cell;
	  cell = new Cube(glm::vec3(x, -1, y));
	  cell->setTexture(*metal);
	  cell->initialize();
	  _objects.push_back(cell);

	  if (s[i] != ' ')
	    {
	      cell = new Cube(glm::vec3(x, 0, y));
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

  glm::mat4 projection;
  glm::mat4 transformation;

  projection = glm::perspective(60.0f,
				static_cast<float>(_videoContext->getScreenWidth()) /
				static_cast<float>(_videoContext->getScreenHeight()),
				0.1f,100.0f);

  transformation = glm::lookAt(glm::vec3(0, 10, -30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  camera.setTransformationMatrix(transformation);
  camera.setProjectionMatrix(projection);

  _shader.bind();
  _shader.setUniform("view", camera.getTransformationMatrix());
  _shader.setUniform("projection", camera.getProjectionMatrix());

  perso = new AGameModel(glm::vec3(0.0f, -0.5f, 0.0f), "./assets/Models/marvin.fbx");
  perso->scale(glm::vec3(0.002f, 0.002f, 0.002f));
  _objects.push_back(perso);
  createMap("./conf/map.conf");
  return true;
}

bool		GameEngine::getEvent()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  if (_input.getKey(SDLK_RIGHT))
    {
      camera.rotate(glm::vec3(0, 1, 0), 1.0f);
      //      camera.setTarget(camera.getTarget() + glm::vec3(-10.0f, 0, 0));
    }
  if (_input.getKey(SDLK_LEFT))
    {
      camera.rotate(glm::vec3(0, 1, 0), -1.0f);
      //      camera.setTarget(camera.getTarget() + glm::vec3(10.0f, 0, 0));
    }
  if (_input.getKey(SDLK_DOWN))
    {
      camera.rotate(glm::vec3(1, 0, 0), 0.10f);
    }
  if (_input.getKey(SDLK_UP))
    {
      camera.rotate(glm::vec3(1, 0, 0), -0.10f);
    }
  if (_input.getKey(SDLK_z))
    {
      camera.translate(glm::vec3(0, 0, -1.0f));
    }
  if (_input.getKey(SDLK_a))
    {
      camera.translate(glm::vec3(1.0f, 1.0f, 0));
    }
  if (_input.getKey(SDLK_a))
    {
      camera.translate(glm::vec3(-1.0f, -1.0f, 0));
    }
  if (_input.getKey(SDLK_s))
    {
      camera.translate(glm::vec3(0, 0, 1.0f));
    }
  if (_input.getKey(SDLK_MINUS))
    {
      camera.zoom(glm::vec3(1.01f, 1.0f, 1.01f));
    }
  if (_input.getKey(SDLK_MINUS))
    {
      camera.zoom(glm::vec3(0.99f, 0.99f, 0.99f));
    }
  if (_input.getKey(SDL_BUTTON_LEFT))
    {
      camera.setTarget(camera.getTarget() + glm::vec3(-1 * _input.getMouseDelta().x, -1 * _input.getMouseDelta().y, _input.getMouseDelta().y));
      camera.setTransformationMatrix(glm::lookAt(camera.getPosition(), camera.getTarget(), camera.getFocus()));
    }
  if (_input.getKey(SDL_MOUSEWHEEL))
    {
      std::cout << "mouseWheel ! " << _input.getMouseWheel().x << std::endl;
      if (_input.getMouseWheel().y > 0)
	camera.setTransformationMatrix(glm::scale(camera.getTransformationMatrix(), glm::vec3(1.01f, 1.01f, 1.01f)));
    }
  return true;
}

bool		GameEngine::update()
{
  if (getEvent() == false)
    return false;
  _videoContext->updateContext(_clock, _input);
  //  camera.update();
  _shader.setUniform("view", camera.getTransformationMatrix());
  _shader.setUniform("projection", camera.getProjectionMatrix());
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->update(_clock, _input);
  return true;
}

void		GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //  glDisable(GL_DEPTH_TEST);
  //  gdl::Geometry	background;

  // background.setColor(1, 1, 1, 1);
  // background.set


  _shader.bind();
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
