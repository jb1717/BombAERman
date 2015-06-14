//
// AssetManager.hh for Bomberman in /home/chambo_e/epitech/cpp_bomberman/includes/engine/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Fri May 22 18:05:32 2015 Emmanuel Chambon
// Last update Sun Jun 14 02:37:22 2015 Emmanuel Chambon
//

#pragma once
#ifndef ASSETMANAGER_HH_
#define  ASSETMANAGER_HH_

#include "AAsset.hh"
#include "BoardHandler.hh"
#include "ThemeHandler.hh"
#include "SoundHandler.hh"
#include "ScoreHandler.hh"
#include "ModelHandler.hh"
#include "SaveHandler.hh"

#define THEME_HANDLER(x)	reinterpret_cast<ThemeHandler *>(&x)
#define BOARD_HANDLER(x)	reinterpret_cast<BoardHandler *>(&x)
#define SOUND_HANDLER(x)	reinterpret_cast<SoundHandler *>(&x)
#define MODEL_HANDLER(x)	reinterpret_cast<ModelHandler *>(&x)
#define THEME(x) 			reinterpret_cast<Theme *>(&x)
#define TEXTURE(x) 			reinterpret_cast<gdl::Texture *>(&x)
#define BOARD(x)			reinterpret_cast<Board *>(&x)

class AssetManager
{
public:
    static AssetManager     &instance();

private:
    AssetManager();

public:
    AAsset                  &operator[](std::string const &);

private:
    void                    loadBoardHandler();
    void                    loadThemeHandler();
    void                    loadSoundHandler();
    void                    loadScoreHandler();
    void                    loadModelHandler();
    void                    loadSaveHandler();

private:
    std::shared_ptr<std::mutex>                            _mutex;
    std::map<std::string, std::shared_ptr<AAsset>>         _assets;
};

#endif
