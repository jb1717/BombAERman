//
// SettingsUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 17:21:08 2015 TommyStarK
// Last update Sun Jun 14 22:07:41 2015 TommyStarK
//

#include "UIManager/SettingsUI.hh"

SettingsUI::SettingsUI()
  : _first(true), _spreading(2), _gameVolum(50), _fxVolum(50),
  _antiAliasing(false), _param(Settings::instance())
{
  this->updateSingletonSettings();
  _itemsName.push_back("aa");
  _itemsName.push_back("master-volume");
  _itemsName.push_back("fx-volume");
  _itemsName.push_back("back");
  _dynamicItems = _itemsName.size();
  _itemsName.push_back("SettingsBackground");
  _itemsName.push_back("settings-title");
  _itemsName.push_back("settings-help");
  _itemsName.push_back("bomb");
  _fixItems = _itemsName.size() - _dynamicItems;
  _cursor[ALIASING] = _spreading + 0.5;
  _cursor[MVOLUM] = -0.5;
  _cursor[FXVOLUM] = -3.5;
  _cursor[BACK] = -6.5;
  _posSettings[0] = new glm::vec3(-0.5, 2.5 + _spreading - (0 * 3.25), 25);
  _posSettings[1] = new glm::vec3(-0.5, _spreading - (1 * 3.25), 25);
  _posSettings[2] = new glm::vec3(-0.5, _spreading - (2 * 3.25) - 2.5, 25);
  this->setName("SettingsUI");
}

SettingsUI::~SettingsUI()
{

}

void                          SettingsUI::itemFocus()
{
  switch (_behavior) {
    case 1:
      _selected = (!_selected ? BACK : _selected == 1 ? ALIASING : _selected == 2 ? MVOLUM : FXVOLUM);
      break ;
    case -1:
      _selected = (_selected == 3 ? ALIASING : !_selected ? MVOLUM : _selected == 1 ? FXVOLUM : BACK);
      break ;
    default:
      break;
  }
  _behavior = 0;
  int cursor = _itemsName.size() - _dynamicItems - 1;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _front[cursor]->setPosition(glm::vec3(5.5, _cursor[_selected], 12));
  for (int i = 0; i < _fixItems; i++)
    _front[i]->draw(_shader, _clock);
  for (int i = 0; i < _dynamicItems - 1; i++)
    _settings[i]->draw(_shader, _clock);
  for (int i = 0; i < _dynamicItems; i++)
    _items[i]->draw(_shader, _clock);
  _window->flush();
}

void                          SettingsUI::setupDisplay()
{
  if (!_camera.setupCamera(*_window))
    throw std::runtime_error("(SettingsUI::)setupDisplay - setup camera failed.");
  if (!_shader.load(FRAGMENT_SHADER, GL_FRAGMENT_SHADER)
      || !_shader.load(VERTEX_SHADER, GL_VERTEX_SHADER)
      || !_shader.build())
    throw std::runtime_error("(SettingsUI::)setupDisplay - load/build shader failed.");
  _camera.setPosition(glm::vec3(0, 0, -20));
  _camera.setZoom(glm::vec3(12, 12, 12));
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
  _front[0] = new Geometric(glm::vec3(0, 0, 15.1), glm::vec3(0, 0, 0), glm::vec3(39, 20, 2));
  _front[1] = new Geometric(glm::vec3(0, 6.5, 12), glm::vec3(), glm::vec3(2.5, 1.75, 15));
  _front[2] = new Geometric(glm::vec3(-6.5, -3.5, 6.5), glm::vec3(), glm::vec3(4, 2, 10));
  _front[3] = new Geometric(glm::vec3(4.5, _cursor[ALIASING], 12), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
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
    _items.push_back(new Geometric(glm::vec3(3, _spreading, 10), glm::vec3(0, 0, 0), glm::vec3(2.5, 1.5, 40)));
    _items.back()->setGeometry(_factory->getGeometry(GeometryFactory::VERTICAL_PLANE));
    _items.back()->setTexture((*(*THEME((*THEME_HANDLER(asset["themes"]))["default"]))[_itemsName[i]]));
    _items.back()->initialize();
    _items.back()->draw(_shader, _clock);
    if (i < (_dynamicItems - 1))
    {
      std::vector<std::string>    tmp;
      std::ostringstream          gv;
      std::ostringstream          fx;
      gv << _gameVolum;
      fx << _fxVolum;
      tmp.push_back(!_antiAliasing ? "OFF" : "ON");
      tmp.push_back(gv.str());
      tmp.push_back(fx.str());
      _settings[i] = new GraphicString(tmp[i]);
      _settings[i]->render(*_factory);
      _settings[i]->translate(*_posSettings[i]);
      _settings[i]->scale(glm::vec3(2, 4, 10));
      _settings[i]->draw(_shader, _clock);
    }
    _spreading -= 2.5;
  }
  _spreading = 2;
}

void                          SettingsUI::modifySettings()
{
  std::ostringstream          in;

  switch (_selected) {
    case 0:
      _settings[_selected]->setText(!_antiAliasing ? "ON" : "OFF");
      _settings[_selected]->translate(*_posSettings[_selected]);
      _settings[_selected]->scale(glm::vec3(2, 4, 10));
      _antiAliasing = !_antiAliasing;
      break ;
    case 1:
      _gameVolum = _gameVolum ==  100 ? 0 : _gameVolum + 1;
      in << _gameVolum;
      _settings[_selected]->setText(in.str());
      _settings[_selected]->translate(*_posSettings[_selected]);
      _settings[_selected]->scale(glm::vec3(2, 4, 10));
      break ;
    case 2:
      _fxVolum = _fxVolum ==  100 ? 0 : _fxVolum + 1;
      in << _fxVolum;
      _settings[_selected]->setText(in.str());
      _settings[_selected]->translate(*_posSettings[_selected]);
      _settings[_selected]->scale(glm::vec3(2, 4, 10));
      break ;
    default:
      break ;
  }
}

void                          SettingsUI::updateSingletonSettings()
{
  _param.setAntiAliasing(_antiAliasing);
  _param.setGameVolum(_gameVolum);
  _param.setFxVolum(_fxVolum);
}

void                          SettingsUI::updateContext()
{
  _window->updateContext(_clock, _input);
  for (auto i : _items)
    i->update(_clock, _input._default);
  for (int i = 0; i < _dynamicItems - 1; i++)
    _settings[i]->update(_clock, _input._default);
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
  if (!_first)
  {
    _window->flush();
    _gameVolum = _param.getGameVolum();
    _fxVolum = _param.getFxVolum();
    _antiAliasing = _param.getAntiAliasing();
  }
  _first = false;
  this->setupDisplay();
}

stateUI                       SettingsUI::handlerEvent()
{
  _selected = ALIASING;
  _behavior = ALIASING;
  while (_isRunning)
  {
    usleep(75000);
    this->itemFocus();
    this->updateContext();
    if (_input._default.getKey(SDLK_ESCAPE) || _input._default.getInput(SDL_QUIT))
      return (std::tuple<bool, std::string>(true, "Quit"));
    else if (((_input._default.getKey(SDLK_RETURN) || _input._default.getInput(SDLK_RETURN))
         && _selected == BACK))
    {
      this->updateSingletonSettings();
      _isRunning = false;
      break ;
    }
    else if ((_input._default.getKey(SDLK_RETURN) || _input._default.getInput(SDLK_RETURN))
              && _selected < BACK)
      this->modifySettings();
    else
    {
      if (_input._default.getInput(SDLK_UP))
        _behavior = 1;
      else if (_input._default.getInput(SDLK_DOWN))
        _behavior = -1;
    }
  }
  return (std::tuple<bool, std::string>(true, this->getName()));
}
