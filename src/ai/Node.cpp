//
// Node.cpp for Bomberman in /home/patoche/Rendu/CPP/cpp_bomberman/src/ai/
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Sat Jun 13 13:56:45 2015 Hugo Prenat
// Last update Sat Jun 13 14:34:24 2015 Hugo Prenat
//

#include "Node.hh"

Node::Node()
{

}

Node::~Node()
{

}

float Node::dist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
