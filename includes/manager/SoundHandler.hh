//
// SoundHandler.hh for Bomberman in /home/chambo_e/epitech/cpp_bomberman/includes/manager/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Sun May 24 08:35:43 2015 Emmanuel Chambon
// Last update Sun Jun 14 14:48:22 2015 Jamais
//

#pragma once
#ifndef SOUNDHANDLER_HH_
#define SOUNDHANDLER_HH_

#include <map>

#include "AAsset.hh"
#include "fmod/fmod.hpp"
/*
** /!\ Unable to use smart pointers due to fmod API
*/

class SoundHandler : public AAsset
{
public:
    SoundHandler();
    ~SoundHandler();

public:
    void                        setBackgroundVolume(float);
    void                        setForegroundVolume(float);
    void                        pause() const;
    void                        resume() const;
    void                        stop() const;
    void                        play(std::string const &, bool = false, bool = true);
    bool                        isPlaying() const;
    FMOD::Sound                 *operator[](std::string const&);

private:
    void                        fmodError(FMOD_RESULT) const;
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
