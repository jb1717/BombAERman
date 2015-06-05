//
// Theme.hh for Bomberman in /home/chambo_e/epitech/cpp_bomberman/includes/engine/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Fri May 22 18:05:32 2015 Emmanuel Chambon
// Last update Fri Jun  5 07:57:51 2015 Jamais
//

#pragma once
#ifndef MODELHANDLER_HH_
#define MODELHANDLER_HH_

#include <memory>
#include <mutex>
#include <iostream>
#include <future>
#include <vector>
#include <regex>
#include <dirent.h>
#include "AGameModel.hh"
#include "AAsset.hh"
#include "VideoContext.hh"

extern VideoContext *V;

class ModelHandler : public AAsset
{
public:
    ModelHandler();
    ~ModelHandler();

private:
    void                        load();
    void                        loadModel(std::string const &, std::string const &);

public:
    AGameModel                  &operator[](std::string const &);

private:
    std::map<std::string, std::shared_ptr<AGameModel>>    _models;
    std::mutex                                            _mutex;
    VideoContext                                          *_videoContext;
};

#endif
