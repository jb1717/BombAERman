//
// main.cpp for CPP_BOMBERMAN in /home/paasch_j/cpp_bomberman/src/bomberman_src
//
// Made by Johan Paasche
// Login   <paasch_j@epitech.net>
//
// Started on  Mon Apr 27 11:27:27 2015 Johan Paasche
// Last update Wed May 27 01:05:05 2015 Milox Thomas
//

#include	"basics.hh"
#include	"Bomberman.hh"
#include	"UIManager/UIManager.hh"
#include	"manager/ScoreHandler.hh"

int	main()
{
  try {
    ScoreHandler  test;
    test.debug();

    test << "Dany;3";
    test << "jon;123";
    test << "Tom;9999";
    test.debug();

    test >> "Dany";
    test.debug();

    BestScores *top = test.top(3);
    for (BestScores::iterator i = top->begin(); i != top->end(); i++)
      std::cout << (*i).best << std::endl;

    UIManager();

    Bomberman();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
