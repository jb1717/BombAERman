//
// Settings.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/engine/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat Jun 13 08:10:30 2015 TommyStarK
// Last update Sun Jun 14 04:50:31 2015 TommyStarK
//

#ifndef _SETTINGS_HH
# define _SETTINGS_HH

# include <vector>
# include <string>

class                   Settings
{
public:
    ~Settings();
    static Settings         &instance();


//@Window Parameters
private:
  int                       _width;
  int                       _height;
  std::string               _windowName;

//@IG
private:
  bool                      _antiAliasing;
  float                     _gameVolum;
  float                     _fxVolum;
  std::vector<std::string>  _ia;


private:
    Settings();


// @SETTERS
public:
  void                      setAntiAliasing(bool);
  void                      setGameVolum(int);
  void                      setFxVolum(int);
  void                      setWidth(int);
  void                      setHeight(int);
  void                      setWindowName(const std::string &);
  void                      addIa(const std::string &);

//@GETTERS
public:
  int                       getWidth() const;
  int                       getHeight() const;
  bool                      getAntiAliasing() const;
  float                     getGameVolum() const;
  float                     getFxVolum() const;
  std::string               getWindowName() const;
  std::vector<std::string>  *getIas();

};

#endif /* end of include guard: _SETTINGS_HH */
