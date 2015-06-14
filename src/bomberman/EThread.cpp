//
// EThread.cpp for Bomberman in /home/tran_0/rendu/cpp_bomberman
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Wed May  6 17:11:54 2015 David Tran
// Last update Mon May 18 05:06:23 2015 David Tran
//

#include "EThread.hh"
#include "Ia.hh"

EThread::EThread()
{

}

EThread::~EThread()
{}

int	EThread::launch(void *(*ptr)(void *), void *arg)
{
  if (pthread_create(&_thread, NULL, ptr, arg) != 0)
    {
      _running = false;
      return (EXIT_FAILURE);
    }
  _running = true;
  return (EXIT_SUCCESS);
}

bool	EThread::is_running() const
{
  return (_running);
}

int	EThread::waitThread()
{
  int	wait;

  wait = pthread_join(_thread, NULL);
  _running = false;
  return (wait);
}

int	EThread::kill_Thread()
{
  return (pthread_kill(_thread, SIGINT));
}

void	*launch_play(void *arg)
{
  Player		*newone = reinterpret_cast<Player *>(arg);

  newone->run_user();
  return (NULL);
}

void	*launch_ia(void *arg)
{
  Ia		*corpse = static_cast<Ia *>(arg);

  corpse->run_user();
  return (NULL);
}

void	*run_bomb(void *arg)
{
  Bomb			*bomb = static_cast<Bomb *>(arg);

  bomb->run();
  return (NULL);
}
