//
// PlayUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 17:32:15 2015 TommyStarK
// Last update Sun May 24 18:01:07 2015 TommyStarK
//

#ifndef  _PLAYUI_HH_
# define _PLAYUI_HH_

# include "AUI.hh"

class             PlayUI : public AUI
{
public:
  PlayUI();
  ~PlayUI();

public:
  void            launch();
  stateUI         handlerEvent();

};

#endif /* end of include guard: _PLAYUI_HH_ */
