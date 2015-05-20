//
// Player.cpp for Bomberman in /home/tran_0/rendu/cpp_bomberman/include
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Sun May  3 01:33:50 2015 David Tran
// Last update Wed May 20 12:00:42 2015 David Tran
//

#include "Player.hh"

Player::Player(Board &Board) : AObj(Board, 0, 0), _isAlive(true), _speed(1)
{
  Bomb	*newone = new Bomb(Board);

  _bombs.push_back(newone);
  _bombThread = new EThreadPool(1);
}

bool		Player::playerSpawn(float x, float y, Board::Direction direction, int Id)
{
  setPosition(x, y);
  _dir = direction;
  setId(Id);
  return (true);
}

Player::~Player()
{
  int intx = static_cast<int>(_x), inty = static_cast<int>(_y);

  _board.popEntity(intx, inty, _id);
  _board.popEntity(intx + 1, inty, _id);
  _board.popEntity(intx, inty + 1, _id);
  _board.popEntity(intx + 1, inty + 1, _id);  
  // delete from all the vector of squares
}

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
  _bombThread->addNewThread(1);
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
  auto	positions = getPosition();

  while (it != _bombs.end())
    {
      if ((*it)->isLaunched() == false)
	{
	  (*it)->triggerLaunch(positions.first, positions.second);
	  _bombThread->addWork(run_bomb, (*it));
	  return (true);
	}
      it++;
    }
  return (true);
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

void	Player::checkPosPowerUp()
{
  std::vector<AObj *>	all_in = _board.getSquareObjects(static_cast<int>(_x), static_cast<int>(_y));
  auto			all_in_it = all_in.begin();
  Crate::BonusType	powerup = Crate::NONE;

  while (all_in_it != all_in.begin())
    {
      if ((*all_in_it)->getId() == -2)
	{
	  powerup = reinterpret_cast<Crate *>((*all_in_it))->getBonus();
	  if (powerup == Crate::SPEED)
	    _speed += 1;
	  else if (powerup == Crate::RANGE)
	    powerUpRange();
	  else if (powerup == Crate::ADD)
	    addBomb();
	  return ;
	}
      all_in_it++;
    }
}

void	Player::run_user()
{
  while (_isAlive)
    {
      if (!userAction())
	return ; // If Negative , throw
      checkPosPowerUp();
    }
}

int	Player::commandValue()
{
  return (0);
}

bool	Player::userAction()
{
  int	keyPressed;

  if ((keyPressed = commandValue()) < 0)
    return (false);
  else if (keyPressed < 4)
    return (selectDirection(static_cast<Board::Direction>(keyPressed)));
  else if (keyPressed == 4)
    return (triggerOneBomb());
  return (false);
}

bool	Player::selectDirection(Board::Direction direc)
{
  if (_dir == direc)
    return (goAhead());
  else if (_dir == (static_cast<Board::Direction>((_dir - 1) % 4)))
    return (turnLeft());
  else if (_dir == (static_cast<Board::Direction>((_dir + 1) % 4)))
    return (turnRight());
  return (goBack());
}

bool	Player::turnLeft()
{
  _dir = static_cast<Board::Direction>((_dir + 1) % 4);
  return (_board.moveEntity(_x, _y, _id, _dir));
}

bool	Player::turnRight()
{
  _dir = static_cast<Board::Direction>((_dir - 1) >= 0 ? _dir - 1 : 3);
  return (_board.moveEntity(_x, _y, _id, _dir));
}

bool	Player::goAhead()
{
  return (_board.moveEntity(_x, _y, _id, _dir));
}

bool	Player::goBack()
{
  _dir = static_cast<Board::Direction>((_dir + 2) % 4);
  return (_board.moveEntity(_x, _y, _id, _dir));
}
