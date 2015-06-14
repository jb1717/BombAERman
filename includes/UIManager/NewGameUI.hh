//
// NewGameUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun Jun 14 06:36:09 2015 TommyStarK
// Last update Sun Jun 14 20:43:07 2015 TommyStarK
//

#ifndef _NEWGAMEUI_HH_
# define _NEWGAMEUI_HH_

# include "AUI.hh"

class                 NewGameUI : public AUI
{
public:
  NewGameUI();
  ~NewGameUI();

public:
  enum Display {HUMAN = 0, ENNEMY = 1, DIFFICULTY = 2, MAP = 3, START = 4, BACK = 5};

private:
  bool                        _first;
  int                         _behavior;
  size_t                      _ia_iter;
  size_t                      _map_iter;
  int                         _selected;
  int                         _fixItems;
  int                         _dynamicItems;
  float                       _spreading;

private:
  int                         _human;
  int                         _ennemy;
  Settings                    &_settings;

private:
  Geometric                   *_front[3];
  glm::vec3                   *_pos[4];
  GraphicString               *_param[4];
  std::vector<Geometric *>    _items;
  std::vector<std::string>    _ia;
  std::vector<std::string>    _map;
  std::vector<std::string>    _itemsName;
  std::map<int, float>        _cursor;


private:
  void                        itemFocus();
  stateUI                     launchGame();
  void                        setupDisplay();
  void                        setupItemsNewGame();
  void                        modifyParameters();
  void                        updateParameters();
  void                        updateContext();


public:
  void                        launch();
  stateUI                     handlerEvent();
};


#endif /* end of include guard: _NEWGAMEUI_HH_ */
