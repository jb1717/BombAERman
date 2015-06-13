//
// SettingsUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 17:35:33 2015 TommyStarK
// Last update Sat Jun 13 03:47:38 2015 TommyStarK
//

#ifndef  _SETTINGSUI_HH_
#define _SETTINGSUI_HH_

# include <map>
# include <vector>
# include <utility>
# include <iostream>
# include <stdexcept>
# include <unistd.h>
#include "AUI.hh"

class       SettingsUI : public AUI
{
public:
  SettingsUI(int, int,const std::string &);
  ~SettingsUI();

public:
  enum Display {NBR = 0, SOUND = 1, QUIT = 2};

private:
  int                         _width;
  int                         _height;
  int                         _behavior;
  int                         _selected;
  int                         _fixItems;
  int                         _dynamicItems;
  float                       _spreading;
  std::string                 _name;

private:
  Geometric                   *_front[3];
  GraphicString               *_text;
  std::vector<Geometric *>    _items;
  std::vector<std::string>    _itemsName;
  std::map<int, float>        _cursor;


private:
  void                        setupDisplay();
  void                        setupItemsSettings();
  void                        updateContext();

public:
  void                        launch();
  stateUI                     handlerEvent();
};

#endif /* end of include guard: _SETTINGSUI_HH_ */
