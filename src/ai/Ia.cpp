//
// Ia.cpp for Bomberman in /home/patoche/rendu/CPP/cpp_bomberman
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Mon May 18 15:23:47 2015 Hugo Prenat
// Last update Wed Jun 10 20:26:35 2015 Hugo Prenat
//

#include "Ia.hh"

Ia::Ia(std::string const &fileName, Board &Board) : Player(Board),
						    _fileName(fileName)
{
	std::cout << "je créé l'IA" << std::endl;
  _key = -1;
  _enemyX = -1;
  _enemyY = -1;
  _chai.add(chaiscript::fun(&Player::is_Alive, this), "iaAlive");
  _chai.add(chaiscript::fun(&Player::triggerOneBomb, this), "iaDropBomb");
  _chai.add(chaiscript::fun(&Ia::chooseDir, this), "iaChooseDir");
	_chai.add(chaiscript::fun(&Ia::getCloserEnemy, this), "iaCloserEnemy");
	_chai.add(chaiscript::fun(&Ia::getPosById, this), "iaPosById");
}

Ia::~Ia()
{

}

void	Ia::run_user()
{
  std::cout << "toto" << std::endl;
  _chai.eval_file(_fileName);
}

bool	Ia::chooseDir(const int dir)
{
  return (selectDirection(static_cast<Board::Direction>(dir)));
}

Board&	Ia::getBoard() const
{
  return (_board);
}

int	Ia::getCloserEnemy()
{
  int id = 0;
  return (id);
}

void	Ia::getPosById(const int id)
{
  return ;
}
