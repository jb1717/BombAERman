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

#ifndef BOARDHANDLER_HH_
#define BOARDHANDLER_HH_

#include <vector>
#include <random>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <dirent.h>
#include <future>
#include <mutex>
#include "AObj.hh"
#include "Board.hh"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"

class BoardHandler
{
public:
    BoardHandler();
    ~BoardHandler() {}

public:
    // Public typedefs
    struct  board_t
    {
        std::string             name;
        std::string             thumbnail;
        std::shared_ptr<Board>  board;
    };

public:
    // Public functions
    void                                        save(std::shared_ptr<Board> const&, std::string const &name) const;
    void                                        generate(int = 42, int = 42);
    void                                        loadOnce(std::string const &);

public:
    // Public accessors
    std::shared_ptr<Board>                      operator[](ssize_t);
    BoardHandler::board_t                       at(ssize_t);
    std::vector<BoardHandler::board_t>          getBoards() const;

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
