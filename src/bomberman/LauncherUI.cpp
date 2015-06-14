//
// LauncherUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 22:06:02 2015 TommyStarK
// Last update Sun Jun 14 22:50:30 2015 TommyStarK
//

#include "UIManager/LauncherUI.hh"


LauncherUI::LauncherUI(int width, int height, const std::string & winName)
  : _width(width), _height(height), _first(true), _spreading(10),
   _name(winName), _settings(Settings::instance()), _const(new glm::vec3())
{
  _settings.setWidth(_width);
  _settings.setHeight(_height);
  _settings.setWindowName(_name);
  _itemsName.push_back("play");
  _itemsName.push_back("settings");
  _itemsName.push_back("quit");
  _dynamicItems = _itemsName.size();
  _itemsName.push_back("StartBackground");
  _itemsName.push_back("title");
  _itemsName.push_back("bomb");
  _cursor[PLAY] = _spreading + 1.75;
  _cursor[SETTINGS] = 0;
  _cursor[QUIT] = -1 *  _spreading - 1.75;
  this->setName("StartUI");
}


LauncherUI::~LauncherUI()
{

}


void                        LauncherUI::itemFocus()
{
  switch (_behavior) {
    case 1:
      _selected = (!_selected ? QUIT : _selected == 1 ? PLAY : SETTINGS);
      break ;
    case -1:
      _selected = (_selected == 2 ? PLAY : !_selected ? SETTINGS : QUIT);
      break ;
    default:
      break;
  }
  _behavior = 0;
  int cursor = _itemsName.size() - _dynamicItems - 1;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _front[cursor]->setPosition(glm::vec3(_cursor[_selected], -4.4 , 12));
  for (auto i : _front)
    i->draw(_shader, _clock);
  for (auto i : _items)
    i->draw(_shader, _clock);
  _window->flush();
}


void                       LauncherUI::setupDisplay()
{
  if (!_camera.setupCamera(*_window))
    throw std::runtime_error("(LauncherUI::)setUpDisplay - setup camera failed.");
  if (!_shader.load(FRAGMENT_SHADER, GL_FRAGMENT_SHADER)
      || !_shader.load(VERTEX_SHADER, GL_VERTEX_SHADER)
      || !_shader.build())
    throw std::runtime_error("(LauncherUI::)setUpDisplay - load/build shader failed.");
  _camera.setPosition(glm::vec3(0, 0, -20));
  _camera.setZoom(glm::vec3(12, 12, 12));
  _camera.setTarget(*_const);
  _camera.refreshPosition();
  _shader.bind();
  _camera.lockShader(_shader, true);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->setupItemsMenu();
  _window->flush();
}


void                        LauncherUI::setupItemsMenu()
{
  auto asset = AssetManager::instance();
  _factory = GeometryFactory::instanciate();
  _front[0] = new Geometric(glm::vec3(0, 0, 15.1), glm::vec3(0, 0, 0), glm::vec3(40, 24, 1));
  _front[1] = new Geometric(glm::vec3(0, 5, 10), glm::vec3(0, 0, 0), glm::vec3(10, 2, 1));
  _front[2] = new Geometric(glm::vec3(_cursor[PLAY], -4.4, 12), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
  int fixItems = _itemsName.size() - _dynamicItems;
  for (auto i : _front) {
    int n = _itemsName.size() - fixItems;
    i->setGeometry(_factory->getGeometry(GeometryFactory::VERTICAL_PLANE));
    i->setTexture((*(*THEME((*THEME_HANDLER(asset["themes"]))["default"]))[_itemsName[n]]));
    i->initialize();
    i->draw(_shader, _clock);
    --fixItems;
  }
  for (int i = 0; i < _dynamicItems; i++) {
    _items.push_back(new Geometric(glm::vec3(_spreading, -5, 10), glm::vec3(0, 0, 0), glm::vec3(2.5, 1.15, 1.25)));
    _items.back()->setGeometry(_factory->getGeometry(GeometryFactory::VERTICAL_PLANE));
    _items.back()->setTexture((*(*THEME((*THEME_HANDLER(asset["themes"]))["default"]))[_itemsName[i]]));
    _items.back()->initialize();
    _items.back()->draw(_shader, _clock);
    _spreading -= 10;
  }
}


std::string                 LauncherUI::getUItoDisplay(int check) const
{
  return (!check ? "PlayUI" : (check == 1 ? "SettingsUI" : "QuitLauncher"));
}


void                        LauncherUI::updateContext()
{
  _window->updateContext(_clock, _input);
  for (auto i : _items)
    i->update(_clock, _input._default);
  for (auto i : _front)
    i->update(_clock, _input._default);
  _camera.update(_clock, _input);
}


void                        LauncherUI::launch()
{
  _isRunning = true;
  _window = VideoContext::instanciate();
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  if (!_first)
    _window->flush();
  if (_first)
  {
    _first = false;
    _window->setScreenWidth(_width);
    _window->setScreenHeight(_height);
    if (!_window->init())
      throw std::runtime_error("(LauncherUI::)launch - init VideoContext failed.");
  }
  this->setupDisplay();
}



stateUI                    LauncherUI::handlerEvent()
{
  _selected = PLAY;
  _behavior = PLAY;
  while (_isRunning)
  {
    usleep(75000);
    this->itemFocus();
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
      if (_input._default.getInput(SDLK_UP) || _input._default.getInput(SDLK_LEFT))
        _behavior = 1;
      else if (_input._default.getInput(SDLK_DOWN) || _input._default.getInput(SDLK_RIGHT))
        _behavior = -1;
    }
  }
  return (std::tuple<bool, std::string>(true, this->getName()));
}
