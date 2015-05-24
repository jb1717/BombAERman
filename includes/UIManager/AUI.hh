//
// AUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 22:57:54 2015 TommyStarK
// Last update Sat May 23 23:51:13 2015 TommyStarK
//

#ifndef  _AUI_HH_
# define _AUI_HH_

# include <string>

class           AUI
{
public:
  virtual ~AUI() {};

public:
  enum TypeUI {LAUNCHER, SETTINGS, LOAD, SAVE, CREDITS};

protected:
  bool          _isRunning;
  std::string   _name;
  AUI::TypeUI   _type;

public:
  void          setName(const std::string &);
  std::string   getName() const;
  AUI::TypeUI   getType() const;

public:
  virtual void  launch() = 0;
  virtual void  handlerEvent() = 0;

};

#endif /* end of include guard: _AUI_HH_ */
