//
// LauncherUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 22:06:02 2015 TommyStarK
// Last update Sun May 24 00:16:15 2015 TommyStarK
//

#include "UIManager/LauncherUI.hh"

LauncherUI::LauncherUI(int width, int height, const std::string & winName)
  : _width(width), _height(height), _name(winName)
{

}

LauncherUI::~LauncherUI()
{

}

void                        LauncherUI::launch()
{
  _isRunning = true;
  _window = new VideoContext(_width, _height, _name);
  _window->setScreenWidth(_width);
  _window->setScreenHeight(_height);
  _window->init();
  this->handlerEvent();
}


void                        LauncherUI::handlerEvent()
{
  while (1);
}
