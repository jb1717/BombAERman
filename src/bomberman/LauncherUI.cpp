//
// LauncherUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 22:06:02 2015 TommyStarK
// Last update Fri Jun  5 19:04:00 2015 Jamais
//

#include "UIManager/LauncherUI.hh"

LauncherUI::LauncherUI(int width, int height, const std::string & winName)
  : _width(width), _height(height), _name(winName)
{
  _texturehandler.push_back(std::make_pair("./assets/Textures/Play.tga",
                            new gdl::Texture()));
  _texturehandler.push_back(std::make_pair("./assets/Textures/Settings.tga",
                            new gdl::Texture()));
  _texturehandler.push_back(std::make_pair("./assets/Textures/Quit.tga",
                            new gdl::Texture()));
  this->setName("StartUI");
}

LauncherUI::~LauncherUI()
{


}
void                       LauncherUI::setUpDisplay()
{
  if (!_camera.setupCamera(*_window))
    throw std::runtime_error("(LauncherUI::)setUpDisplay - setup camera failed.");
  if (!_shader.load(FRAGMENT_SHADER, GL_FRAGMENT_SHADER)
      || !_shader.load(VERTEX_SHADER, GL_VERTEX_SHADER)
      || !_shader.build())
    throw std::runtime_error("(LauncherUI::)setUpDisplay - load/build shader failed.");
  _camera.refreshPosition();
  _shader.bind();
  _shader.setUniform("view", _camera.getTransformationMatrix());
  _shader.setUniform("projection", _camera.getProjectionMatrix());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  try {
    for (auto i : _texturehandler) {
      int j = 0;
      std::get<1>(i)->load(std::get<0>(i));
      _items.push_back(new Cube(glm::vec3(j, 0, 0)));
      _items.back()->setTexture(*std::get<1>(i));
      _items.back()->initialize();
      _items.back()->draw(_shader, _clock);
      j -= 2;
    }
  } catch(std::invalid_argument &e) {
    throw std::invalid_argument(e.what());
  }
  _window->flush();
}

void                       LauncherUI::updateContext()
{
  _window->updateContext(_clock, _input);
  _camera.update(_clock, _input);
  _shader.setUniform("view", _camera.getTransformationMatrix());
  _shader.setUniform("projection", _camera.getProjectionMatrix());
  try {
    for (auto i : _items)
      (*i).update(_clock, _input);
  } catch(std::invalid_argument &e) {
    throw std::invalid_argument(e.what());
  }
}

std::string                LauncherUI::getUItoDisplay(int check) const
{
  std::cout << check << std::endl;
  return (!check ? "PlayUI" : (check == 1 ? "SettingsUI" : "Quit"));
}

void                       LauncherUI::launch()
{

  _isRunning = true;
  _window = VideoContext::instanciate();
  // _window = new VideoContext(_width, _height, _name);
  _window->setScreenWidth(_width);
  _window->setScreenHeight(_height);
  // if (!_window->init())
  //   throw std::runtime_error("(LauncherUI::)launch - init VideoContext failed.");
  this->setUpDisplay();
}

stateUI                    LauncherUI::handlerEvent()
{
  _selected = PLAY;
  while (_isRunning)
  {
    this->updateContext();
    if (_input._default.getKey(SDLK_ESCAPE) || _input._default.getInput(SDL_QUIT))
    {
      _isRunning = false;
      break ;
    }
    else if (_input._default.getKey(SDLK_RETURN) || _input._default.getInput(SDLK_RETURN))
      return (std::tuple<bool, std::string>(false, this->getUItoDisplay(_selected)));
    else
    {
      if (_input._default.getInput(SDLK_UP))
        _selected = (!_selected ? QUIT : (_selected - 1));
      else if (_input._default.getInput(SDLK_DOWN))
        _selected = (_selected == QUIT ? PLAY : (_selected + 1));
    }
    this->updateContext();
  }
  return (std::tuple<bool, std::string>(true, this->getName()));
}
