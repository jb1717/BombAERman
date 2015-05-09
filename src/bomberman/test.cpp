#include "Score.hpp"
#include "Save.hpp"

int main()
{
  Score		test;
  Save    sav;

  test.show();
  std::cout << "~~~~~~~~~~" << std::endl;
  test.showTop();
  std::cout << "~~~~~~~~~~" << std::endl;
  test << "jimmy;999999";
  test << "tommy;1456";
  test << "johnny;12456";
  test << "henry;14756";
  test << "bobby;46";
  test << "lilou;654654";
  test.showTop();
  test << "ben;2015";
  test << "manu;1234567";

  TOP             *a = test >> 3;

  for (TOP::iterator i = a->begin(); i != a->end(); ++i) {
    std::cout << ">> - PLAYER " << (*i).player << " DATE " << (*i).date << " SCORE " << (*i).best << std::endl;
  }
  return 0;
}
