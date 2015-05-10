//
// EThread.hh for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Wed May  6 17:12:20 2015 David Tran
// Last update Sat May  9 09:09:49 2015 Milox Thomas
//

#ifndef ETHREAD_HH_
# define ETHREAD_HH_

# include <pthread.h>
# include <stdlib.h>
# include "Core.hh"

class	Core;

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

#endif // !ETHREAD_HH_
