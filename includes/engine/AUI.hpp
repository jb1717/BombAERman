//
// AUI.hpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/engine/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Wed May 20 17:55:45 2015 TommyStarK
// Last update Wed May 20 21:41:02 2015 TommyStarK
//


#ifndef  _AUI_HPP_
# define _AUI_HPP_

# include <vector>
# include "AButtons.hpp"

class                       AUI
{
public:
  AUI();
  ~AUI();

protected:
  std::vector<AButtons *>   _buttons;

public:
  virtual void              loop() const = 0;
};


#endif /* end of include guard: _AUI_HPP_ */
