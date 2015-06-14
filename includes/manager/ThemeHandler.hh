//
// Theme.hh for Bomberman in /home/chambo_e/epitech/cpp_bomberman/includes/engine/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Fri May 22 18:05:32 2015 Emmanuel Chambon
// Last update Sun Jun 14 02:54:02 2015 Emmanuel Chambon
//

#pragma once
#ifndef THEMEHANDLER_HH_
#define THEMEHANDLER_HH_

#include "AAsset.hh"
#include "Theme.hh"

class ThemeHandler : public AAsset
{
public:
    ThemeHandler();

public:
    void                        loadTheme(std::string const &, std::string const &);
    std::vector<std::string>    getThemes() const;

private:
    void                        load();

public:
    Theme                       &operator[](std::string const &);
    Theme                       &operator[](long int);

private:
    std::map<std::string, std::shared_ptr<Theme>>         _themes;
    std::mutex                                            _mutex;
};

#endif
