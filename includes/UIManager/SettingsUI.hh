//
// SettingsUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 17:35:33 2015 TommyStarK
// Last update Sun Jun 14 19:13:15 2015 TommyStarK
//

#ifndef  _SETTINGSUI_HH_
#define _SETTINGSUI_HH_

# include <map>
# include <vector>
# include <utility>
# include <iostream>
# include <stdexcept>
# include <unistd.h>
# include "AUI.hh"

class       SettingsUI : public AUI
{
public:
  SettingsUI();
  ~SettingsUI();

public:
  enum Display {ALIASING = 0, MVOLUM = 1, FXVOLUM = 2, BACK = 3};

private:
  bool                        _first;
  int                         _behavior;
  int                         _selected;
  int                         _fixItems;
  int                         _dynamicItems;
  float                       _spreading;

private:
  int                         _gameVolum;
  int                         _fxVolum;
  bool                        _antiAliasing;
  Settings                    &_param;

private:
  Geometric                   *_front[4];
  glm::vec3                   *_posSettings[3];
  GraphicString               *_settings[3];
  std::vector<Geometric *>    _items;
  std::vector<std::string>    _itemsName;
  std::map<int, float>        _cursor;


private:
  void                        setupDisplay();
  void                        setupItemsSettings();
  void                        itemFocus();
  void                        modifySettings();
  // void                        updateSettings();
  void                        updateSingletonSettings();
  void                        updateContext();

public:
  void                        launch();
  stateUI                     handlerEvent();
};

#endif /* end of include guard: _SETTINGSUI_HH_ */
