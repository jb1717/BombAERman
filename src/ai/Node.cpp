//
// Node.cpp for Bomberman in /home/patoche/Rendu/CPP/cpp_bomberman/src/ai/
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Sat Jun 13 13:56:45 2015 Hugo Prenat
// Last update Sun Jun 14 20:54:33 2015 Hugo Prenat
//

#include "Node.hh"

Node::Node(std::map<int, std::string>& map, int x, int y, int xEnemy, int yEnemy)
  : _map(map)
{
	_start.father.first = x;
	_start.father.second = y;
	_end.first = xEnemy;
	_end.second = yEnemy;
}

Node::~Node()
{

}

float	Node::dist(int x1, int y1, int x2, int y2)
{
  return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

bool	Node::isInList(std::pair<int, int> unk,
		       std::map<std::pair<int, int>, Case>& list)
{
  std::map<std::pair<int,int>, Case>::iterator it = list.find(unk);
  if (it == list.end())
    return (false);
  return (true);
}

void	Node::addAjacentsBox(std::pair<int, int>& box)
{
  Case	tmp;

  for (int x = box.first - 1; x <= box.first + 1; x++)
    {
      if (x < 0 || x >= static_cast<int>(_map.size()))
	continue;
      for (int y = box.second - 1; y <= box.second + 1; y++)
	{
	  if (y < 0 ||
	      y >= static_cast<int>(_map[x].length()) ||
	      _map[x][y] == 'x' ||
	      (x == box.first && y == box.second))
	    continue;
	  std::pair<int,int> it(x, y);

	  if (!isInList(it, _closeList))
	    {
	      tmp.toPoss = _closeList[box].toPoss + dist(x, y, box.first,
							 box.second);
	      tmp.toDest = dist(x, y, _end.first, _end.second);
	      tmp.total = tmp.toPoss + tmp.toDest;
	      tmp.father = box;
	      if (isInList(it, _openList))
		{
		  if (tmp.toDest < _openList[it].toDest)
		    _openList[it] = tmp;
		}
	      else
		_openList[std::pair<int,int>(x, y)] = tmp;
	    }
	}
    }
}

std::pair<int,int>	Node::bestNode(std::map<std::pair<int,int>, Case>& list)
{
  float			total = list.begin()->second.total;
  std::pair<int,int>	best = list.begin()->first;

  for (std::map<std::pair<int,int>, Case>::iterator it = list.begin();
       it != list.end(); it++)
    {
      if (it->second.total < total)
	{
	  total = it->second.total;
	  best = it->first;
	}
    }
  return (best);
}

void	Node::addCloseList(std::pair<int, int>& elem)
{
  Case&	add = _openList[elem];

  _closeList[elem] = add;
  _openList.erase(elem);
  return ;
}

void	Node::findPath()
{
  Case& tmp = _closeList[std::pair<int, int>(_end.first, _end.second)];
  std::pair<int, int> path;
  std::pair<int, int> old;

  path.first = _end.first;
  path.second = _end.second;
  old.first  = tmp.father.first;
  old.second = tmp.father.second;
  _path.push_front(path);
  while (old != std::pair<int,int>(_start.father.first, _start.father.second))
    {
      path.first = old.first;
      path.second = old.second;
      _path.push_front(path);
      tmp = _closeList[tmp.father];
      old.first  = tmp.father.first;
      old.second = tmp.father.second;
    }
  return ;
}

std::map<int, std::string>& Node::fillMap()
{
  std::pair<int,int> current;

  current.first  = 0;
  current.second = 0;
  _openList[current] = _start;
  addCloseList(current);
  addAjacentsBox(current);
  while (!((current.first == _end.first) && (current.second == _end.second)) &&
	 (!_openList.empty()))
    {
      current = bestNode(_openList);
      addCloseList(current);
      addAjacentsBox(current);
    }
  if ((current.first == _end.first) && (current.second == _end.second))
    {
      std::list<std::pair<int, int>>::iterator it;

      findPath();
      for (it = _path.begin(); it != _path.end(); it++)
	{
	  if (_map[it->first][it->second] != 'x')
	    _map[it->first][it->second] = 'u';
	}
    }
  return (_map);
}
