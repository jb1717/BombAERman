//
// main.cpp for CPP_BOMBERMAN in /home/paasch_j/cpp_bomberman/src/bomberman_src
//
// Made by Johan Paasche
// Login   <paasch_j@epitech.net>
//
// Started on  Mon Apr 27 11:27:27 2015 Johan Paasche
// Last update Wed May 20 21:59:35 2015 Jamais
//

#include	"basics.hh"
#include	"Bomberman.hh"


int	main()
{
  try {
    Bomberman();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
