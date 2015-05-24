//
// LauncherUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 21:39:13 2015 TommyStarK
// Last update Sun May 24 00:08:12 2015 TommyStarK
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

private:
  int                   _width, _height;
  std::string           _name;
  VideoContext          *_window;

public:
  void                  launch();
  void                  handlerEvent();


};


#endif /* end of include guard: _LAUNCHERUI_HH_ */
