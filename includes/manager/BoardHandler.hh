//

// BoardHandler.hh for Bomberman in
// /home/chambo_e/epitech/cpp_bomberman/includes/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Wed May 20 15:53:00 2015 Emmanuel Chambon
// Last update Wed May 20 20:57:12 2015 Emmanuel Chambon
//

#pragma once
#ifndef BOARDHANDLER_HH_
#define BOARDHANDLER_HH_

#include "AObj.hh"
#include "Board.hh"
#include "AAsset.hh"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"

class BoardHandler : public AAsset
{
public:
    BoardHandler();

public:
    // Public typedefs
    typedef struct              board_s
    {
        std::string             name;
        std::string             thumbnail;
        std::shared_ptr<Board>  board;
    }                           board_t;

public:
    // Public functions
    void                                        save(std::shared_ptr<Board> const&, std::string const &) const;
    void                                        generate(int = 42, int = 42);
    void                                        load(std::string const &);

public:
    // Public accessors
    Board                                       &operator[](long int) const;
    Board                                       &operator[](std::string const &) const;
    BoardHandler::board_t                       at(long int) const;
    std::vector<BoardHandler::board_t>          getBoards() const;
    std::vector<std::string>                    getBoardsNames() const;

private:
    // Private functions
    void                                        load();
    void                                        loadBoard(std::string const &);
    std::shared_ptr<Board>                      loadMap(rapidjson::Value const &, int, int);

private:
    // Private variables
    std::vector<board_t>                        _boards;
    std::mutex                                  _mutex;
};

#endif // BOARDHANDLER_HH_
