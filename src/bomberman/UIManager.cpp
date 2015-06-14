//
// UIManager.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 21:02:19 2015 TommyStarK
// Last update Sun Jun 14 04:36:37 2015 TommyStarK
//

#include "UIManager/UIManager.hh"

UIManager::UIManager()
  : _start(true), _pause(false), _running(true), _current("StartUI"),
    _defaultWidthWin(1820), _defaultHeightWin(980), _defaultName("BombAERman")
{
  _ui["StartUI"] = std::make_shared<LauncherUI>(_defaultWidthWin, _defaultHeightWin, _defaultName);
  _ui["SettingsUI"] = std::make_shared<SettingsUI>();
  _ui["PlayUI"] = std::make_shared<PlayUI>();
  _ui["CreditsUI"] = std::make_shared<CreditsUI>();
  // _ui["NewGameUI"] = std::make_shared<NewGameUI>();
  // _ui["LoadGameUI"] = std::make_shared<LoadGameUI>();
  _ui["PauseUI"] = std::make_shared<PauseUI>();
  this->startService();
}

UIManager::~UIManager()
{

}

void                          UIManager::startService()
{
  if (_start)
    this->UIhandler(_current);
}

std::tuple<int, std::string>  UIManager::controller(bool quit, const std::string &ui)
{
  int i = !quit ? 0 : 1;

  switch (i) {
    case 0:
        if (ui == "PlayUI")
          return (std::tuple<int, std::string>(0, ui));
        else if (ui == "SettingsUI")
          return (std::tuple<int, std::string>(0, ui));
        else if (ui == "QuitLauncher")
          return (std::tuple<int, std::string>(0, "CreditsUI"));
        else
          break ;
    case 1:
        if (ui == "Quit")
          return (std::tuple<int, std::string>(3, ""));
        else if (ui == "SettingsUI" || ui == "PlayUI")
          return (std::tuple<int, std::string>(0, "StartUI"));
    default:
      break ;
  }
  return (std::tuple<int, std::string>(3, ""));
}

void                          UIManager::UIhandler(const std::string &name)
{
  int  i = 0;
  auto tmp = std::make_tuple(false, _current);
  _current = name != _current ? name : _current;
  while (_running)
  {
    switch (i) {
      case 0:
      {
        _ui[_current]->launch();
        i = 1;
      }
      case 1:
      {
        while (i = 2, !std::get<0>(tmp) && std::get<1>(tmp) == _current)
          tmp = _ui[_current]->handlerEvent();
      }
      case 2:
      {
        auto dispatch = this->controller(std::get<0>(tmp), std::get<1>(tmp));
        i = std::get<0>(dispatch);
        _current = std::get<1>(dispatch);
        break ;
      }
      default:
      {
        _running = false;
        break;
      }
    }
    std::get<0>(tmp) = false;
    std::get<1>(tmp) = _current;
  }
}

UIManager                     &UIManager::operator<<(const std::string &name)
{
  if (_ui.find(name) != _ui.end())
    this->UIhandler(name);
  return *this;
}


std::shared_ptr<AUI>          UIManager::operator[](const std::string &name)
{
  if (_ui.find(name) != _ui.end())
    return _ui[name];
  return nullptr;
}
