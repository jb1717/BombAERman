//
// Ia.cpp for Bomberman in /home/patoche/rendu/CPP/cpp_bomberman
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Mon May 18 15:23:47 2015 Hugo Prenat
// Last update Sun Jun 14 10:05:08 2015 Hugo Prenat
//

#include "GameEngine.hh"
#include "Ia.hh"
#include "Node.hh"

Ia::Ia(std::string const &fileName, Board &Board) : Player(Board),
						    _fileName(fileName)
{
  int north = 0;
  int west = 1;
  int south = 2;
  int east = 3;

  _key = -1;
  _enemyX = -1;
  _enemyY = -1;
  _chai.add(chaiscript::fun(&Player::is_Alive, this), "iaAlive");
  _chai.add(chaiscript::fun(&Player::triggerOneBomb, this), "iaDropBomb");
  _chai.add(chaiscript::fun(&Ia::chooseDir, this), "iaChooseDir");
  _chai.add(chaiscript::fun(&Ia::getCloserEnemy, this), "iaCloserEnemy");
  _chai.add(chaiscript::fun(&Ia::setPosById, this), "iaPosById");
  _chai.add(chaiscript::fun(&Ia::moveToEnemy, this), "iaMoveToEnemy");
  _chai.add(chaiscript::fun(&Ia::dangerZone, this), "iaDangerZone");
  _chai.add(chaiscript::fun(&Player::goAhead, this), "iaMove");
  _chai.add_global_const(chaiscript::const_var(north), "North");
  _chai.add_global_const(chaiscript::const_var(west), "West");
  _chai.add_global_const(chaiscript::const_var(south), "South");
  _chai.add_global_const(chaiscript::const_var(east), "East");
}

Ia::~Ia()
{

}

void	Ia::run_user()
{
  try
  {
    _chai.eval_file(_fileName);
  }
  catch (const std::exception &err)
  {
    std::cerr << "\033[36m" << err.what() << "\033[0m" << std::endl;
  }
}

bool	Ia::chooseDir(const int dir)
{
  std::lock_guard<std::mutex> lock(_mutex);
  std::cout << "Before x = " << _x << " y = " << _y << std::endl;
  selectDirection(static_cast<Board::Direction>(dir));
  std::cout << "Afteer x = " << _x << " y = " << _y << std::endl;
  return (true);
}

Board&	Ia::getBoard() const
{
  return (_board);
}

std::map<float, AObj *>& Ia::getMapEnemy() const
{
  std::lock_guard<std::mutex> lock(_mutex);
  std::vector<std::vector<AObj *>>  v = _board.getFullBoard();
  std::map<float, AObj *>           *enemy = new std::map<float, AObj *>;

  for (std::vector<std::vector<AObj *>>::iterator it = v.begin();
       it != v.end(); ++it)
    {
      std::vector<AObj *> tmp = *it;
      for (std::vector<AObj *>::iterator i = tmp.begin(); i != tmp.end(); ++i)
        {
          AObj  *obj = *i;
          if (obj->getType() == PLAYER) {
            std::pair<float, float> pos = obj->getPos();
            float dist = sqrt(pow(_x - pos.first, 2) + pow(_y - pos.second, 2));

            if (dist != 0)
              enemy->insert(std::make_pair(dist, obj));
          }
        }
    }
  return (*enemy);
}

static int	moveToObj(std::map<int, std::string> map, const char obj,
			  std::pair<float, float> const pos)
{
  int		north = 0;
  int		west = 1;
  int		south = 2;
  int		east = 3;

  if (map[static_cast<size_t>(pos.first - 1)][static_cast<size_t>(pos.second)] == obj)
    return (north);
  if (map[static_cast<size_t>(pos.first + 1)][static_cast<size_t>(pos.second)] == obj)
    return (west);
  if (map[static_cast<size_t>(pos.first)][static_cast<size_t>(pos.second + 1)] == obj)
    return (south);
  if (map[static_cast<size_t>(pos.first)][static_cast<size_t>(pos.second - 1)] == obj)
    return (east);
  return (0);
}

int Ia::dangerZone()
{
  std::lock_guard<std::mutex> lock(_mutex);
  std::vector<std::vector<AObj *>>  v = _board.getFullBoard();
  std::map<int, std::string>           map;
  std::map<int, std::string>           safe;

  for (size_t i = 0; i < getBoard().size(); i++)
    {
      map[i / getBoard().getWidth()] += '0';
      safe[i / getBoard().getWidth()] += ' ';
    }

  for (std::vector<std::vector<AObj *>>::iterator it = v.begin();
       it != v.end(); ++it)
    {
      std::vector<AObj *> tmp = *it;
      for (std::vector<AObj *>::iterator i = tmp.begin(); i != tmp.end(); ++i)
        {
          AObj  *obj = *i;

          switch (obj->getType())
            {
	    case ::BOMB:
	      {
		std::pair<float, float> pos = obj->getPos();
		map[static_cast<int>(pos.first)][static_cast<int>(pos.second)] = '1';
		for (size_t i = 0; i < static_cast<size_t>(reinterpret_cast<Bomb *>(obj)->getRange()); i++)
		  {
		    map[static_cast<size_t>(pos.first - i)][static_cast<size_t>(pos.second)] = '1';
		    map[static_cast<size_t>(pos.first + i)][static_cast<size_t>(pos.second)] = '1';
		    map[static_cast<size_t>(pos.first)][static_cast<size_t>(pos.second - i)] = '1';
		    map[static_cast<size_t>(pos.first)][static_cast<size_t>(pos.second + i)] = '1';
		  }
		break ;
	      }
	    case ::UNBREAKABLE_WALL:
	      {
		std::pair<float, float> pos = obj->getPos();
		map[static_cast<int>(pos.first)][static_cast<int>(pos.second)] = '8';
		map[static_cast<int>(pos.first)][static_cast<int>(pos.second)] = 'x';
		break ;
	      }
	    case ::CRATE:
	      {
		std::pair<float, float> pos = obj->getPos();
		map[static_cast<int>(pos.first)][static_cast<int>(pos.second)] = 'p';
		break ;
	      }
	    default: break ;
            }
        }
    }
  if (map[static_cast<size_t>(getPos().first)][static_cast<size_t>(getPos().second)] != '1')
    return (-1);
  if (map[static_cast<size_t>(getPos().first - 1)][static_cast<size_t>(getPos().second)] == '0')
    return (0);
  if (map[static_cast<size_t>(getPos().first + 1)][static_cast<size_t>(getPos().second)] == '0')
    return (2);
  if (map[static_cast<size_t>(getPos().first)][static_cast<size_t>(getPos().second + 1)] == '0')
    return (1);
  if (map[static_cast<size_t>(getPos().first)][static_cast<size_t>(getPos().second - 1)] == '0')
    return (3);
  std::cout << "DANS LA MIERDA" << std::endl;
  return (-1);
}

int Ia::moveToEnemy(const int id)
{
  AObj* enemy = getEnemyById(id);
  std::pair<float, float> pos = enemy->getPos();
  std::lock_guard<std::mutex> lock(_mutex);
  std::vector<std::vector<AObj *>>  v = _board.getFullBoard();
  std::map<int, std::string>           map;
  std::map<int, std::string>           old;

  for (size_t i = 0; i < getBoard().size(); i++) {
    map[i / getBoard().getWidth()] += ' ';
  }

  for (std::vector<std::vector<AObj *>>::iterator it = v.begin();
       it != v.end(); ++it)
    {
      std::vector<AObj *> tmp = *it;
      for (std::vector<AObj *>::iterator i = tmp.begin(); i != tmp.end(); ++i)
        {
          AObj  *obj = *i;
          if (obj->getType() == UNBREAKABLE_WALL) {
            std::pair<float, float> pos = obj->getPos();
            map[static_cast<int>(pos.first)][static_cast<int>(pos.second)] = 'x';
          }
        }
    }
  Node Algo(map, getPos().first, getPos().second, pos.first, pos.second);

  old = Algo.fillMap();
  // for (size_t i = 0; i < getBoard().getWidth(); i++) {
  //   std::cout << old[i] << std::endl;
  // }
  return (moveToObj(old, 'u', getPos()));
}

int		Ia::getCloserEnemy() const
{
  std::map<float, AObj *>   enemy = getMapEnemy();

  std::map<float, AObj *>::iterator it = enemy.begin();
  return (it->second->getId());
}

AObj*		Ia::getEnemyById(int id) const
{
  std::map<float, AObj *>   enemy = getMapEnemy();

  for(std::map<float, AObj *>::iterator it = enemy.begin(); it != enemy.end();
  ++it)
  {
    if (it->second->getId() == id)
      return (it->second);
  }
  return (NULL);
}

void	Ia::setPosById(const int id)
{
  std::map<float, AObj *>   enemy = getMapEnemy();

  _enemyX = enemy[id]->getPos().first;
  return ;
}

bool	Ia::possibleToMove(const int dir)
{
  std::cout << dir << std::endl;;
  return (true);
}
