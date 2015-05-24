//
// AButtons.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/engine/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Wed May 20 18:02:41 2015 TommyStarK
// Last update Sat May 23 05:48:37 2015 TommyStarK
//

#ifndef  _ABUTTONS_HH_
# define _ABUTTONS_HH_

# include <tuple>
# include <string>
# include <functional>
# include "Input.hh"
# include	"graphics.hh"
# include "SDL_keycode.h"

class AButtons : public gdl::Input
{

public:
  AButtons();
  ~AButtons();

public:
  enum Keys {UP, DOWN, ENTER, ESC, NONE, OTHER};

private:
  std::string                   _name;
  glm::vec3                     _position;
  gdl::Texture                  *_texture;

public:
  void                           setPosition(float, float, float);
  const std::string              &getButtonName() const;
  std::tuple<bool, enum Keys>    checkInput();
  virtual void                   launch() = 0;

};

#endif /* end of include guard: _ABUTTONS_HH_ */
