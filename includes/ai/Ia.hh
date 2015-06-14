//
// Ia.hh for Bomberman in /home/patoche/rendu/CPP/cpp_bomberman
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Mon May 18 15:12:42 2015 Hugo Prenat
// Last update Sun Jun 14 22:15:04 2015 Hugo Prenat
//

#ifndef IA_HH_
# define IA_HH_

# include <chaiscript/chaiscript.hpp>

# include "Player.hh"
# include "Node.hh"

class				Ia : public Player
{
public:
  Ia(std::string const &fileName, Board &Board);
  ~Ia();

public:
  Board&			getBoard() const;
  int				getCloserAvailableEnemy() const;
  int				getCloserEnemy() const;		// Return Enemy Id
  AObj*				getEnemyById(int id) const;
  std::map<float, AObj *>&	getMapEnemy() const;

public:
  bool				userAction();
  void				run_user();
  bool				chooseDir(const int dir);
  int				moveToEnemy(const int id);
  int				moveToType(const char obj);
  int				dangerZone();
  int				whichObject(const int dir);
  bool				possibleToMove(const int dir);
  int				getPath(std::map<int, std::string>& maze,
					int posx, int posy, int sizex, int sizey);

public:
  void				setPosById(const int id);	// Set _enemyX _enemyY to Id Pos

private:
  int				_key;
  float				_enemyX;
  float				_enemyY;
  std::string			_fileName;
  chaiscript::ChaiScript	_chai;
};

#endif // !IA_HH_
