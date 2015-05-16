//
// Board.cpp for Bomberman in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Wed May  6 13:21:36 2015 Jean-Baptiste Grégoire
// Last update Wed May 13 15:48:19 2015 Jean-Baptiste Grégoire
//

#include "Board.hh"

Board::Board(size_t xLength, size_t yLength) : _xLength(xLength), _yLength(yLength)
{

}

// bool	Board::placeEntity(size_t x, size_t y, char entity)
// {
//   int	to = y * _xLength + x;

//   if (_board[to] == Board_EMPTY_CHAR)
//     {
//       _board[to] = entity;
//       return (true);
//     }
//   return (false);
// }

// bool	Board::moveEntity(size_t x, size_t y, Direction dir)
// {
//   int	from = y * _xLength + x;
//   int	to;
//   char	c;

//   switch (dir)
//     {
//     case North:
//       if (y > 0)
//         to = from - _yLength;
//       else
//         to = -1;
//     case South:
//       if (y < _yLength)
//         to = from + _yLength;
//       else
//         to = -1;
//     case East:
//       if (x > 0)
//         to = from - 1;
//       else
//         to = -1;
//     case West:
//       if (x < _xLength)
//         to = from + 1;
//       else
//         to = -1;
//     default: return(false);
//     }
//   if (to == -1)
//     return (false);
//   c = _Board[from];
//   _Board[from] = Board_EMPTY_CHAR;
//   _Board[to] = c;
//   return (true);
// }

Board::~Board()
{

}
