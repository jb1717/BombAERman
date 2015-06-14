//
// NewGameUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun Jun 14 06:38:02 2015 TommyStarK
// Last update Sun Jun 14 22:34:59 2015 TommyStarK
//

#include "UIManager/NewGameUI.hh"

NewGameUI::NewGameUI()
  : _first(true), _ia_iter(0), _map_iter(0), _spreading(2),
    _human(1), _ennemy(0), _settings(Settings::instance())
{
  _ia = _settings.getIas();
  for (size_t i = 0; i < _ia.size(); i++)
    std::transform(_ia[i].begin(), _ia[i].end(), _ia[i].begin(), toupper);
  _map.push_back("TEST");
  _map.push_back("YOLO");
  _settings.setPlayerNbr(_human);
  _settings.setIaNbr(_ennemy);
  _settings.setDifficulty(_ia[_ia_iter]);
  _settings.setMapName(_map[_map_iter]);
  _itemsName.push_back("human");
  _itemsName.push_back("ennemy");
  _itemsName.push_back("difficulty");
  _itemsName.push_back("map");
  _itemsName.push_back("start-game");
  _itemsName.push_back("back");
  _dynamicItems = _itemsName.size();
  _itemsName.push_back("NewGameBackground");
  _itemsName.push_back("newgame");
  _itemsName.push_back("bomb");
  _fixItems = _itemsName.size() - _dynamicItems;
  _cursor[HUMAN] = _spreading + 0.5;
  _cursor[ENNEMY] = 0.75;
  _cursor[DIFFICULTY] = -1;
  _cursor[MAP] = -2.5;
  _cursor[START] = -4.5;
  _cursor[BACK] = -6.2;
  _pos[0] = new glm::vec3(-0.75, 2.5 + _spreading, 25);
  _pos[1] = new glm::vec3(-0.75, _spreading - 0.5, 25);
  _pos[2] = new glm::vec3(-0.75, _spreading - 4.5, 25);
  _pos[3] = new glm::vec3(-0.75, _spreading - 8, 25);
  this->setName("NewGameUI");
}

NewGameUI::~NewGameUI()
{

}

stateUI                        NewGameUI::launchGame()
{
  std::cout << "!!! NEW GAME !!!" << std::endl;
  return (std::tuple<bool, std::string>(false, "LAUNCHGAME:)"));
}

void                          NewGameUI::itemFocus()
{
  switch (_behavior) {
    case 1:
      _selected = (!_selected ? BACK : _selected == 1 ? HUMAN :
                  _selected == 2 ? ENNEMY : _selected == 3 ? DIFFICULTY :
                  _selected == 4 ? MAP : START);
      break ;
    case -1:
      _selected = (_selected == 5 ? HUMAN : !_selected ? ENNEMY :
                  _selected == 1 ? DIFFICULTY : _selected == 2 ? MAP :
                  _selected == 3 ? START : BACK);
      break ;
    default:
      break;
  }
  _behavior = 0;
  int cursor = _itemsName.size() - _dynamicItems - 1;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _front[cursor]->setPosition(glm::vec3(6.25, _cursor[_selected], 12));
  for (int i = 0; i < _fixItems; i++)
    _front[i]->draw(_shader, _clock);
  for (int i = 0; i < _dynamicItems - 2; i++)
    _param[i]->draw(_shader, _clock);
  for (int i = 0; i < _dynamicItems; i++)
    _items[i]->draw(_shader, _clock);
  _window->flush();
}

void                          NewGameUI::setupDisplay()
{
  if (!_camera.setupCamera(*_window))
    throw std::runtime_error("(NewGameUI::)setupDisplay - setup camera failed.");
  if (!_shader.load(FRAGMENT_SHADER, GL_FRAGMENT_SHADER)
      || !_shader.load(VERTEX_SHADER, GL_VERTEX_SHADER)
      || !_shader.build())
    throw std::runtime_error("(NewGameUI::)setupDisplay - load/build shader failed.");
  _camera.setPosition(glm::vec3(0, 0, -20));
  _camera.setZoom(glm::vec3(12, 12, 12));
  _camera.refreshPosition();
  _shader.bind();
  _camera.lockShader(_shader, true);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->setupItemsNewGame();
  _window->flush();
}

void                          NewGameUI::setupItemsNewGame()
{
  auto asset = AssetManager::instance();
  _factory = GeometryFactory::instanciate();
  _front[0] = new Geometric(glm::vec3(0, 0, 15.1), glm::vec3(0, 0, 0), glm::vec3(39, 20, 2));
  _front[1] = new Geometric(glm::vec3(0, 6.5, 12), glm::vec3(), glm::vec3(2, 1.25, 15));
  _front[2] = new Geometric(glm::vec3(6.5, _cursor[HUMAN], 12), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
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
    if (i < (_dynamicItems - 2))
    {
      _param[i] = new GraphicString(!i ? "1" : i == 1 ? "0" : i == 2 ? _ia[0]: _map[0]);
      _param[i]->render(*_factory);
      _param[i]->translate(*_pos[i]);
      _param[i]->scale(glm::vec3(2, 2, 1));
      _param[i]->draw(_shader, _clock);
    }
    _spreading -= 1.5;
  }
  _spreading = 2;
}

void                          NewGameUI::modifyParameters()
{
  std::ostringstream          in;

  switch (_selected) {
    case 0:
      _param[_selected]->setText(_human == 1 ? "2" : "1");
      _param[_selected]->translate(*_pos[_selected]);
      _param[_selected]->scale(glm::vec3(2, 2, 1));
      _human = _human == 1 ? _human - 1 : _human + 1;
      _settings.setPlayerNbr(_human);
      break ;
    case 1:
      _ennemy = _ennemy == 10 ? 0 : _ennemy + 1;
      in << _ennemy;
      _param[_selected]->setText(in.str());
      _param[_selected]->translate(*_pos[_selected]);
      _param[_selected]->scale(glm::vec3(2, 2, 1));
      _settings.setIaNbr(_ennemy);
      break ;
    case 2:
      _ia_iter = _ia_iter == _ia.size () - 1 ? 0 : _ia_iter + 1;
      _param[_selected]->setText(_ia[_ia_iter]);
      _param[_selected]->translate(*_pos[_selected]);
      _param[_selected]->scale(glm::vec3(2, 2, 1));
      _settings.setDifficulty(_ia[_ia_iter]);
      break ;
    case 3:
      _map_iter = _map_iter == _map.size() - 1 ? 0 : _map_iter + 1;
      _param[_selected]->setText(_map[_map_iter]);
      _param[_selected]->translate(*_pos[_selected]);
      _param[_selected]->scale(glm::vec3(2, 2, 1));
      _settings.setMapName(_map[_map_iter]);
      break ;
    default:
      break ;
  }
}

void                          NewGameUI::updateContext()
{
  _window->updateContext(_clock, _input);
  for (auto i : _items)
    i->update(_clock, _input._default);
  for (int i = 0; i < _dynamicItems - 2; i++)
    _param[i]->update(_clock, _input._default);
  for (int i = 0; i < _fixItems; i++)
    _front[i]->update(_clock, _input._default);
  _camera.update(_clock, _input);
}


void                          NewGameUI::launch()
{
  _isRunning = true;
  _window = VideoContext::instanciate();
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  if (!_first) {
    _window->flush();
    _human = _settings.getPlayerNbr();
    _ennemy = _settings.getIaNbr();
  }
  _first = false;
  this->setupDisplay();
}


stateUI                       NewGameUI::handlerEvent()
{
  _selected = HUMAN;
  _behavior = HUMAN;
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
      _isRunning = false;
      break ;
    }
    else if ((_input._default.getKey(SDLK_RETURN) || _input._default.getInput(SDLK_RETURN))
              && _selected == START)
      return (this->launchGame());
    else if ((_input._default.getKey(SDLK_RETURN) || _input._default.getInput(SDLK_RETURN))
              && _selected < BACK)
      this->modifyParameters();
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
