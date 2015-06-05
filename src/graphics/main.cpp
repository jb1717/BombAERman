//
// main.cpp for  in /home/Jamais/Labo
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Fri May 15 21:29:13 2015 Jamais
// Last update Fri Jun  5 19:16:13 2015 Jamais
//

#include	<cstdlib>
#include	"GameEngine.hh"
#include	"Camera.hh"
#include	"AssetManager.hh"


int	main()
{
  V = VideoContext::instanciate();
  V->init();
  AssetManager::instance();


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
