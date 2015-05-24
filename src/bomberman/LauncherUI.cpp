//
// LauncherUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 22:06:02 2015 TommyStarK
// Last update Sun May 24 06:49:53 2015 TommyStarK
//

#include "UIManager/LauncherUI.hh"

LauncherUI::LauncherUI(int width, int height, const std::string & winName)
  : _width(width), _height(height), _name(winName)
{
  this->setName("StartUI");
}

LauncherUI::~LauncherUI()
{

}

std::string                LauncherUI::getUItoDisplay(int check) const
{
  std::cout << check << std::endl;
  return (!check ? "PlayUI" : (check == 1 ? "SettingsUI" : "Quit"));
}

void                       LauncherUI::launch()
{
  _isRunning = true;
  _window = new VideoContext(_width, _height, _name);
  _window->setScreenWidth(_width);
  _window->setScreenHeight(_height);
  _window->init();
}


stateUI                    LauncherUI::handlerEvent()
{
  _selected = PLAY;
  while (_isRunning)
  {
    _window->updateContext(_clock, _input);
    if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    {
      _isRunning = false;
      break ;
    }
    else if (_input.getKey(SDLK_RETURN) || _input.getInput(SDLK_RETURN))
      return (std::tuple<bool, std::string>(true, this->getUItoDisplay(_selected)));
    else
    {
      if ((_input.getKey(SDLK_UP) || _input.getInput(SDLK_UP)))
        _selected = (!_selected ? QUIT : (_selected - 1));
      else if ((_input.getKey(SDLK_DOWN) || _input.getInput(SDLK_DOWN)))
        _selected = (_selected == QUIT ? PLAY : (_selected + 1));
      _window->updateContext(_clock, _input);
    }
  }
  return (_selected = 0, std::tuple<bool, std::string>(true, this->getName()));
}
