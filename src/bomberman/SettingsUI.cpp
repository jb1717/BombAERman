//
// SettingsUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 17:21:08 2015 TommyStarK
// Last update Sat Jun 13 03:25:12 2015 Milox Thomas
//

#include "UIManager/SettingsUI.hh"

SettingsUI::SettingsUI(int width, int height, const std::string & winName)
  : _width(width), _height(height), _spreading(2), _name(winName)
{
  _itemsName.push_back("music");
  _itemsName.push_back("players");
  _itemsName.push_back("quit");
  _dynamicItems = _itemsName.size();
  _itemsName.push_back("SettingsBackground");
  _itemsName.push_back("SettingsTitle3");
  _itemsName.push_back("bomb");
  _fixItems = _itemsName.size() - _dynamicItems;
  _cursor[NBR] = _spreading + 0.5;
  this->setName("SettingsUI");
}

SettingsUI::~SettingsUI()
{

}

void                          SettingsUI::setupDisplay()
{
  if (!_camera.setupCamera(*_window))
    throw std::runtime_error("(SettingsUI::)setupDisplay - setup camera failed.");
  if (!_shader.load(FRAGMENT_SHADER, GL_FRAGMENT_SHADER)
      || !_shader.load(VERTEX_SHADER, GL_VERTEX_SHADER)
      || !_shader.build())
    throw std::runtime_error("(SettingsUI::)setupDisplay - load/build shader failed.");
  _camera.setPosition(glm::vec3(0, 0, -2));
  _camera.refreshPosition();
  _shader.bind();
  _camera.lockShader(_shader, true);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->setupItemsSettings();
  _window->flush();
}

void                          SettingsUI::setupItemsSettings()
{
  auto asset = AssetManager::instance();
  _factory = GeometryFactory::instanciate();
  _front[0] = new Geometric(glm::vec3(0, 0, 15.1), glm::vec3(), glm::vec3(40, 24, 1));
  _front[1] = new Geometric(glm::vec3(0, 7, 12), glm::vec3(), glm::vec3(2, 2, 1));
  _front[2] = new Geometric(glm::vec3(5.5, _cursor[NBR], 12), glm::vec3(), glm::vec3(1.5, 1.5, 1));
  int fixItems = _itemsName.size() - _dynamicItems;
  for (int i = 0; i < _fixItems; i++) {
    int n = _itemsName.size() - fixItems;
    _front[i]->setGeometry(_factory->getGeometry(GeometryFactory::VERTICAL_PLANE));
    _front[i]->setTexture((*(*THEME((*THEME_HANDLER(asset["themes"]))["default"]))[_itemsName[n]]));
    _front[i]->initialize();
    _front[i]->draw(_shader, _clock);
    --fixItems;
  }
  for (int i = 0; i < _dynamicItems; i++) {
    _items.push_back(new Geometric(glm::vec3(3, _spreading, 10), glm::vec3(), glm::vec3(2.5, 1.15, 1.25)));
    _items.back()->setGeometry(_factory->getGeometry(GeometryFactory::VERTICAL_PLANE));
    _items.back()->setTexture((*(*THEME((*THEME_HANDLER(asset["themes"]))["default"]))[_itemsName[i]]));
    _items.back()->initialize();
    _items.back()->draw(_shader, _clock);
    _spreading -= 3;
  }
}

void                          SettingsUI::updateContext()
{
  _window->updateContext(_clock, _input);
  for (auto i : _items)
    i->update(_clock, _input._default);
  for (int i = 0; i < _fixItems; i++)
    _front[i]->update(_clock, _input._default);
  _camera.update(_clock, _input);
}

void                          SettingsUI::launch()
{
  _isRunning = true;
  _window = VideoContext::instanciate();
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  this->setupDisplay();
}

stateUI                       SettingsUI::handlerEvent()
{
  while (_isRunning)
  {
    usleep(75000);
    this->updateContext();
    if (_input._default.getKey(SDLK_ESCAPE) || _input._default.getInput(SDL_QUIT))
    {
      _isRunning = false;
      break ;
    }
  }
  return (std::tuple<bool, std::string>(true, this->getName()));
}
