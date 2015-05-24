//
// UIManager.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 20:58:21 2015 TommyStarK
// Last update Sun May 24 18:00:20 2015 TommyStarK
//

#ifndef _UIMANAGER_HH_
# define _UIMANAGER_HH_

# include <map>
# include <string>
# include <memory>
# include <iostream>
# include "AUI.hh"
# include "PlayUI.hh"
# include "PauseUI.hh"
# include "SettingsUI.hh"
# include "LauncherUI.hh"

class      UIManager
{
public:
  UIManager();
  ~UIManager();

// private functionals attributes
private:
  bool                              _start;
  bool                              _pause;
  bool                              _running;
  std::string                       _current;

// private attributes to hold on user window parameters
private:
  int                               _defaultWidthWin;
  int                               _defaultHeightWin;
  std::string                       _defaultName;

// differents UIs handled
private:
  std::map<std::string, std::shared_ptr<AUI>>  _ui;

// private interns functions
private:
  void                              UIhandler(const std::string &);
  std::tuple<int, std::string>      controller(bool, const std::string &);

// public access
public:
  void                              startService();

// public operator<< to launch UI by its name
// public operator[] to access UI by its name
public:
  UIManager                         &operator<<(const std::string &);
  std::shared_ptr<AUI>              operator[](const std::string &);


};

#endif /* end of include guard: _UIMANAGER_HH_ */
