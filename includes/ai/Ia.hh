//
// Ia.hh for Bomberman in /home/patoche/rendu/CPP/cpp_bomberman
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Mon May 18 15:12:42 2015 Hugo Prenat
// Last update Sat Jun 13 06:17:50 2015 Jean-Baptiste Grégoire
//

#ifndef IA_HH_
# define IA_HH_

# include <chaiscript/chaiscript.hpp>

# include "Player.hh"

class				Ia : public Player
{
public:
  Ia(std::string const &fileName, Board &Board);
  ~Ia();

public:
  Board&			getBoard() const;
  std::string			getMap() const;
  AObj*				getCloserEnemy() const;		// Return Enemy Id
  std::map<float, AObj *>&	getMapEnemy() const;

public:
  bool			userAction();
  void			run_user();
  bool			chooseDir(const int dir);
  void			setPosById(const long int id);	// Set _enemyX _enemyY to Id Pos

public:
  long int       getDistance(long int id) const ;
  long int       getCloserAvailableEnemy() const;
  void				moveToEnemy(const int id);


private:
  int				_key;
  float				_enemyX;
  float				_enemyY;
  std::string			_fileName;
  chaiscript::ChaiScript	_chai;
};

#endif // !IA_HH_
