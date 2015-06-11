//
// Ia.cpp for Bomberman in /home/patoche/rendu/CPP/cpp_bomberman
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Mon May 18 15:23:47 2015 Hugo Prenat
// Last update Thu Jun 11 16:05:29 2015 Hugo Prenat
//

#include "Ia.hh"

Ia::Ia(std::string const &fileName, Board &Board) : Player(Board),
						    _fileName(fileName)
{
  int north = 0;
  int west = 1;
  int south = 2;
  int east = 3;

  std::cout << "je créé l'IA" << std::endl;
  _key = -1;
  _enemyX = -1;
  _enemyY = -1;
  _chai.add(chaiscript::fun(&Player::is_Alive, this), "iaAlive");
  _chai.add(chaiscript::fun(&Player::triggerOneBomb, this), "iaDropBomb");
  _chai.add(chaiscript::fun(&Ia::chooseDir, this), "iaChooseDir");
  _chai.add(chaiscript::fun(&Ia::getCloserEnemy, this), "iaCloserEnemy");
  _chai.add(chaiscript::fun(&Ia::getPosById, this), "iaPosById");
  _chai.add(chaiscript::var(north), "North");
  _chai.add(chaiscript::var(west), "West");
  _chai.add(chaiscript::var(south), "South");
  _chai.add(chaiscript::var(east), "East");
}

Ia::~Ia()
{

}

void	Ia::run_user()
{
  _chai.eval_file(_fileName);
  std::cout << "toto" << std::endl;
}

bool	Ia::chooseDir(const int dir)
{
  return (selectDirection(static_cast<Board::Direction>(dir)));
}

Board&	Ia::getBoard() const
{
  return (_board);
}

std::map<float, AObj *>& Ia::getMapEnemy()
{
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

int		Ia::getCloserEnemy()
{
  int	id = 0;
  return (id);
}

void	Ia::getPosById(const int id)
{
  std::vector<std::vector<AObj *>>           v = _board.getFullBoard();

  for (std::vector<std::vector<AObj *>>::iterator it = v.begin();
       it != v.end(); ++it)
    {
      std::vector<AObj *> tmp = *it;
      for (std::vector<AObj *>::iterator i = tmp.begin(); i != tmp.end(); ++i)
        {
          AObj  *obj = *i;
          if (obj->getType() == PLAYER) {
            std::cout << "Ouais == " << obj->getId() << std::endl; // TO FILL
          }
        }
    }
  return ;
}
