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
  test << "jimmy;999";
  test << "tommy;1456";
  test << "johnny;456";
  test << "henry;156";
  test << "bobby;46";
  test << "lilou;654";
  test.showTop();
  test << "ben;2";
  test << "manu;666";

  TOP             *a = test >> 3;

  for (TOP::iterator i = a->begin(); i != a->end(); ++i) {
    std::cout << ">> - PLAYER " << (*i).player << " DATE " << (*i).date << " SCORE " << (*i).best << std::endl;
  }
  return 0;
}
