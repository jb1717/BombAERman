//
// PauseUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 03:48:16 2015 TommyStarK
// Last update Fri Jun 12 22:23:18 2015 TommyStarK
//

#ifndef _PAUSEUI_HH_
# define _PAUSEUI_HH_

# include <iostream>
# include "AUI.hh"

class           PauseUI : public AUI
{
public:
  PauseUI();
  ~PauseUI();

private:
  void          updateContext();

public:
  void          launch();
  stateUI       handlerEvent();

  };

#endif /* end of include guard: _PAUSEUI_HH_ */
