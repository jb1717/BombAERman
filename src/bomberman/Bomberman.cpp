//
// Bomberman.cpp for  in /home/chambo_e/epitech/cpp_bomberman/src/bomberman
//
// Made by Emmanuel Chambon
// chambo_e  <chambon.emmanuel@gmail.com>
//
// Started on  Tue May 19 11:18:08 2015 Emmanuel Chambon
// Last update Tue May 19 14:42:12 2015 Emmanuel Chambon
//

#include "Bomberman.hh"

Bomberman::Bomberman()
    : _window(_x, _y, "BombAERman")
{

    setWidthHeight();

    _window.init();

    // SETBACKGROUND(_window);

    // MAINUI(_window, x, y);

    BoardHandler(_x, _y);

    while (1) ;
}

Bomberman::~Bomberman()
{

}

/*
** Define multiple instance of method for different platforms
*/
#if __linux
void                    Bomberman::setWidthHeight()
{
  FILE *cmd = popen("xdpyinfo  | grep 'dimensions:'", "r");
  if (cmd)
  {
      char buffer[1024] = {0};
      std::string res(fgets(buffer, sizeof(buffer), cmd));
      std::smatch m;

      if (std::regex_search(res, m, std::regex("([0-9])\\w+")))
      {
          std::string res(m[0]);
          std::regex_token_iterator<std::string::iterator> end;
          std::regex_token_iterator<std::string::iterator> token(res.begin(), res.end(), std::regex("x"), -1);
          _x = std::stoi(*token++) - 100;
          _y = std::stoi(*token++) - 100;
          _window.setScreenWidth(_x);
          _window.setScreenHeight(_y);
      }
      pclose(cmd);
  }
}
#else
void                    Bomberman::setWidthHeight()
{

}
#endif
