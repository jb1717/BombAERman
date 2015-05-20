//
// EThreadPool.hh for Bomberman in /home/tran_0/rendu/cpp_bomberman
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Mon May 18 18:40:53 2015 David Tran
// Last update Mon May 18 19:48:35 2015 David Tran
//

#ifndef ETHREADPOOL_HH_
# define ETHREADPOOL_HH_

# include <vector>
# include <queue>
# include <exception>
# include <stdexcept>
# include "EThread.hh"
# include "ECondVar.hh"
# include "EMutex.hh"

class		Ethread;

class		EThreadPool
{
public:
  EThreadPool(int nb_thread);
  ~EThreadPool();

public:
  bool    addNewThread(int nb_thread);
  void    addWork(void *(*routine)(void *), void *args);
  void    pendingFunc();
  void    stopThePool();

private:
  typedef struct
  {
    void	*(*func)(void *);
    void	*args;
  }		Job;

private:
  int   _size;
  bool	_working;
  std::vector<EThread *>	_threads;
  std::queue<Job *>		_jobs;
  ECondVar			_proc;
  EMutex			_mutex;
};

void	*thread_start(void *);

#endif // !ETHREADPOOL_HH_
