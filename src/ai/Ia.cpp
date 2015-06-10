//
// Ia.cpp for Bomberman in /home/patoche/rendu/CPP/cpp_bomberman
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Mon May 18 15:23:47 2015 Hugo Prenat
// Last update Wed Jun 10 18:13:50 2015 Hugo Prenat
//

#include "Ia.hh"

Ia::Ia(std::string const &fileName, Board &Board) : Player(Board),
						    _fileName(fileName)
{
	std::cout << "je créé l'IA" << std::endl;
  _key = -1;
  _chai.add(chaiscript::fun(&Player::is_Alive, this), "iaAlive");
  _chai.add(chaiscript::fun(&Player::triggerOneBomb, this), "iaDropBomb");
  _chai.add(chaiscript::fun(&Ia::chooseDir, this), "iaChooseDir");
}

Ia::~Ia()
{

}

void	Ia::run_user()
{
  sleep(1);
  std::cout << "toto" << std::endl;
  _chai.eval_file(_fileName);
}

bool	Ia::chooseDir(const int dir)
{
  return (selectDirection(static_cast<Board::Direction>(dir)));
}

bool	Ia::userAction()
{
  int	keyPressed = _key;

  if (keyPressed < 0)
    return (false);
  else if (keyPressed < 4)
    return (selectDirection(static_cast<Board::Direction>(keyPressed)));
  else if (keyPressed == 4)
    return (triggerOneBomb());
  return (false);
}

Board&	Ia::getBoard() const
{
  return (_board);
}
