#include "Score.hpp"

int main()
{
  Score		test;

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
  test << "ben;1";
  test << "manu;1234567";

  // time_t t = time(0);   // get time now
  //    struct tm * now = localtime( & t );
  //    std::cout << (now->tm_year + 1900) << '-'
  //         << (now->tm_mon + 1) << '-'
  //         <<  now->tm_mday
  //         << std::endl;
  return 0;
}
