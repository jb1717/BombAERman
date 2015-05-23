//
// UIManager.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 21:02:19 2015 TommyStarK
// Last update Sun May 24 00:17:38 2015 TommyStarK
//

#include "UIManager/UIManager.hh"

UIManager::UIManager()
  : _defaultWidthWin(1820), _defaultHeightWin(980), _defaultName("BombAERman")
{
  _ui["Game-Launcher"] = std::make_shared<LauncherUI>(_defaultWidthWin,
                                                      _defaultHeightWin,
                                                      _defaultName);
  this->startService();
}

UIManager::~UIManager()
{

}

void                          UIManager::startService()
{
  _ui["Game-Launcher"]->launch();
}

std::shared_ptr<AUI>          UIManager::operator[](const std::string &name)
{
  if (_ui.find(name) != _ui.end())
    return _ui[name];
  return nullptr;
}
