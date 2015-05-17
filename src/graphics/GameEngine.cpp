//
// GameEngine.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:23:57 2015 Jamais
// Last update Sun May 17 02:49:16 2015 Jamais
//

#include	"GameEngine.hh"
#include	"Cube.hh"

GameEngine::GameEngine() : Game()
{
  _videoContext = new VideoContext(1280, 960, "Afghanistan : 1994 ...");
}

bool		GameEngine::initialize()
{
   if (!_context.start(800, 600, "My bomberman!"))
    return false;

  glEnable(GL_DEPTH_TEST);

  // if (!_shader.load("./shaders/fragmentShader", GL_FRAGMENT_SHADER)
  //     || !_shader.load("./shaders/vertexShader", GL_VERTEX_SHADER)
  //     || !_shader.build())
  //   return false;

  if (!_shader.load(FRAGMENT_SHADER, GL_FRAGMENT_SHADER)
      || !_shader.load(VERTEX_SHADER, GL_VERTEX_SHADER)
      || !_shader.build())
    return false;

  glm::mat4 projection;
  glm::mat4 transformation;

  projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);


  transformation = glm::lookAt(glm::vec3(0, 10, -30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);

  gdl::Texture *texture  = new gdl::Texture();
  texture->load("./assets/Textures/crate.tga");

  gdl::Texture *lava1 = new gdl::Texture();
  lava1->load("./assets/Textures/lava1.tga");

  gdl::Texture *metal = new gdl::Texture();
  metal->load("./assets/Textures/floor1.tga");

  int	h = 200;
  int	w = 100;

  for (int x = -w / 2; x < w / 2; x++)
    {
      for (int y = -h / 2; y < h / 2; y++)
	{
	  AGameObject *floor = new Cube(glm::vec3(x, 0, y));
	  if (x < 0)
	    floor->setTexture(*texture);
	  else if (y < 0)
	    floor->setTexture(*lava1);
	  else
	    floor->setTexture(*metal);
	  floor->initialize();
	  _objects.push_back(floor);
	}
    }
  return true;
}

bool		GameEngine::update()
{

  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;

  _context.updateClock(_clock);
  _context.updateInputs(_input);

  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->update(_clock, _input);
  return true;
}

void		GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _shader.bind();

  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);

  _context.flush();
}

GameEngine::~GameEngine()
{
  for (size_t i = 0; i < _objects.size(); ++i)
    delete _objects[i];
  _context.stop();
  delete _videoContext;
}
