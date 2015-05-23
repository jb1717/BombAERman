//
// AssetManager.hh for Bomberman in /home/chambo_e/epitech/cpp_bomberman/includes/engine/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Fri May 22 18:05:32 2015 Emmanuel Chambon
// Last update Sat May 23 19:35:45 2015 Emmanuel Chambon
//

#ifndef ASSETMANAGER_HH_
#define  ASSETMANAGER_HH_

#include <map>
#include <string>
#include <initializer_list>
#include <iostream>
#include <memory>
#include "AAsset.hh"
#include "BoardHandler.hh"
#include "ThemeHandler.hh"

class AssetManager
{
public:
    AssetManager();
    ~AssetManager ();

public:
    std::shared_ptr<AAsset>         operator[](std::string const &);

private:
    std::map<std::string, std::shared_ptr<AAsset>>         _assets;
};

#endif
