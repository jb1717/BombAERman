//
// test.cpp for test in /home/paasch_j/cpp_bomberman
//
// Made by Johan Paasche
// Login   <paasch_j@epitech.net>
//
// Started on  Mon Apr 27 11:47:41 2015 Johan Paasche
// Last update Mon Apr 27 23:46:03 2015 Johan Paasche
//

#include	"bomberman.hh"
#include	<time.h>
#include	<unistd.h>

bool		helloWorld()
{
  gdl::SdlContext	_context;
  gdl::Texture		_texture;

  _context.start(500, 500, "Bomberman");

  sleep(1);
  std::cout << "Hello, World !" << std::endl;
  return (true);
}
