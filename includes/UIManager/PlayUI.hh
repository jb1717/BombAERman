//
// PlayUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 17:32:15 2015 TommyStarK
// Last update Fri Jun 12 22:23:16 2015 TommyStarK
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


private:
  std::vector<std::string>    _iaNames;


private:
  void            getIaNames();
  void            updateContext();

public:
  void            launch();
  stateUI         handlerEvent();


};

#endif /* end of include guard: _PLAYUI_HH_ */
