//
// Settings.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat Jun 13 08:09:46 2015 TommyStarK
// Last update Sat Jun 13 10:27:31 2015 TommyStarK
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

int                       Settings::getGameVolum() const
{
  return _gameVolum;
}

int                       Settings::getFxVolum() const
{
  return _fxVolum;
}

bool                      Settings::getAntiAliasing() const
{
  return _antiAliasing;
}
