//
// PlayUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 17:22:00 2015 TommyStarK
// Last update Sun Jun 14 05:04:39 2015 TommyStarK
//

#include "UIManager/PlayUI.hh"

PlayUI::PlayUI()
: _first(true), _spreading(2)
{
  this->getIaNames();
  auto settings = Settings::instance();
  for (auto i : _iaNames)
    settings.addIa(i);
  _itemsName.push_back("newgame");
  _itemsName.push_back("loadgame");
  _itemsName.push_back("back");
  _dynamicItems = _itemsName.size();
  _itemsName.push_back("PlayBackground");
  _itemsName.push_back("bomb");
  _fixItems = _itemsName.size() - _dynamicItems;
  _cursor[NEWGAME] = _spreading + 0.5;
  _cursor[LOADGAME] = -0.5;
  _cursor[BACK] = -3.5;
  this->setName("PlayUI");
}

PlayUI::~PlayUI()
{

}

void                          PlayUI::getIaNames()
{
  DIR                         *dir = opendir("./ia");
  size_t                      pos = 0;
  struct dirent               *current = NULL;
  std::vector<std::string>    tmp;

  if (dir) {
    while ((current = readdir(dir)) != NULL) {
      tmp.push_back(current->d_name);
    }
    for (auto i : tmp) {
      if ((pos = i.find_last_of(".")) != std::string::npos && i.substr(pos) == ".chai")
      {
        std::string token;
        token = i.substr(0, pos);
        _iaNames.push_back(token);
      }
    }
  }
}

void                          PlayUI::itemsFocus()
{
  switch (_behavior) {
    case 1:
      _selected = (!_selected ? BACK : _selected == 1 ? NEWGAME : LOADGAME);
      break ;
    case -1:
      _selected = (_selected == 2 ? NEWGAME : !_selected ? LOADGAME : BACK);
      break ;
    default:
      break;
  }
  _behavior = 0;
  int cursor = _itemsName.size() - _dynamicItems - 1;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _front[cursor]->setPosition(glm::vec3(2.5, _cursor[_selected] , 12));
  for (auto i : _front)
    i->draw(_shader, _clock);
  for (auto i : _items)
    i->draw(_shader, _clock);
  _window->flush();
}


void                          PlayUI::setupDisplay()
{
  if (!_camera.setupCamera(*_window))
    throw std::runtime_error("(LauncherUI::)setUpDisplay - setup camera failed.");
  if (!_shader.load(FRAGMENT_SHADER, GL_FRAGMENT_SHADER)
      || !_shader.load(VERTEX_SHADER, GL_VERTEX_SHADER)
      || !_shader.build())
    throw std::runtime_error("(LauncherUI::)setUpDisplay - load/build shader failed.");
  // _camera.setPosition(glm::vec3(0, 0, -2));
  // _camera.refreshPosition();
  _camera.setPosition(glm::vec3(0, 0, -20));
  _camera.setZoom(glm::vec3(12, 12, 12));
  _camera.refreshPosition();
  _shader.bind();
  _camera.lockShader(_shader, true);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->setupItemsToGame();
  _window->flush();
}

void                          PlayUI::setupItemsToGame()
{
  auto asset = AssetManager::instance();
  _factory = GeometryFactory::instanciate();
  _front[0] = new Geometric(glm::vec3(0, 0, 15.1), glm::vec3(0, 0, 0), glm::vec3(38, 20, 4));
  _front[1] = new Geometric(glm::vec3(3.5, _cursor[NEWGAME], 12), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
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
    _items.push_back(new Geometric(glm::vec3(0, _spreading, 10), glm::vec3(0, 0, 0), glm::vec3(2.5, 1.75, 100)));
    _items.back()->setGeometry(_factory->getGeometry(GeometryFactory::VERTICAL_PLANE));
    _items.back()->setTexture((*(*THEME((*THEME_HANDLER(asset["themes"]))["default"]))[_itemsName[i]]));
    _items.back()->initialize();
    _items.back()->draw(_shader, _clock);
    _spreading -= 2.5;
  }
  _spreading = 2;
}

void                          PlayUI::updateContext()
{
  _window->updateContext(_clock, _input);
  for (int i = 0; i < _dynamicItems; i++)
    _items[i]->update(_clock, _input._default);
  for (int i = 0; i < _fixItems; i++)
    _front[i]->update(_clock, _input._default);
  _camera.update(_clock, _input);

}

std::string                   PlayUI::displayNextUi()
{
  return (!_selected ? "NEWGAME" : "LOADGAME");
}

void                          PlayUI::launch()
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

stateUI                       PlayUI::handlerEvent()
{
  _selected = NEWGAME;
  _behavior = NEWGAME;
  while (_isRunning)
  {
    usleep(75000);
    this->itemsFocus();
    this->updateContext();
    if (_input._default.getKey(SDLK_ESCAPE) || _input._default.getInput(SDL_QUIT) ||
        ((_input._default.getKey(SDLK_RETURN) || _input._default.getInput(SDLK_RETURN))
         && _selected == BACK))
    {
      _isRunning = false;
      break ;
    }
    else if ((_input._default.getKey(SDLK_RETURN) || _input._default.getInput(SDLK_RETURN))
              && _selected < BACK)
      return (std::tuple<bool, std::string>(false, this->displayNextUi()));
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
