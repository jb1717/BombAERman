//
// LoadGameUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun Jun 14 11:12:30 2015 TommyStarK
// Last update Sun Jun 14 20:41:08 2015 TommyStarK
//

#ifndef _LOADGAMEUI_HH
# define _LOADGAMEUI_HH

# include <map>
# include <vector>
# include <utility>
# include <iostream>
# include <stdexcept>
# include <unistd.h>
# include "AUI.hh"

class             LoadGameUI : public AUI
{
public:
  LoadGameUI();
  ~LoadGameUI();

public:
  enum Display {SELECT = 0, LOAD = 1, BACK = 2};

private:
  bool                        _first;
  int                         _behavior;
  int                         _selected;
  int                         _fixItems;
  int                         _dynamicItems;
  float                       _spreading;
  size_t                      _currentSave;

private:
  Settings                    &_settings;
  std::vector<std::string>    _saves;
  std::vector<std::string>    _itemsName;
  std::map<int, float>        _cursor;

private:
  glm::vec3                   *_pos;
  Geometric                   *_front[3];
  GraphicString               *_current;
  std::vector<Geometric *>    _items;

private:
  void                        itemsFocus();
  stateUI                     loadGame();
  void                        setupDisplay();
  void                        setupItemsLoad();
  void                        displaySaveToLoad();
  void                        updateContext();

public:
  void                        launch();
  stateUI                     handlerEvent();
};


#endif /* end of include guard: _LOADGAMEUI_HH */
