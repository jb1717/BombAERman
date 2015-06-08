//
// BasicBomb.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Wed May 20 21:14:53 2015 Jamais
// Last update Thu Jun  4 20:08:00 2015 Jamais
//

#include	"BasicBomb.hh"

BasicBomb::BasicBomb() : ABomb()
{
  load("./assets/models/PumpkinBomb.fbx");
  setCurrentAnim(0);
  scale(glm::vec3(0.002, 0.002, 0.002));
}

BasicBomb::~BasicBomb()
{

}
