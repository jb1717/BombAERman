//
// UIManager.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 20:58:21 2015 TommyStarK
// Last update Sun May 24 00:16:54 2015 TommyStarK
//

#ifndef _UIMANAGER_HH_
# define _UIMANAGER_HH_

# include <map>
# include <string>
# include <memory>
# include "AUI.hh"
# include "LauncherUI.hh"
# include <iostream>

class      UIManager
{
public:
  UIManager();
  ~UIManager();

private:
  int                               _defaultWidthWin;
  int                               _defaultHeightWin;
  std::string                       _defaultName;

private:
  std::map<std::string, std::shared_ptr<AUI>>  _ui;

public:
  void                              startService();

public:
  std::shared_ptr<AUI>              operator[](const std::string &);


};

#endif /* end of include guard: _UIMANAGER_HH_ */
