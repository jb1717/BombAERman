//
// AButtons.hpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/engine/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Wed May 20 18:02:41 2015 TommyStarK
// Last update Wed May 20 21:15:37 2015 TommyStarK
//

#ifndef  _ABUTTONS_HPP_
# define _ABUTTONS_HPP_

# include <tuple>
# include "Input.hh"
# include "SDL_keycode.h"

class AButtons : public gdl::Input
{

public:
  AButtons();
  ~AButtons();

public:
  enum Keys {UP, DOWN, ENTER, ESC, NONE};

public:
  std::tuple<bool, enum Keys>    checkInput();
  virtual void                   launch() = 0;

};

#endif /* end of include guard: _ABUTTONS_HPP_ */
