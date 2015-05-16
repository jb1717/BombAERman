//
// main.cpp for  in /home/Jamais/Labo
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Fri May 15 21:29:13 2015 Jamais
// Last update Sun May 17 00:45:02 2015 Jamais
//

#include <cstdlib>
#include "GameEngine.hh"

int	main()
{
// On cree son engine
GameEngine engine;
if (engine.initialize() == false)
  {
    std::cerr << "ini" << std::endl;
    return (EXIT_FAILURE);
  }
while (engine.update() == true)
  engine.draw();
 return EXIT_SUCCESS;
}
