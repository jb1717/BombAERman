//
// Event.cpp for Bomberman in /home/jibb/rendu/cpp_bomberman/src/bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Tue Jun  9 16:16:03 2015 Jean-Baptiste Grégoire
// Last update Tue Jun  9 16:22:26 2015 Jean-Baptiste Grégoire
//

#include "Event.hh"

bomber::Event	&bomber::Event::operator=(bomber::Event const &o)
{
  type = o.type;
  key = o.key;
  value = o.value;
  return (*this);
}
