//
// main.cpp for  in /home/Jamais/Labo
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Fri May 15 21:29:13 2015 Jamais
// Last update Sat Jun  6 01:38:41 2015 Jamais
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
  Board*       	board = new Board(10, 10);

  video = VideoContext::instanciate();
  video->init();

  for (int x = 0; x < 10; x++)
    {
      for (int y = 0; y < 10; y++)
	{
	  /* placing character in 1 / 1 */
	  if (x == y  && x == 1)
	    board->placeEntity(x, y, new Player(*board));
	  if (((x % 3 == 0) &&  (y % 3 == 0)) || (x == 0 || y == 0 || x == 9 || y == 9))
	  board->placeEntity(x, y, new Crate(*board));
	  board->placeEntity(x, y, new UnbreakableWall(*board));
	}
    }

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
