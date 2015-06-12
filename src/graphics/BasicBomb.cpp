//
// BasicBomb.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Wed May 20 21:14:53 2015 Jamais
// Last update Fri Jun 12 04:20:12 2015 Jamais
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

void		BasicBomb::update(gdl::Clock const& clock, UNUSED Binput& input)
{
  static		int i = 1;

  ABomb::update(clock, input);
  _color.r += 0.05f * i;
  if (_color.r < 0.0f || _color.r >= 1.0f)
    i *= -1;
}
