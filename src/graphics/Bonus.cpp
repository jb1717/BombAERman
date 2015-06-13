//
// Bonus.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Fri Jun 12 23:12:39 2015 Jamais
// Last update Sat Jun 13 05:26:11 2015 Jamais
//

#include	"Bonus.hh"

Bonus::Bonus() :  AGameModel()
{
}

Bonus::Bonus(glm::vec3 const& position) : AGameModel()
{
  _position = position;
}

void		Bonus::update(gdl::Clock const& clock, UNUSED Binput& input)
{
  _rotation.y += 0.01;
}

Bonus::~Bonus(){}
