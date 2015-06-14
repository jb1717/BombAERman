//
// LoadGameUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun Jun 14 11:14:23 2015 TommyStarK
// Last update Sun Jun 14 22:09:22 2015 TommyStarK
//

#include "UIManager/LoadGameUI.hh"

LoadGameUI::LoadGameUI()
  : _first(true), _spreading(-1), _currentSave(0), _settings(Settings::instance())
{
  _saves = _settings.getIas();
  for (size_t i = 0; i < _saves.size(); i++)
    std::transform(_saves[i].begin(), _saves[i].end(), _saves[i].begin(), toupper);
  _itemsName.push_back("loadgame-text");
  _itemsName.push_back("resume");
  _itemsName.push_back("back");
  _dynamicItems = _itemsName.size();
  _itemsName.push_back("LoadGameBackground");
  _itemsName.push_back("loadgame");
  _itemsName.push_back("bomb");
  _fixItems = _itemsName.size() - _dynamicItems;
  _cursor[SELECT] = -1;
  _cursor[LOAD] = -3.5;
  _cursor[BACK] = -5.75;
  _pos = new glm::vec3(-13, _spreading - 1.25, 25);
  this->setName("LoadGameUI");
}

LoadGameUI::~LoadGameUI()
{

}

stateUI                        LoadGameUI::loadGame()
{
  std::cout << "!!! LOAD GAME !!!" << std::endl;
  return (std::tuple<bool, std::string>(false, "LAUNCHGAME:)"));
}

void                          LoadGameUI::itemsFocus()
{
  switch (_behavior) {
    case 1:
      _selected = (!_selected ? BACK : _selected == 1 ? SELECT : LOAD);
      break ;
    case -1:
      _selected = (_selected == 2 ? SELECT : !_selected ? LOAD : BACK);
      break ;
    default:
      break;
  }
  _behavior = 0;
  int cursor = _itemsName.size() - _dynamicItems - 1;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _front[cursor]->setPosition(glm::vec3(-0.5, _cursor[_selected] , 12));
  for (auto i : _front)
    i->draw(_shader, _clock);
  _current->draw(_shader, _clock);
  for (auto i : _items)
    i->draw(_shader, _clock);
  _window->flush();
}

void                          LoadGameUI::setupDisplay()
{
  if (!_camera.setupCamera(*_window))
    throw std::runtime_error("(LoadGameUI::)setupDisplay - setup camera failed.");
  if (!_shader.load(FRAGMENT_SHADER, GL_FRAGMENT_SHADER)
      || !_shader.load(VERTEX_SHADER, GL_VERTEX_SHADER)
      || !_shader.build())
    throw std::runtime_error("(LoadGameUI::)setupDisplay - load/build shader failed.");
  _camera.setPosition(glm::vec3(0, 0, -20));
  _camera.setZoom(glm::vec3(12, 12, 12));
  _camera.refreshPosition();
  _shader.bind();
  _camera.lockShader(_shader, true);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->setupItemsLoad();
  _window->flush();
}

void                          LoadGameUI::setupItemsLoad()
{
  auto asset = AssetManager::instance();
  _factory = GeometryFactory::instanciate();
  _front[0] = new Geometric(glm::vec3(0, 0, 15.1), glm::vec3(0, 0, 0), glm::vec3(39, 20, 2));
  _front[1] = new Geometric(glm::vec3(1, 7.2, 12), glm::vec3(), glm::vec3(1.5, 1, 15));
  _front[2] = new Geometric(glm::vec3(-0.5, _cursor[SELECT], 12), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
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
    _items.push_back(new Geometric(glm::vec3(-2.5, _spreading, 10), glm::vec3(0, 0, 0), glm::vec3(2.5, 1.5, !i ? 40 : 20)));
    _items.back()->setGeometry(_factory->getGeometry(GeometryFactory::VERTICAL_PLANE));
    _items.back()->setTexture((*(*THEME((*THEME_HANDLER(asset["themes"]))["default"]))[_itemsName[i]]));
    _items.back()->initialize();
    _items.back()->draw(_shader, _clock);
    if (!i)
    {
      _current = new GraphicString(_saves[i]);
      _current->render(*_factory);
      _current->translate(*_pos);
      _current->scale(glm::vec3(2, 2, 1));
      _current->draw(_shader, _clock);
    }
    _spreading -= 2;
  }
  _spreading = -1;
}

void                          LoadGameUI::displaySaveToLoad()
{
  _currentSave = _currentSave == _saves.size() - 1 ? 0 : _currentSave + 1;
  _current->setText(_saves[_currentSave]);
  _current->translate(*_pos);
  _current->scale(glm::vec3(2, 2, 1));
  _settings.setLoading(_saves[_currentSave]);
}

void                          LoadGameUI::updateContext()
{
  _window->updateContext(_clock, _input);
  for (int i = 0; i < _dynamicItems; i++)
    _items[i]->update(_clock, _input._default);
  _current->update(_clock, _input._default);
  for (int i = 0; i < _fixItems; i++)
    _front[i]->update(_clock, _input._default);
  _camera.update(_clock, _input);
}

void                          LoadGameUI::launch()
{
  _isRunning = true;
  _window = VideoContext::instanciate();
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  if (!_first)
    _window->flush();
  _first = false;
  this->setupDisplay();
}

stateUI                       LoadGameUI::handlerEvent()
{
  _selected = SELECT;
  _behavior = SELECT;
  while (_isRunning)
  {
    usleep(75000);
    this->itemsFocus();
    this->updateContext();
    if (_input._default.getKey(SDLK_ESCAPE) || _input._default.getInput(SDL_QUIT))
      return (std::tuple<bool, std::string>(true, "Quit"));
    else if (((_input._default.getKey(SDLK_RETURN) || _input._default.getInput(SDLK_RETURN))
         && _selected == BACK))
    {
      _isRunning = false;
      break ;
    }
    else if ((_input._default.getKey(SDLK_RETURN) || _input._default.getInput(SDLK_RETURN))
              && _selected == SELECT)
      this->displaySaveToLoad();
    else if ((_input._default.getKey(SDLK_RETURN) || _input._default.getInput(SDLK_RETURN))
              && _selected == LOAD)
      return (this->loadGame());
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
