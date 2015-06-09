//
// main.cpp for  in /home/Jamais/Labo
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Fri May 15 21:29:13 2015 Jamais
// Last update Tue Jun  9 02:23:37 2015 Jamais
//

#include	<cstdlib>
#include	"GameEngine.hh"
#include	"Camera.hh"
#include	"AssetManager.hh"
#include	"Crate.hh"
#include	"UnbreakableWall.hh"
#include	"Player.hh"

int	main()
{
  VideoContext*	video;
  //  Board*       	board = new Board(11, 11);
  video = VideoContext::instanciate();
  video->init();
  auto		asset = AssetManager::instance();
  auto		boards = BOARD_HANDLER(asset["boards"]);
  auto		board = BOARD((*boards)[0]);

  //  for (int << = -5 ; x < 5; x++)
  // for (int x = 0; x < 11; x++)
  //   {
  //     for (int y = 0; y < 11; y++)
  // 	{
  // 	  /* placing character in 1 / 1 */
  // 	  if (x == 1  && y == 1)
  board->placeEntity(1, 1, new Player(*board));
  // 	  if (((x % 3 == 0) &&  (y % 3 == 0)) || (x == 0 || y == 0 || x == 10 || y == 10))
  // 	  board->placeEntity(x, y, new Crate(*board));
  // 	  board->placeEntity(x, y, new UnbreakableWall(*board));
  // 	}
  //   }
  GameEngine	engine;
  board->initialize();
  board->initGameObjects();

  AssetManager::instance();

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
