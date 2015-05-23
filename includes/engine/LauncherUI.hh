//
// LauncherUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/engine/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Wed May 20 19:56:53 2015 TommyStarK
// Last update Sat May 23 05:54:34 2015 TommyStarK
//


#ifndef  _LAUNCHERUI_HH_
#define _LAUNCHERUI_HH_

# include "AUI.hh"
# include <memory>

class LauncherUI : public AUI
{
public:
  LauncherUI(int, int, const std::string &);
  ~LauncherUI();

private:
  enum Welcome {PLAY, SETTINGS, QUIT};

private:
  int                              _x, _y;
  int                              _select;
  bool                             _run;
  std::string                      _windowTittle;
  std::shared_ptr<VideoContext>    _win;

public:
  void                             loop();
  std::shared_ptr<VideoContext>    getWin();
};

#endif /* end of include guard: _LAUNCHERUI_HH_ */
