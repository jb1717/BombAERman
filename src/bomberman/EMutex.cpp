//
// EMutex.cpp for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Thu May  7 18:44:46 2015 David Tran
// Last update Thu May  7 18:54:21 2015 David Tran
//

#include "EMutex.hh"

EMutex::EMutex()
{
  pthread_mutex_init(&_mutex, NULL);
}

EMutex::~EMutex()
{
  pthread_mutex_destroy(&_mutex);
}

int	EMutex::lock()
{
  return (pthread_mutex_lock(&_mutex));
}

int	EMutex::trylock()
{
  return (pthread_mutex_trylock(&_mutex));
}

int	EMutex::unlock()
{
  return (pthread_mutex_trylock(&_mutex));
}

pthread_mutex_t	*EMutex::getMutex()
{
  return (&_mutex);
}
