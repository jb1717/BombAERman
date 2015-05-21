//
// LauncherUI.hpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/engine/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Wed May 20 19:56:53 2015 TommyStarK
// Last update Wed May 20 21:40:32 2015 TommyStarK
//


#ifndef  _LAUNCHERUI_HPP_
#define _LAUNCHERUI_HPP_

# include "Bomberman.hh"
# include "AUI.hpp"

class LauncherUI : public AUI
{
public:
  LauncherUI(VideoContext &, int x = 1920, int y = 1080);
  ~LauncherUI();

private:
  enum Welcome {PLAY, SETTINGS, QUIT};

private:
  int                 _x, _y;
  int                 _select;
  bool                _run;
  VideoContext        &_win;

public:
  void                loop();

};

#endif /* end of include guard: _LAUNCHERUI_HPP_ */
