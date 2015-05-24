//
// SoundHandler.hh for Bomberman in /home/chambo_e/epitech/cpp_bomberman/includes/manager/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Sun May 24 08:35:43 2015 Emmanuel Chambon
// Last update Sun May 24 17:58:12 2015 Emmanuel Chambon
//

#pragma once
#ifndef SOUNDHANDLER_HH_
#define SOUNDHANDLER_HH_

#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <future>
#include <mutex>
#include <regex>
#include <dirent.h>
#include "manager/AAsset.hh"
#include "fmod/fmod.hpp"

class SoundHandler : public AAsset
{
public:
    SoundHandler();
    ~SoundHandler();

public:
    void                        setBackgroundVolume(float);
    void                        setForegroundVolume(float);
    void                        pause();
    void                        resume();
    void                        stop();
    void                        play(FMOD::Sound *);
    void                        playSample(FMOD::Sound *);
    bool                        isPlaying();
    FMOD::Sound                 *operator[](std::string const&);

private:
    void                        fmodError(FMOD_RESULT);
    void                        load();
    void                        loadSound(std::string const &);

private:
    FMOD::System                                *_system;
    std::map<std::string, FMOD::Sound *>        _sounds;
    std::mutex                                  _mutex;
    FMOD::Channel                               *_channel = 0;
    FMOD::Channel                               *_channelSample = 0;
    float                                       _foregroundVolume = 1.0;
    float                                       _backgroundVolume = 0.5;
};

#endif
