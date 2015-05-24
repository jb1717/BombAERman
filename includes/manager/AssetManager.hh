//
// AssetManager.hh for Bomberman in /home/chambo_e/epitech/cpp_bomberman/includes/engine/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Fri May 22 18:05:32 2015 Emmanuel Chambon
// Last update Sun May 24 10:41:57 2015 Emmanuel Chambon
//

#pragma once
#ifndef ASSETMANAGER_HH_
#define  ASSETMANAGER_HH_

#include <map>
#include <string>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <future>
#include <mutex>
#include "AAsset.hh"
#include "BoardHandler.hh"
#include "ThemeHandler.hh"
#include "SoundHandler.hh"

#define THEME_HANDLER(x)	reinterpret_cast<ThemeHandler *>(&x)
#define THEME(x) 			reinterpret_cast<Theme *>(&x)
#define TEXTURE(x) 			reinterpret_cast<gdl::Texture *>(&x)
#define BOARD_HANDLER(x)	reinterpret_cast<BoardHandler *>(&x)
#define BOARD(x)			reinterpret_cast<Board *>(&x)
#define SOUND_HANDLER(x)	reinterpret_cast<SoundHandler *>(&x)

class AssetManager
{
public:
    AssetManager();
    ~AssetManager ();
    AssetManager(const AssetManager&) {};
public:
    AAsset                  &operator[](std::string const &);

private:
    void                    loadBoardHandler();
    void                    loadThemeHandler();
    void                    loadSoundHandler();

private:
    std::map<std::string, std::shared_ptr<AAsset>>         _assets;
    mutable std::mutex                                     _mutex;
};

#endif
