//
// main.cpp for  in /home/Jamais/Labo
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Fri May 15 21:29:13 2015 Jamais
// Last update Sun Jun 14 15:59:51 2015 Jamais
//

#include        <cstdlib>
#include	<pthread.h>
#include	<mutex>
#include	<thread>
#include        "GameEngine.hh"
#include        "Camera.hh"
#include        "AssetManager.hh"
#include        "Crate.hh"
#include        "UnbreakableWall.hh"
#include        "Player.hh"
#include        "Ia.hh"

std::mutex	_mutex;

std::ostream&	operator<<(std::ostream& os, glm::vec3 const& v)
{
  os << " {" << v.x << ", " << v.y << ", " << v.z << "}";
  return os;
}

static void		*launch_play(void *arg)
{
  Player	*corpse = static_cast<Player *>(arg);

  corpse->run_user();
  return (NULL);
}

static void		*launch_ia(void *arg)
{
  Ia	*corpse = static_cast<Ia *>(arg);

  sleep(1);
  corpse->run_user();
  return (NULL);
}

int     main()
{
  VideoContext::instanciate()->init();
  auto asset = AssetManager::instance();
  GameEngine engine;

  Board *board = BOARD((*BOARD_HANDLER(asset["boards"]))[1]);


  board->spawnPlayers(1, 1, "ia/easy.chai");
  board->initialize();
  board->initGameObjects();

  //  SOUND_HANDLER(asset["sounds"])->play("bomberman");

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
  std::thread t1(launch_play, std::ref(board->getPlayers().front()));
  //std::thread t2(launch_play, std::ref(board->getPlayers()[1]));
  std::thread t3(launch_ia, std::ref(board->getPlayers()[1]));
  while (engine.update() == true)
    engine.draw();
  return EXIT_SUCCESS;
}
