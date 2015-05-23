//
// Theme.hh for Bomberman in /home/chambo_e/epitech/cpp_bomberman/includes/engine/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Fri May 22 18:05:32 2015 Emmanuel Chambon
// Last update Sat May 23 19:37:28 2015 Emmanuel Chambon
//

#ifndef THEMEHANDLER_HH_
#define THEMEHANDLER_HH_

#include <map>
#include <string>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <mutex>
#include <future>
#include <vector>
#include <dirent.h>
#include "AAsset.hh"
#include "Theme.hh"

class ThemeHandler : public AAsset
{
public:
    ThemeHandler();
    ~ThemeHandler();

public:
    void                        load(std::initializer_list<std::initializer_list<std::string>> const &);
    void                        loadTheme(std::string const &, std::string const &);

private:
    void                        load();

public:
    std::shared_ptr<Theme>      operator[](std::string const &);
    std::shared_ptr<Theme>      operator[](ssize_t);

private:
    std::map<std::string, std::shared_ptr<Theme>>         _themes;
    std::mutex                           _mutex;
};

#endif
