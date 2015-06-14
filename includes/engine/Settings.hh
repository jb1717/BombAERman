//
// Settings.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/engine/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat Jun 13 08:10:30 2015 TommyStarK
// Last update Sun Jun 14 20:13:34 2015 TommyStarK
//

#ifndef _SETTINGS_HH
# define _SETTINGS_HH

# include <vector>
# include <string>
# include <iostream>

class                       Settings
{
public:
  ~Settings() {};
  static Settings           &instance();

private:
  Settings() {};

//@Window Parameters
private:
  int                       _width;
  int                       _height;
  std::string               _windowName;

private:
  int                       _playerNbr;
  int                       _iaNbr;
  std::string               _difficulty;
  std::string               _mapName;
  std::string               _loading;

//@IG
private:
  bool                      _antiAliasing;
  float                     _gameVolum;
  float                     _fxVolum;
  std::vector<std::string>  _ia;

// public:
//   static Settings           &instance();

// @SETTERS
public:
  void                      setPlayerNbr(int);
  void                      setIaNbr(int);
  void                      setLoading(const std::string &);
  void                      setDifficulty(const std::string &);
  void                      setMapName(const std::string &);
  void                      setAntiAliasing(bool);
  void                      setGameVolum(int);
  void                      setFxVolum(int);
  void                      setWidth(int);
  void                      setHeight(int);
  void                      setWindowName(const std::string &);
  void                      addIa(const std::string &);

//@GETTERS
public:
  int                       getPlayerNbr() const;
  int                       getIaNbr() const;
  std::string               getLoading() const;
  std::string               getDifficulty() const;
  std::string               getMapName() const;
  int                       getWidth() const;
  int                       getHeight() const;
  bool                      getAntiAliasing() const;
  int                       getGameVolum() const;
  int                       getFxVolum() const;
  std::string               getWindowName() const;
  std::vector<std::string>  getIas();

};

#endif /* end of include guard: _SETTINGS_HH */
