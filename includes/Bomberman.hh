//
// bomberman.hh for CPP_BOMBERMAN in /home/paasch_j/cpp_bomberman
//
// Made by Johan Paasche
// Login   <paasch_j@epitech.net>
//
// Started on  Mon Apr 27 14:05:58 2015 Johan Paasche
// Last update Tue May 19 11:35:07 2015 Emmanuel Chambon
//

#ifndef     ___BOMBERMAN_HH___
# define    ___BOMBERMAN_HH___

# include   <regex>
# include   "basics.hh"
# include   "BoardHandler.hh"
# include   "gameEngine/graphics.hh"
# include   "gameEngine/VideoContext.hh"

class Bomberman
{
public:
    Bomberman();
    ~Bomberman();

private:
    void                setWidthHeight();
private:
    VideoContext        _window;
    int                 _x = 1820, _y = 1080;
};

#endif      /* !___BOMBERMAN_HH___ */
