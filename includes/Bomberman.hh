//

// bomberman.hh for CPP_BOMBERMAN in /home/paasch_j/cpp_bomberman
//
// Made by Johan Paasche
// Login   <paasch_j@epitech.net>
//
// Started on  Mon Apr 27 14:05:58 2015 Johan Paasche
// Last update Tue May 19 11:35:07 2015 Emmanuel Chambon
//

#ifndef ___BOMBERMAN_HH___
#define ___BOMBERMAN_HH___

# include   <regex>
# include   <thread>
# include   <chrono>
# include   <stdexcept>
# include   "Score.hh"
# include   "basics.hh"
# include   "LauncherUI.hh"
# include   "manager/AssetManager.hh"
# include   "gameEngine/graphics.hh"
# include   "gameEngine/VideoContext.hh"

class Bomberman
{
public:

  Bomberman();
  ~Bomberman();

private:

  void setWidthHeight();

private:
  int                       _x, _y;
  Score                     *_score;
  LauncherUI                *_ui;

};

#endif /* !___BOMBERMAN_HH___ */
