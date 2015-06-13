//
// Settings.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/engine/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat Jun 13 08:10:30 2015 TommyStarK
// Last update Sat Jun 13 12:14:27 2015 TommyStarK
//

#ifndef _SETTINGS_HH
# define _SETTINGS_HH

class                   Settings
{
public:
    ~Settings();
    static Settings     &instance();

private:
  int                   _gameVolum;
  int                   _fxVolum;
  bool                  _antiAliasing;

private:
    Settings();

public:
  void                  setAntiAliasing(bool);
  void                  setGameVolum(int);
  void                  setFxVolum(int);

public:
    int                 getGameVolum() const;
    int                 getFxVolum() const;
    bool                getAntiAliasing() const;

};

#endif /* end of include guard: _SETTINGS_HH */
