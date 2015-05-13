//
// Player.cpp for Bomberman in /home/tran_0/rendu/cpp_bomberman/include
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Sun May  3 01:33:50 2015 David Tran
// Last update Wed May 13 21:44:28 2015 Jean-Baptiste Grégoire
//

#include "Player.hh"

Player::Player(char Speed, bool alive, Map &map) : _isAlive(alive), _speed(Speed), _map(map)
{
  Bomb	*newone = new Bomb;

  _bombs.push_back(newone);
}

bool		Player::playerSpawn(int x, int y, Map::Direction direction)
{
  if (_map.placeEntity(x, y, PLAYER_CHAR))
    {
      _x = x;
      _y = y;
      _dir = direction;
      return (true);
    }
  return (false);
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
  Bomb		*newone = new Bomb;

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
  _dir = static_cast<Map::Direction>((_dir + 1) % 4);
  return (_map.moveEntity(_x, _y, _dir));
}

bool	Player::turnRight()
{
  _dir = static_cast<Map::Direction>((_dir - 1) >= 0 ? _dir - 1 : 3);
  return (_map.moveEntity(_x, _y, _dir));
}

bool	Player::goAhead()
{
  return (_map.moveEntity(_x, _y, _dir));
}

bool	Player::goBack()
{
  _dir = static_cast<Map::Direction>((_dir + 2) % 4);
  return (_map.moveEntity(_x, _y, _dir));
}
