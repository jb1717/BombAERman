//
// PlayUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 17:32:15 2015 TommyStarK
// Last update Mon Jun  1 09:47:18 2015 Emmanuel Chambon
//

#ifndef  _PLAYUI_HH_
# define _PLAYUI_HH_

# include <dirent.h>
# include <string>
# include <vector>
# include "AUI.hh"

class             PlayUI : public AUI
{
public:
  PlayUI();
  ~PlayUI();

public:
  void            launch();
  stateUI         handlerEvent();
  void            getIaNames();

private:
  std::vector<std::string>    _iaNames;

};

#endif /* end of include guard: _PLAYUI_HH_ */
