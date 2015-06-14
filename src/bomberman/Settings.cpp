//
// Settings.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat Jun 13 08:09:46 2015 TommyStarK
// Last update Sun Jun 14 04:52:25 2015 TommyStarK
//

#include "Settings.hh"

Settings    &Settings::instance()
{
    static Settings *instance = new Settings();
    return *instance;
}

Settings::Settings()
{

}

Settings::~Settings()
{

}

//
//@ GETTERS
//
void                      Settings::setAntiAliasing(bool AntiAliasing)
{
  _antiAliasing = AntiAliasing;
}

void                      Settings::setGameVolum(int gameVolum)
{
  _gameVolum = gameVolum / 100;
}

void                      Settings::setFxVolum(int fx)
{
  _fxVolum = fx / 100;
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


//
//@ GETTERS
//
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

float                     Settings::getGameVolum() const
{
  return _gameVolum;
}

float                     Settings::getFxVolum() const
{
  return _fxVolum;
}

std::string                Settings::getWindowName() const
{
  return _windowName;
}

std::vector<std::string>  *Settings::getIas()
{
  std::vector<std::string>  *tmp = new std::vector<std::string>;

  for (auto i : _ia)
    tmp->push_back(i);
  return (tmp);
}
