//
// Ia.hh for Bomberman in /home/patoche/rendu/CPP/cpp_bomberman
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Mon May 18 15:12:42 2015 Hugo Prenat
// Last update Thu Jun 11 15:59:50 2015 Hugo Prenat
//

#ifndef IA_HH_
# define IA_HH_

# include <chaiscript/chaiscript.hpp>

# include "Player.hh"

class			Ia : public Player
{
public:
  Ia(std::string const &fileName, Board &Board);
  ~Ia();

public:
  Board&		getBoard() const;

public:
  bool			userAction();
  void			run_user();
  bool			chooseDir(const int dir);
  int			getCloserEnemy();		// Return Enemy Id
  void			getPosById(const int id);	// Set _enemyX _enemyY to Id Pos
  std::map<float, AObj *>& getMapEnemy();

private:
  int				_key;
  float				_enemyX;
  float				_enemyY;
  std::string			_fileName;
  chaiscript::ChaiScript	_chai;
};

#endif // !IA_HH_
