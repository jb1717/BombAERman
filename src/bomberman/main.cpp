//
// main.cpp for CPP_BOMBERMAN in /home/paasch_j/cpp_bomberman/src/bomberman_src
//
// Made by Johan Paasche
// Login   <paasch_j@epitech.net>
//
// Started on  Mon Apr 27 11:27:27 2015 Johan Paasche
// Last update Thu May 28 02:17:09 2015 Emmanuel Chambon
//

#include	"Bomberman.hh"
#include	"UIManager/UIManager.hh"
#include    "AssetManager.hh"

int	main()
{
  try {
    AssetManager::instance();

    // ScoreHandler  test;
    // test.debug();

    // test << "Dany;3";
    // test << "jon;123";
    // test << "Tom;9999";
    // test.debug();

    // test >> "Dany";
    // test.debug();

    // BestScores *top = test.top(3);
    // for (BestScores::iterator i = top->begin(); i != top->end(); i++)
    //   std::cout << (*i).best << std::endl;

    // UIManager();

    Bomberman();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
