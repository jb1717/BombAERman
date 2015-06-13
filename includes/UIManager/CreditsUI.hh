//
// CreditsUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat Jun 13 00:55:20 2015 TommyStarK
// Last update Sun Jun 14 00:24:32 2015 TommyStarK
//

#ifndef _CREDITSUI_HH_
# define _CREDITSUI_HH_

# include <map>
# include <vector>
# include <utility>
# include <iostream>
# include <stdexcept>
# include <unistd.h>
# include "AUI.hh"

class           CreditsUI : public AUI
{
public:
  CreditsUI();
  ~CreditsUI();

//Private display attributes
private:
  Geometric                   *_front[3];
  std::vector<std::string>    _itemsName;

private:
   void                       setupDisplay();
   void                       setupItemsCredits();

private:
  void                        updateContext();

public:
  void                        launch();
  stateUI                     handlerEvent();
};

#endif /* end of include guard: _CREDITSUI_HH_ */
