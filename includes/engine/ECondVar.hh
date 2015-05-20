//
// ECondVar.hh for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Mon May 18 19:13:51 2015 David Tran
// Last update Mon May 18 19:25:40 2015 David Tran
//

#ifndef ECONDVAR_HH
# define ECONDVAR_HH

# include <iostream>
# include <string>
# include <pthread.h>
# include <time.h>
# include "EMutex.hh"

class ECondVar
{
public:
  ECondVar();
  ~ECondVar();
public:
  enum	Target
  {
    ONE = 0,
    BROADCAST
  };

  void	sleep(int sec);
  void	wakeUp(enum Target);
private:
  EMutex		_mutex;
  pthread_cond_t	_cond;
};

#endif // !ECONDVAR_HH
