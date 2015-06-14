//
// LauncherUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 21:39:13 2015 TommyStarK
// Last update Sun Jun 14 00:42:04 2015 TommyStarK
//

#ifndef _LAUNCHERUI_HH_
# define _LAUNCHERUI_HH_

# include <map>
# include <vector>
# include <utility>
# include <iostream>
# include <stdexcept>
# include <unistd.h>
# include "AUI.hh"

class      LauncherUI : public AUI
{
public:
  LauncherUI(int, int, const std::string &);
  ~LauncherUI();

// Enum representing different choices for users.
// It will serve to remember the cursor position of the user.
public:
  enum Display {PLAY = 0, SETTINGS = 1, QUIT = 2};


// Private functionals attributes.
// Window parameters & tools to handle events.
private:
  int                         _width;
  int                         _height;
  int                         _behavior;
  int                         _selected;
  int                         _dynamicItems;
  bool                        _first;
  float                       _spreading;
  std::string                 _name;


// Private menu attributes.
private:
  Geometric                   *_front[3];
  std::vector<std::string>    _itemsName;
  std::vector<Geometric *>    _items;
  std::map<int, float>        _cursor;



// Setup of necessary parameters to display Context.
// Update Context to refresh window & handle last event on the frame.
// Setup of items which will be shown on menu.
// ItemFocus handle the current user's choice.
// getUItoDisplay returns a std::string containing name of next UI to display.
private:
  void                      itemFocus();
  void                      setupDisplay();
  void                      setupItemsMenu();
  std::string               getUItoDisplay(int) const;
  void                      updateContext();

// Public access.
public:
  void                      launch();
  stateUI                   handlerEvent();
};


#endif /* end of include guard: _LAUNCHERUI_HH_ */
