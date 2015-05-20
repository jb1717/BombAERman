//
// GameEngine.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:23:57 2015 Jamais
// Last update Wed May 20 21:44:23 2015 Jamais
//

#include	"GameEngine.hh"
#include	"Cube.hh"
#include	"Camera.hh"
#include	"BasicBomb.hh"

Camera		camera;
AGameModel	*perso;
AGameObject	*skybox;
//AGameObject	*bomb;
BasicBomb	*bomb;

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
  gdl::Texture	*texture  = new gdl::Texture();
  gdl::Texture	*lava1 = new gdl::Texture();
  gdl::Texture	*metal = new gdl::Texture();

  int	y;
  int	x;
  int	i = 0;

  texture->load("./assets/Textures/crate.tga");
  lava1->load("./assets/Textures/DangerousCrate.tga");
  // metal->load("./assets/Textures/floor1.tga");
  metal->load("./assets/Textures/paves1.tga");
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
	      if (abs(x + y)  % 3 == 0)
		cell->setTexture(*lava1);
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
  // perso = new AGameModel(glm::vec3(0.0f, 5.0f, 0.0f), "./assets/Models/PumpkinBomb2.fbx");
  //perso = new AGameModel(glm::vec3(0.0f, 5.0f, 0.0f), "~/assets/Models/uh60.obj");
  gdl::Texture	*skyTexture = new gdl::Texture;

  skyTexture->load("./assets/Textures/Skybox.tga");
  perso = new AGameModel(glm::vec3(0.0f, -0.5f, 0.0f), "./assets/Models/marvin.fbx");
  //  perso->scale(glm::vec3(0.02f, 0.02f, 0.02f));
  perso->scale(glm::vec3(0.002f, 0.002f, 0.002f));

  perso->setCurrentAnim(0);
  _objects.push_back(perso);

  skybox = new Cube(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(1000, 1000, 1000));
  skybox->setTexture(*skyTexture);
  skybox->initialize();
  //  _objects.push_back(skybox);
  //  bomb = new BasicBomb();
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

  glm::mat4 projection;
  glm::mat4 transformation;

  projection = glm::perspective(60.0f,
				static_cast<float>(_videoContext->getScreenWidth()) /
				static_cast<float>(_videoContext->getScreenHeight()),
				0.0001f,10000.0f);

  transformation = glm::lookAt(glm::vec3(0, 10, -30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  camera.setTransformationMatrix(transformation);
  camera.setProjectionMatrix(projection);

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
  if (_input.getKey(SDL_BUTTON_LEFT))
    camera.rotate(glm::vec3(0, 1, 0), static_cast<float>(_input.getMouseDelta().x));
  if (_input.getKey(SDLK_KP_PLUS))
    camera.rotate(glm::vec3(-1, 0, 0), 0.10f);
  if (_input.getKey(SDLK_KP_MINUS))
    camera.rotate(glm::vec3(1, 0, 0), 0.10f);
  if (_input.getKey(SDLK_z))
    perso->translate(glm::vec3(0, 0, 1));
  if (_input.getKey(SDLK_s))
    perso->translate(glm::vec3(0, 0, -1));
  if (_input.getKey(SDLK_a))
    perso->translate(glm::vec3(1, 0, 0));
  if (_input.getKey(SDLK_e))
    perso->translate(glm::vec3(-1, 0, 0));
  if (_input.getKey(SDLK_SPACE))
    {
      glm::vec3 p;

      bomb = new BasicBomb();
      bomb->setTimer(2.0);
      //      static_cast<BasicBomb *>(bomb)->setTimer(2.0);
      p = perso->getPosition();
      p.y = 0.5;
      bomb->translate(p);
      _objects.push_back(bomb);
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
  // if (static_cast<BasicBomb *>(bomb)->getTimer() <= 0.0)
  //   {
  //     for (std::vector<AGameObject*>::iterator i = _objects.begin(); *i != bomb; i++)
  // 	_objects.erase(i);
  //   }
  return true;
}

void		GameEngine::draw()
{
  GLint OldCullFaceMode;
  glGetIntegerv(GL_CULL_FACE_MODE, &OldCullFaceMode);
  GLint OldDepthFuncMode;
  glGetIntegerv(GL_DEPTH_FUNC, &OldDepthFuncMode);

  glCullFace(GL_FRONT);
  glDepthFunc(GL_LEQUAL);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  glDisable(GL_DEPTH_TEST);
  glDepthMask(GL_FALSE);
  glEnable(GL_TEXTURE_CUBE_MAP_ARB);
  glDepthFunc(GL_EQUAL);
  skybox->draw(_shader, _clock);
  glDepthMask(GL_TRUE);
  glEnable(GL_DEPTH_TEST);

  glCullFace(OldCullFaceMode);
  glDepthFunc(OldDepthFuncMode);

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


  // if (_input.getKey(SDLK_RIGHT))
  //   {
  //     camera.rotate(glm::vec3(0, 1, 0), 1.0f);
  //     //      camera.setTarget(camera.getTarget() + glm::vec3(-10.0f, 0, 0));
  //   }
  // if (_input.getKey(SDLK_LEFT))
  //   {
  //     camera.rotate(glm::vec3(0, 1, 0), -1.0f);
  //     //      camera.setTarget(camera.getTarget() + glm::vec3(10.0f, 0, 0));
  //   }
  // if (_input.getKey(SDLK_DOWN))
  //   {
  //     camera.rotate(glm::vec3(1, 0, 0), 0.10f);
  //   }
  // if (_input.getKey(SDLK_UP))
  //   {
  //     camera.rotate(glm::vec3(1, 0, 0), -0.10f);
  //   }
  // if (_input.getKey(SDLK_z))
  //   {
  //     camera.translate(glm::vec3(0, 0, -1.0f));
  //   }
  // if (_input.getKey(SDLK_a))
  //   {
  //     camera.translate(glm::vec3(1.0f, 1.0f, 0));
  //   }
  // if (_input.getKey(SDLK_a))
  //   {
  //     camera.translate(glm::vec3(-1.0f, -1.0f, 0));
  //   }
  // if (_input.getKey(SDLK_s))
  //   {
  //     camera.translate(glm::vec3(0, 0, 1.0f));
  //   }
  // if (_input.getKey(SDLK_MINUS))
  //   {
  //     camera.zoom(glm::vec3(1.01f, 1.0f, 1.01f));
  //   }
  // if (_input.getKey(SDLK_MINUS))
  //   {
  //     camera.zoom(glm::vec3(0.99f, 0.99f, 0.99f));
  //   }
  // if (_input.getKey(SDL_BUTTON_LEFT))
  //   {
  //     camera.setTarget(camera.getTarget() + glm::vec3(-1 * _input.getMouseDelta().x, -1 * _input.getMouseDelta().y, _input.getMouseDelta().y));
  //     camera.setTransformationMatrix(glm::lookAt(camera.getPosition(), camera.getTarget(), camera.getFocus()));
  //   }
  // if (_input.getKey(SDL_MOUSEWHEEL))
  //   {
  //     std::cout << "mouseWheel ! " << _input.getMouseWheel().x << std::endl;
  //     if (_input.getMouseWheel().y > 0)
  // 	camera.setTransformationMatrix(glm::scale(camera.getTransformationMatrix(), glm::vec3(1.01f, 1.01f, 1.01f)));
  //   }
