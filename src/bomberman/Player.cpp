//
// Player.cpp for Bomberman in /home/tran_0/rendu/cpp_bomberman/include
//
// Made by David Tran
// Login   <tran_0@epitech.net>
//
// Started on  Sun May  3 01:33:50 2015 David Tran
// Last update Wed May 20 14:13:06 2015 David Tran
//

#include "GameEngine.hh"
#include "Player.hh"

Player::Player(Board &Board) : AObj(Board, 0, 0), _isAlive(true)
{
  Bomb	*newone = new Bomb(Board);

  _bombs.push_back(newone);
  _type = PLAYER;
}

bool		Player::playerSpawn(float x, float y, Board::Direction direction, int Id)
{
  setPos(x, y);
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
  _board.removePlayer(_id);
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
  //  _bombThread->addNewThread(1);
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
  std::vector<Bomb *>::iterator	it = _bombs.begin();
  auto	positions = getPos();
  float	true_x = (_board.getWidth() / 2) - _x;
  float	true_y = (_board.getHeight() / 2) - _y;

  while (it != _bombs.end())
    {
      if (!(*it)->isLaunched())
	{
	  (*it)->triggerLaunch();
	  (*it)->setPos(positions.first, positions.second);
	  // _bombThread->addWork(run_bomb, (*it));
	  _board.placeEntity(_x, _y, (*it));
	  (*it)->setGameObj(new BasicBomb());
	  (*it)->getGameObj()->setPosition(glm::vec3(true_x, 1, true_y));
	  (*it)->getGameObj()->setScale(glm::vec3(0.003f, 0.003f, 0.003f));
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

void	Player::goAllExplosions()
{
  std::lock_guard<std::mutex> lock(_mutex);
  for (std::vector<Bomb *>::iterator	it = _bombs.begin() ; it !=_bombs.end() ; it++)
    {
      if ((*it)->isLaunched() && (*it)->getGameObj())
	{
	  BasicBomb	*tmp = reinterpret_cast<BasicBomb *>((*it)->getGameObj());
	  if (tmp->isExplosed())
	    {
	      // AGameObject	*to_del = (*it)->getGameObj();
	      // delete to_del;
	      (*it)->triggerLaunch();
	      (*it)->explosion();
	    }
	}
    }
}

void	Player::update_bombs(gdl::Clock const &clock, Binput &input)
{
  for (std::vector<Bomb *>::iterator	it = _bombs.begin() ; it !=_bombs.end() ; it++)
    {
      if ((*it)->isLaunched() && (*it)->getGameObj())
	{
	  BasicBomb	*tmp = reinterpret_cast<BasicBomb *>((*it)->getGameObj());
	  tmp->update(clock, input);
	}
    }
}

//
// Principal funcions
//

void	Player::checkPosPowerUp()
{
  std::lock_guard<std::mutex> lock(_mutex);
  std::vector<AObj *>	&all_in = _board.getSquareObjects(static_cast<int>(_x), static_cast<int>(_y));
  auto			all_in_it = all_in.begin();
  Crate::BonusType	powerup = Crate::NONE;

  while (all_in_it != all_in.end())
    {
      if ((*all_in_it)->getId() == -2 && reinterpret_cast<Crate *>((*all_in_it))->isBreak())
	{
	  powerup = reinterpret_cast<Crate *>((*all_in_it))->getBonus();
	  if (powerup == Crate::RANGE)
	    powerUpRange();
	  else if (powerup == Crate::ADD)
	    addBomb();
	  _board.deleteEntity(_x, _y, 0, false);
	  return ;
	}
      all_in_it++;
    }
}

void	Player::run_user()
{
  while (_isAlive)
    {
      checkPosPowerUp();
      goAllExplosions();
    }
}

keyActions	Player::commandValue()
{
  return (NACT);
}

bool	Player::userAction()
{
  keyActions	keyPressed;

  if ((keyPressed = commandValue()) < 0)
    return (false);
  else if (keyPressed == SPACE)
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
  if (!_board.moveEntity(_x, _y, _id, _dir))
    return (false);
  float	true_x = (_board.getWidth() / 2) - _x;
  float	true_y = (_board.getHeight() / 2) - _y;
  _gameObj->setPosition(glm::vec3(true_x, 0.5, true_y));
  return (true);
}

bool	Player::turnRight()
{
  _dir = static_cast<Board::Direction>((_dir - 1) >= 0 ? _dir - 1 : 3);
  if (!_board.moveEntity(_x, _y, _id, _dir))
    return (false);
  float	true_x = (_board.getWidth() / 2) - _x;
  float	true_y = (_board.getHeight() / 2) - _y;
  _gameObj->setPosition(glm::vec3(true_x, 0.5, true_y));
  return (true);
}

bool	Player::goAhead()
{
  if (!_board.moveEntity(_x, _y, _id, _dir))
    return (false);
  float	true_x = (_board.getWidth() / 2) - _x;
  float	true_y = (_board.getHeight() / 2) - _y;
  _gameObj->setPosition(glm::vec3(true_x, 0.5, true_y));
  return (true);
}

bool	Player::goBack()
{
  _dir = static_cast<Board::Direction>((_dir + 2) % 4);
  if (!_board.moveEntity(_x, _y, _id, _dir))
    return (false);
  float	true_x = (_board.getWidth() / 2) - _x;
  float	true_y = (_board.getHeight() / 2) - _y;
  _gameObj->setPosition(glm::vec3(true_x, 0.5, true_y));
  return (true);
}
