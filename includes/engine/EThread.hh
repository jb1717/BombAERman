//
// EThread.hh for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Wed May  6 17:12:20 2015 David Tran
// Last update Mon May 18 19:44:39 2015 David Tran
//

#ifndef ETHREAD_HH_
# define ETHREAD_HH_

# include <pthread.h>
# include <stdlib.h>

# define NO_TIMEOUT 0

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

# include "Engine.hh"
# include "Bomb.hh"

void	*launch_player(void *);
void	*run_bomb(void *);

#endif // !ETHREAD_HH_
