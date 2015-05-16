//
// Player.cpp for Bomberman in /home/tran_0/rendu/cpp_bomberman/include
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Sun May  3 01:33:50 2015 David Tran
// Last update Sat May 16 08:06:23 2015 David Tran
//

#include "Player.hh"

Player::Player(Board &Board) : AObj(Board, 0, 0), _isAlive(true), _speed(1)
{
  Bomb	*newone = new Bomb(Board);

  _bombs.push_back(newone);
}

bool		Player::playerSpawn(int x, int y, Board::Direction direction)
{
  setPosition(x, y);
  _dir = direction;
  return (true);
}

Player::~Player()
{}

//
// Alive Functions
//
bool	Player::is_Alive() const
{
  return (_isAlive);
}

void	Player::triggerAlive()
{
  _isAlive = !_isAlive;
}

//
// Bomb Functions
//
void		Player::addBomb()
{
  Bomb		*newone = new Bomb(_board);

  _bombs.push_back(newone);
}

std::vector<Bomb *>		Player::getBombs() const
{
  return (_bombs);
}

std::vector<Bomb*>::const_iterator	Player::getBombIt() const
{
  return (_bombs.begin());
}

bool	Player::triggerOneBomb()
{
  std::vector<Bomb *>::const_iterator	it = _bombs.begin();

  while (it != _bombs.end())
    {
      if ((*it)->isLaunched() == false)
	{
	  (*it)->triggerLaunch(0, 0);
	  return (true);
	}
      it++;
    }
  return (false);
}

void	Player::powerUpRange()
{
  std::vector<Bomb *>::const_iterator	it = _bombs.begin();

  while (it != _bombs.end())
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
  return (_speed);
}

void	Player::setSpeed(char const &Speed)
{
  _speed = Speed;
}

//
// Principal funcions
//
void	Player::run_user()
{}

bool	Player::turnLeft()
{
  _dir = static_cast<Board::Direction>((_dir + 1) % 4);
  // return (_board.moveEntity(_x, _y, _dir));
  return (true);
}

bool	Player::turnRight()
{
  _dir = static_cast<Board::Direction>((_dir - 1) >= 0 ? _dir - 1 : 3);
  // return (_board.moveEntity(_x, _y, _dir));
  return (true);
}

bool	Player::goAhead()
{
  // return (_board.moveEntity(_x, _y, _dir));
  return (true);
}

bool	Player::goBack()
{
  _dir = static_cast<Board::Direction>((_dir + 2) % 4);
  // return (_board.moveEntity(_x, _y, _dir));
  return (true);
}
