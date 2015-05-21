//
// main.cpp for  in /home/Jamais/Labo
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Fri May 15 21:29:13 2015 Jamais
// Last update Wed May 20 22:13:20 2015 Milox Thomas
//

#include	<cstdlib>
#include	"GameEngine.hh"
#include	"Camera.hh"

int	main()
{
// On cree son engine
GameEngine engine;
if (engine.initialize() == false)
  {
    std::cerr << "ini" << std::endl;
    return (EXIT_FAILURE);
  }
 if (engine.setupGame("./conf/map.conf") == false)
   {
     std::cout << "Couldn't load the map." << std::endl;
     return false;
   }
while (engine.update() == true)
  engine.draw();
 return EXIT_SUCCESS;
}
