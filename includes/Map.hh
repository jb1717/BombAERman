//
// Map.hh for Bomberman in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Wed May  6 13:22:05 2015 Jean-Baptiste Grégoire
// Last update Wed May 13 21:34:49 2015 Jean-Baptiste Grégoire
//

#ifndef MAP_HH_
# define MAP_HH_

# include <string>


# define MAP_EMPTY_CHAR	'o'

class		Map
{
public:
  enum Direction
    {
      North = 0, West, South, East
    };

public:
  Map(size_t length, size_t width);
  bool	placeEntity(size_t x, size_t y, char entity);
  bool	moveEntity(size_t x, size_t y, Direction dir);
  ~Map();

private:
  std::string	_map;
  size_t	_xLength;
  size_t	_yLength;
};

#endif // !MAP_HH_
