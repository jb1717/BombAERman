//
// Ia.hh for Bomberman in /home/patoche/rendu/CPP/cpp_bomberman
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Mon May 18 15:12:42 2015 Hugo Prenat
// Last update Sat Jun 13 17:06:21 2015 Hugo Prenat
//

#ifndef NODE_HH_
# define NODE_HH_

# include <cmath>
# include <utility>
# include <map>
# include <list>

struct			Case
{
  float			toPoss;
  float			toDest;
  float			total;
  std::pair<int,int>	father;
};

class					Node
{
public:
  Node(std::map<int, std::string>& map, int x, int y, int xEnemy, int yEnemy);
  ~Node();

public:
  float					dist(int x1, int y1, int x2, int y2);
  void					addAjacentsBox(std::pair<int,int>& box);
  bool					isInList(std::pair<int,int> unk,
						 std::map<std::pair<int,int>, Case>& list);
  std::pair<int,int>			bestNode(std::map<std::pair<int,int>, Case>& list);
  void					addCloseList(std::pair<int, int>& elem);
  void					findPath();
  std::map<int, std::string>&		fillMap();

private:
  std::map<int, std::string>&		_map;
  std::map<std::pair<int,int>, Case>	_closeList;
  std::map<std::pair<int,int>, Case>	_openList;
  std::list<std::pair<int, int>>	_path;
  std::pair<int, int>			_end;
  Case					_start;
};

#endif // !NODE_HH_
