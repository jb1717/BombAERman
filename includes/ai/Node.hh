//
// Ia.hh for Bomberman in /home/patoche/rendu/CPP/cpp_bomberman
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Mon May 18 15:12:42 2015 Hugo Prenat
// Last update Sat Jun 13 14:32:42 2015 Hugo Prenat
//

#ifndef NODE_HH_
# define NODE_HH_

# include <cmath>

class					Node
{
public:
  Node();
  ~Node();

public:
  float					dist(int x1, int y1, int x2, int y2);

private:
};

#endif // !NODE_HH_
