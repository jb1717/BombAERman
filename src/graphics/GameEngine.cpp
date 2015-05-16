//
// GameEngine.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:23:57 2015 Jamais
// Last update Sun May 17 00:51:15 2015 Jamais
//

#include	"GameEngine.hh"
#include	"Cube.hh"

GameEngine::GameEngine()
{}

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

  AGameObject *cube = new Cube();

  cube->setTexture(*texture);
  cube->initialize();
  _objects.push_back(cube);
  AGameObject *slab = new Cube(glm::vec3(2, 1, 2));
  slab->setTexture(*texture);
  slab->initialize();
  _objects.push_back(slab);
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
}
