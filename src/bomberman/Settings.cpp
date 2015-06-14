//
// Settings.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat Jun 13 08:09:46 2015 TommyStarK
// Last update Sun Jun 14 20:18:02 2015 TommyStarK
//

#include "Settings.hh"

// Settings    Settings::_instance = Settings();

Settings    &Settings::instance()
{
  static Settings *instance = new Settings();
  return *instance;
}


//
//@ SETTERS
//
void                      Settings::setPlayerNbr(int nbr)
{
  _playerNbr = nbr;
}

void                      Settings::setIaNbr(int nbr)
{
  _iaNbr = nbr;
}

void                      Settings::setDifficulty(const std::string &difficulty)
{
  _difficulty = difficulty;
}

void                      Settings::setMapName(const std::string &map)
{
  _mapName = map;
}

void                      Settings::setAntiAliasing(bool AntiAliasing)
{
  _antiAliasing = AntiAliasing;
}

void                      Settings::setGameVolum(int gameVolum)
{
  _gameVolum = gameVolum;
}

void                      Settings::setFxVolum(int fx)
{
  _fxVolum = fx;
}


void                      Settings::addIa(const std::string &ia)
{
  _ia.push_back(ia);
}

void                      Settings::setWidth(int width)
{
  _width = width;
}

void                      Settings::setHeight(int height)
{
  _height = height;
}

void                      Settings::setWindowName(const std::string &name)
{
  _windowName = name;
}

void                      Settings::setLoading(const std::string &loading)
{
  _loading = loading;
}


//
//@ GETTERS
//
int                       Settings::getPlayerNbr() const
{
  return _playerNbr;
}

int                       Settings::getIaNbr() const
{
  return _iaNbr;
}

std::string               Settings::getDifficulty() const
{
  return _difficulty;
}

std::string               Settings::getMapName() const
{
  return _mapName;
}

int                       Settings::getWidth() const
{
  return _width;
}

int                       Settings::getHeight() const
{
  return _height;
}

bool                      Settings::getAntiAliasing() const
{
  return _antiAliasing;
}

int                      Settings::getGameVolum() const
{
  return _gameVolum ;
}

int                      Settings::getFxVolum() const
{
  return _fxVolum;
}

std::string              Settings::getWindowName() const
{
  return _windowName;
}

std::string              Settings::getLoading() const
{
  return _loading;
}

std::vector<std::string>  Settings::getIas()
{
  std::vector<std::string>  tmp;

  for (auto i : _ia)
    tmp.push_back(i);
  return (tmp);
}
