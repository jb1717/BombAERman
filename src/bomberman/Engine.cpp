//
// Engine.cpp for Bomberman in /home/tran_0/rendu/cpp_bomberman
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Tue May  5 17:48:04 2015 David Tran
// Last update Fri May 22 01:49:56 2015 Jamais
//

#include "Engine.hh"

Engine::Engine(Board &board) : _board(board), _nbPlay(0), _nbIa(0)
{
}

Engine::~Engine()
{}


Board	&Engine::getBoard() const
{
  return (_board);
}

bool	Engine::initialize(int player, int ia, std::string const &difficulty)
{
  VideoContext::instanciate()->init();
  auto asset = AssetManager::instance();

  _nbPlay = player;
  _nbIa = ia;
  _board.spawnPlayers(player, ia, difficulty);
  _board.initialize();
  _board.initGameObjects();
  return (true);
}

bool	Engine::players_thread()
{
  for (int i = 0; i < _nbPlay ; i++)
    {
      EThread	*newone = new EThread;
      newone->launch(launch_play, _board.getPlayers()[i]);
      _players.push_back(newone);
    }
  for (int i = 0; i < _nbIa ; i++)
    {
      EThread	*newone = new EThread;
      newone->launch(launch_play, _board.getPlayers()[_nbPlay + i]);
      _players.push_back(newone);
    }
  return (true);
}

bool	Engine::checkRealAlive()
{
  if (_nbPlay == 1)
    {
      if (_board.getPlayers().front()->getId() != 1)
	return (false);
    }
  else if (_nbPlay == 2)
    {
      if (_board.getPlayers().front()->getId() != 1 || _board.getPlayers().front()->getId() != 2)
	return (false);
    }
  return (true);
}

bool	Engine::launch_game()
{
  engine = new GameEngine;
  if (engine->setupGame(&_board) == false)
    {
      std::cout << "Couldn't load the map." << std::endl;
      return (false);
    }
  if (engine->initialize() == false)
    {
      std::cerr << "ini" << std::endl;
      return (false);
    }
  if (!players_thread())
    return (false);
  run();
  return (true);
}

void	Engine::run()
{
  while (_board.getPlayers().size() <= 1 && checkRealAlive() && engine->update() == true)
    engine->draw();
  if (_board.getPlayers().size() == 0)
    std::cout << "You Lost... LOOSER" << std::endl;
  else
    {
      if (_nbPlay == 1)
	{
	  if (_board.getPlayers().front()->getId() != 1)
	    std::cout << "You Lost... LOOSER" << std::endl;
	  else
	    std::cout << "Player 1 ! WINS" << std::endl;
	}
      else
	{
	  if (_board.getPlayers().front()->getId() != 1 || _board.getPlayers().front()->getId() != 2)
	    std::cout << "You Lost... LOOSER" << std::endl;
	  else
	    std::cout << "Player " << _board.getPlayers().front()->getId() << " 1 ! WINS" << std::endl;
	}
    }
  for (auto ite = _players.begin() ; ite != _players.end() ; ite++)
    (*ite)->kill_Thread();
}
