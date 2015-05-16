//
// EMutex.hh for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Thu May  7 18:44:21 2015 David Tran
// Last update Thu May  7 18:55:00 2015 David Tran
//

#ifndef EMUTEX_HH_
# define EMUTEX_HH_

# include <pthread.h>

class	EMutex
{
public:
  EMutex();
  ~EMutex();
public:
  int			lock();
  int			trylock();
  int			unlock();
  pthread_mutex_t	*getMutex();
private:
  pthread_mutex_t	_mutex;
};

#endif // !EMUTEX_HH_
