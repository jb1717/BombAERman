//
// main.cpp for  in /home/Jamais/Labo
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Fri May 15 21:29:13 2015 Jamais
// Last update Fri Jun 12 11:11:22 2015 Emmanuel Chambon
//

#include	<cstdlib>
#include	"GameEngine.hh"
#include	"Camera.hh"
#include	"AssetManager.hh"
#include	"Crate.hh"
#include	"UnbreakableWall.hh"
#include	"Player.hh"
#include	"Ia.hh"

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

  Board *board = BOARD((*BOARD_HANDLER(asset["boards"]))[1]);

  board->initialize();
  board->initGameObjects();

  SOUND_HANDLER(asset["sounds"])->play("bomberman");

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
