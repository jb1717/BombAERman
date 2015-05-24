//
// LauncherUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 21:39:13 2015 TommyStarK
// Last update Sun May 24 06:52:46 2015 TommyStarK
//

#ifndef _LAUNCHERUI_HH_
# define _LAUNCHERUI_HH_

# include "AUI.hh"
# include <iostream>
# include "gameEngine/graphics.hh"
# include "gameEngine/VideoContext.hh"

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
  VideoContext          *_window;

// Enum representing different choices for users
public:
  enum Display {PLAY = 0, SETTINGS = 1, QUIT = 2};

// Returns a std::string containing name to UI to display
private:
  std::string           getUItoDisplay(int) const;

// Public access
public:
  void                  launch();
  stateUI               handlerEvent();


};


#endif /* end of include guard: _LAUNCHERUI_HH_ */
