//
// LauncherUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 21:39:13 2015 TommyStarK
// Last update Sun May 24 12:51:09 2015 TommyStarK
//

#ifndef _LAUNCHERUI_HH_
# define _LAUNCHERUI_HH_

# include <vector>
# include <iostream>
# include <utility>
# include <stdexcept>
# include <unistd.h>
# include "AUI.hh"
# include "Camera.hh"
# include "Texture.hh"
# include "gameEngine/graphics.hh"
# include "gameEngine/Cube.hh"
# include "gameEngine/AGameObject.hh"
# include "gameEngine/GameEngine.hh"
# include "gameEngine/VideoContext.hh"

typedef std::vector<std::pair<std::string, gdl::Texture *>> TextureHandler;

class      LauncherUI : public AUI
{
public:
  LauncherUI(int, int, const std::string &);
  ~LauncherUI();

// private functionals attributes
private:
  int                   _width;
  int                   _height;
  int                   _selected;
  std::string           _name;

// private display attributes
private:
  Camera                _camera;
  gdl::Texture          *_background;
  gdl::BasicShader      _shader;
  VideoContext          *_window;

// private contenairs to handle display UI
private:
  TextureHandler              _texturehandler;
  std::vector<AGameObject *>  _items;

// Enum representing different choices for users
public:
  enum Display {PLAY = 0, SETTINGS = 1, QUIT = 2};

// Setup of necessary parameters to display Context.
// Update Context to refresh window.
// Returns a std::string containing name to UI to display.
private:
  void                  setUpDisplay();
  void                  updateContext();
  std::string           getUItoDisplay(int) const;

// Public access
public:
  void                  launch();
  stateUI               handlerEvent();


};


#endif /* end of include guard: _LAUNCHERUI_HH_ */
