//
// PlayUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 17:32:15 2015 TommyStarK
// Last update Sun Jun 14 04:37:18 2015 TommyStarK
//

#ifndef  _PLAYUI_HH_
# define _PLAYUI_HH_

# include <dirent.h>
# include <string>
# include <vector>
# include <stdlib.h>
# include "AUI.hh"

class             PlayUI : public AUI
{
public:
  PlayUI();
  ~PlayUI();

public:
  enum Display {NEWGAME = 0, LOADGAME = 1, BACK = 2};

private:
  bool                        _first;
  int                         _behavior;
  int                         _selected;
  int                         _fixItems;
  int                         _dynamicItems;
  float                       _spreading;

private:
  std::vector<std::string>    _iaNames;
  std::vector<std::string>    _itemsName;
  std::map<int , float>       _cursor;

private:
  Geometric                   *_front[2];
  std::vector<Geometric *>    _items;


private:
  void                        getIaNames();
  void                        setupDisplay();
  void                        itemsFocus();
  void                        setupItemsToGame();
  void                        updateContext();
  std::string                 displayNextUi();

public:
  void                        launch();
  stateUI                     handlerEvent();


};

#endif /* end of include guard: _PLAYUI_HH_ */
