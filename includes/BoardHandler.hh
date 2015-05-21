//
// BoardHandler.hh for Bomberman in /home/chambo_e/epitech/cpp_bomberman/includes/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Wed May 20 15:53:00 2015 Emmanuel Chambon
// Last update Wed May 20 20:57:12 2015 Emmanuel Chambon
//

#ifndef BOARDHANDLER_HH_
# define BOARDHANDLER_HH_

#include <vector>
#include <random>
#include <iostream>
#include "Board.hh"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/prettywriter.h"

class BoardHandler
{
public:
    BoardHandler(int = 42, int = 42);
    ~BoardHandler() {};

public:
    typedef struct  board_s
    {
        std::string         name;
        std::string         thumbnail;
        Board               *board;
    }               board_t;

public:
    void                    save(Board const &) const;
    void                    generate();
    std::vector<board_t>    getBoards() const;

private:
    std::vector<board_t>       _boards;
    int                      _x, _y;
private:
    void                     load();
};

#endif
