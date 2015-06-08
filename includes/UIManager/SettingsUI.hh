//
// SettingsUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 17:35:33 2015 TommyStarK
// Last update Sun May 24 17:58:06 2015 TommyStarK
//

#ifndef  _SETTINGSUI_HH_
#define _SETTINGSUI_HH_

#include "AUI.hh"

class       SettingsUI : public AUI
{
public:
  SettingsUI();
  ~SettingsUI();

public:
  void       launch();
  stateUI    handlerEvent();
};

#endif /* end of include guard: _SETTINGSUI_HH_ */
