//
// Player.cpp for Bomberman in /home/tran_0/rendu/cpp_bomberman/include
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Sun May  3 01:33:50 2015 David Tran
// Last update Mon May  4 18:33:31 2015 David Tran
//

#include "Player.hh"

Player::Player(char Speed, bool alive) : isAlive(alive), speed(Speed)
{
  Bomb	*newone = new Bomb;

  bombs.push_back(newone);
}

Player::~Player()
{}

//
// Alive Functions
//
bool	Player::is_Alive() const
{
  return (isAlive);
}

void	Player::triggerAlive()
{
  isAlive = !isAlive;
}

//
// Bomb Functions
//
void		Player::addBomb()
{
  Bomb		*newone = new Bomb;

  bombs.push_back(newone);
}

std::vector<Bomb *>		Player::getBombs() const
{
  return (bombs);
}

std::vector<Bomb*>::const_iterator	Player::getBombIt() const
{
  return (bombs.begin());
}

bool	Player::triggerOneBomb()
{
  std::vector<Bomb *>::const_iterator	it = bombs.begin();

  while (it != bombs.end())
    {
      if ((*it)->isLaunched() == false)
	{
	  (*it)->triggerLaunch();
	  return (true);
	}
      it++;
    }
  return (false);
}

void	Player::powerUpRange()
{
  std::vector<Bomb *>::const_iterator	it = bombs.begin();

  while (it != bombs.end())
    {
      (*it)->setRange((*it)->getRange() + 1);
      it++;
    }
}

//
// PowerUp Functions
//
char	Player::getSpeed() const
{
  return (speed);
}

void	Player::setSpeed(char const &Speed)
{
  speed = Speed;
}
