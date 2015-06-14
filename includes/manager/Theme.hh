//
// Theme.hh for Bomberman in /home/chambo_e/epitech/cpp_bomberman/includes/manager/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Sat May 23 02:03:11 2015 Emmanuel Chambon
// Last update Sun Jun 14 02:51:05 2015 Emmanuel Chambon
//

#pragma once
#ifndef THEME_HH_
#define THEME_HH_

#include <string>
#include <map>
#include <iostream>
#include <memory>
#include <mutex>
#include <vector>
#include <dirent.h>
#include <regex>
#include "graphics.hh"

class Theme
{
public:
    Theme(std::string const &, std::string const &);

public:
    gdl::Texture                *operator[](std::string const &);
    std::vector<std::string>    getTextures() const;

private:
    void                        load(std::string const &);
    void                        loadTheme(std::string const &);

private:
    std::map<std::string, std::shared_ptr<gdl::Texture>>       _textures;
    std::mutex                                                 _mutex;
    std::string                                                _name;
};

#endif
