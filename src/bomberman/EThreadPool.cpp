//
// EThreadPool.cpp for EThreadPool in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Mon May 18 19:15:36 2015 David Tran
// Last update Mon May 18 19:49:19 2015 David Tran
//

#include "EThreadPool.hh"

EThreadPool::EThreadPool(int nb_thread) : _size(nb_thread), _working(true)
{
  for (int i = 0; i < nb_thread; ++i)
  {
    EThread	*tmp = new EThread;

    if (tmp->launch(thread_start, this) != 0)
      throw std::runtime_error("Can't create threadpool !");
    _threads.push_back(tmp);
  }
}

void		EThreadPool::addWork(void *(*routine)(void *), void *args)
{
  Job	*newJob = new Job;

  newJob->func = routine;
  newJob->args = args;
  _jobs.push(newJob);
  _proc.wakeUp(ECondVar::ONE);
}

void		EThreadPool::stopThePool()
{
  _working = false;
}

void		EThreadPool::pendingFunc()
{
  bool		start = true;
  Job		*currentJob;

  while (start || _working)
  {
    if (_jobs.empty())
      _proc.sleep(NO_TIMEOUT);
    else
    {
      _mutex.lock();
      currentJob = _jobs.front();
      _jobs.pop();
      _mutex.unlock();
      (*(currentJob->func))(currentJob->args);
    }
    start = false;
  }
}

bool		EThreadPool::addNewThread(int nb_thread)
{
  for (int i = 0; i < nb_thread; ++i)
  {
    EThread *tmp = new EThread;

    if (tmp->launch(thread_start, this) != 0)
      throw ;
    _threads.push_back(tmp);
  }
  return (true);
}

EThreadPool::~EThreadPool()
{
  for (std::vector<EThread *>::iterator it = _threads.begin();
       it != _threads.end(); ++it)
    (*it)->waitThread();
  while (!_threads.empty())
  {
    delete _threads.back();
    _threads.pop_back();
  }
}

void	*thread_start(void *p)
{
  reinterpret_cast<EThreadPool *>(p)->pendingFunc();
  return (NULL);
}
