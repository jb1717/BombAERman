//
// AUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 22:57:54 2015 TommyStarK
// Last update Sun May 24 17:56:52 2015 TommyStarK
//

#ifndef  _AUI_HH_
# define _AUI_HH_

# include <tuple>
# include <string>
# include <functional>
# include "Binput.hh"
# include "Clock.hh"

typedef std::tuple<bool, std::string>  stateUI;

class               AUI
{
public:
  virtual ~AUI() {};

// private necessary attributes to display & catch events
protected:
  bool              _isRunning;
  std::string       _name;
  gdl::Clock        _clock;
  Binput	        _input;

// to handle different UI by name
public:
  void              setName(const std::string &);
  std::string       getName() const;


public:
  virtual void      launch() = 0;
  virtual stateUI   handlerEvent() = 0;

};

#endif /* end of include guard: _AUI_HH_ */
