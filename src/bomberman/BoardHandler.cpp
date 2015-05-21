//
// BoardHandler.cpp for Bomberman in /home/chambo_e/epitech/cpp_bomberman/src/bomberman/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Wed May 20 15:53:08 2015 Emmanuel Chambon
// Last update Wed May 20 21:43:23 2015 Emmanuel Chambon
//

#include "BoardHandler.hh"

BoardHandler::BoardHandler(int x, int y) : _x(x), _y(y)
{
    generate();
    load();
}

void                BoardHandler::save(Board const &board) const
{

}

void                BoardHandler::generate()
{
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution<int> dist(CRATE, END);
    board_t         board;

    board.name = "Random";
    board.thumbnail = "./assets/random.jpg";
    board.board = new Board(_x, _y);


    for (int y_ = 0 ; y_ < _y; y_++) {
        for (int x_ = 0; x_ < _x; x_++) {
            board.board->placeEntity((float )x_, (float)y_, static_cast<entityType>(dist(engine)), 0);
        }
    }
    _boards.push_back(board);
}

std::vector<BoardHandler::board_t>  BoardHandler::getBoards() const
{
    return _boards;
}

void                BoardHandler::load()
{

}
