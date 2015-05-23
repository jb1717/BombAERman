//
// Theme.hh for Bomberman in /home/chambo_e/epitech/cpp_bomberman/includes/manager/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Sat May 23 02:03:11 2015 Emmanuel Chambon
// Last update Sat May 23 19:22:37 2015 Emmanuel Chambon
//


#ifndef THEME_HH_
#define THEME_HH_

#include <string>
#include <map>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <mutex>
#include <future>
#include <vector>
#include <dirent.h>
#include <regex>
#include "graphics.hh"

class Theme
{
public:
    Theme();
    Theme(std::string const &, std::string const &);
    ~Theme();

public:
    // gdl::Texture        *operator[](std::string const &);

private:
    void                load(std::string const &);
    void                loadTheme(std::string const &);

private:
    std::map<std::string, gdl::Texture *>       _textures;
    std::mutex                                  _mutex;
    std::string                                 _name;
};

#endif
