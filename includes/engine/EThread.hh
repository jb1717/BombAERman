//
// EThread.hh for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Wed May  6 17:12:20 2015 David Tran
// Last update Mon May 18 05:06:06 2015 David Tran
//

#ifndef ETHREAD_HH_
# define ETHREAD_HH_

# include <pthread.h>
# include <stdlib.h>
# include "Engine.hh"
# include "Bomb.hh"

class	Engine;
class	Bomb;

class	EThread
{
public:
  EThread();
  ~EThread();
public:
  int	launch(void *(*ptr)(void *), void *arg);
  bool	is_running() const;
  int	waitThread();
private:
  pthread_t	_thread;
  bool		_running;
};

void	*launch_player(void *);
void	*run_bomb(void *);

#endif // !ETHREAD_HH_
