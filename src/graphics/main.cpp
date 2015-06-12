//
// main.cpp for  in /home/Jamais/Labo
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Fri May 15 21:29:13 2015 Jamais
// Last update Fri Jun 12 08:48:13 2015 Jamais
//

#include        <cstdlib>
#include        "GameEngine.hh"
#include        "Camera.hh"
#include        "AssetManager.hh"
#include        "Crate.hh"
#include        "UnbreakableWall.hh"
#include        "Player.hh"

std::ostream&	operator<<(std::ostream& os, glm::vec3 const& v)
{
  os << " {" << v.x << ", " << v.y << ", " << v.z << "}";
  return os;
}

int     main()
{
  VideoContext::instanciate()->init();
  auto asset = AssetManager::instance();
  GameEngine engine;

  Board *board = BOARD((*BOARD_HANDLER(asset["boards"]))[0]);

  board->initialize();
  board->initGameObjects();

  if (engine.setupGame(board) == false)
    {
      std::cout << "Couldn't load the map." << std::endl;
      return false;
    }
  if (engine.initialize() == false)
    {
      std::cerr << "ini" << std::endl;
      return (EXIT_FAILURE);
    }
  while (engine.update() == true)
    engine.draw();
  return EXIT_SUCCESS;
}
