//
// main.cpp for  in /home/Jamais/Labo
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Fri May 15 21:29:13 2015 Jamais
// Last update Fri Jun 12 02:27:06 2015 Emmanuel Chambon
//

#include        <cstdlib>
#include        "GameEngine.hh"
#include        "Camera.hh"
#include        "AssetManager.hh"
#include        "Crate.hh"
#include        "UnbreakableWall.hh"
#include        "Player.hh"

int     main()
{
  VideoContext::instanciate()->init();
  auto asset = AssetManager::instance();
  GameEngine engine;

  Board *board = BOARD((*BOARD_HANDLER(asset["boards"]))[0]);

  board->initialize();
  board->initGameObjects();

  if (engine.initialize() == false)
    {
      std::cerr << "ini" << std::endl;
      return (EXIT_FAILURE);
    }
  if (engine.setupGame(board) == false)
    {
      std::cout << "Couldn't load the map." << std::endl;
      return false;
    }
  while (engine.update() == true)
    engine.draw();
  return EXIT_SUCCESS;
}
