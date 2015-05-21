//
// BasicBomb.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Wed May 20 21:14:53 2015 Jamais
// Last update Wed May 20 21:16:46 2015 Jamais
//

#include	"BasicBomb.hh"

BasicBomb::BasicBomb() : ABomb()
{
  load("./assets/Models/PumpkinBomb2.fbx");
  scale(glm::vec3(0.002, 0.002, 0.002));
}

BasicBomb::~BasicBomb()
{

}
