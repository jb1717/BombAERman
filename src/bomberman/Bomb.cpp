//
// bomb.cpp for bomberman in /home/tran_0/rendu/cpp_bomberman/include
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Sun May  3 01:03:38 2015 David Tran
// Last update Mon May 18 04:59:59 2015 David Tran
//

#include "Bomb.hh"

Bomb::Bomb(Board &Board, bool Launch, char Range) : AObj(Board), launched(Launch), range(Range)
{
  bombThread = new EThread;
}

Bomb::~Bomb()
{}

bool	Bomb::isLaunched() const
{
  return (launched);
}

void	Bomb::triggerLaunch(int x, int y)
{
  launched = !launched;
  if (launched)
    {
      _time = std::chrono::steady_clock::now();
      bombThread->launch(run_bomb, this);
    }
  setPosition(x, y);
}

bool	Bomb::explosion_check()
{
  std::chrono::steady_clock::time_point timeNow = std::chrono::steady_clock::now();
  if (launched && (std::chrono::duration_cast<std::chrono::duration<int>>(timeNow - _time)).count() > 3)
    return (true);
  return (false);
}

char	Bomb::getRange() const
{
  return (range);
}

void	Bomb::setRange(char const &Range)
{
  range = Range;
}

void			Bomb::run()
{
  while (!explosion_check())
    {
      usleep(0.2);
    }
  launched = !launched;
}
