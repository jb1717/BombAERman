//
// ECondVar.cpp<2> for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Mon May 18 19:17:14 2015 David Tran
// Last update Mon May 18 19:17:23 2015 David Tran
//

#include "ECondVar.hh"

ECondVar::ECondVar()
{
  if (pthread_cond_init(&_cond, NULL) != 0)
    throw ;
}

void  ECondVar::wakeUp(enum Target)
{
  if (BROADCAST)
    pthread_cond_broadcast(&_cond);
  else
    pthread_cond_signal(&_cond);
}

void	ECondVar::sleep(int sec)
{
  if (sec)
  {
    struct timespec t = {sec, 0};

    pthread_cond_timedwait(&_cond, _mutex.getMutex(), &t);
  }
  else
    pthread_cond_wait(&_cond, _mutex.getMutex());
}

ECondVar::~ECondVar()
{
  if (pthread_cond_destroy(&_cond) != 0)
    throw ;
}
