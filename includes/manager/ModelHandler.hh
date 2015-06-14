//
// Theme.hh for Bomberman in /home/chambo_e/epitech/cpp_bomberman/includes/engine/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Fri May 22 18:05:32 2015 Emmanuel Chambon
// Last update Sun Jun 14 02:40:40 2015 Emmanuel Chambon
//

#pragma once
#ifndef MODELHANDLER_HH_
#define MODELHANDLER_HH_

#include "AGameModel.hh"
#include "AAsset.hh"
#include "VideoContext.hh"

/*
** No async on this loader because of conflicts with the GDL
*/

class ModelHandler : public AAsset
{
public:
    ModelHandler();

private:
    void                        load();
    void                        loadModel(std::string const &, std::string const &);

public:
    AGameModel                  &operator[](std::string const &);

private:
    std::map<std::string, std::shared_ptr<AGameModel>>    _models;
    std::shared_ptr<VideoContext>                         _videoContext;
};

#endif
