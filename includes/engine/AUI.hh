//
// AUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/engine/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Wed May 20 17:55:45 2015 TommyStarK
// Last update Sat May 23 05:54:58 2015 TommyStarK
//


#ifndef  _AUI_HH_
# define _AUI_HH_

# include <vector>
# include <future>
# include "AButtons.hh"
# include "gameEngine/graphics.hh"
# include "gameEngine/VideoContext.hh"

class                             AUI
{
public:
  AUI();
  ~AUI();

protected:
  std::vector<AButtons *>          _buttons;
  std::vector<std::future<AUI *>>  _links;

public:
  virtual void                     loop() = 0;
  AButtons                         *operator[](const std::string &);
};


#endif /* end of include guard: _AUI_HH_ */
