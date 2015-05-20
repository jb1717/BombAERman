//
// LauncherUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Wed May 20 19:57:09 2015 TommyStarK
// Last update Wed May 20 21:40:33 2015 TommyStarK
//

#include "LauncherUI.hpp"

LauncherUI::LauncherUI(VideoContext &videocontext, int x, int y)
  : _x(x), _y(y), _select(0), _run(true), _win(videocontext)
{
    // _buttons.push_back(new Play);
    // _buttons.push_back(new Settings);
    this->loop();
}

LauncherUI::~LauncherUI()
{

}

void                                    LauncherUI::loop()
{
  while (_run == true)
  {
    for (auto i : _buttons)
    {
      std::tuple<bool, enum AButtons::Keys>   tmp;

      tmp = (*i).checkInput();
      if (std::get<0>(tmp) == true)
      {
        if (_select == PLAY && std::get<1>(tmp) == AButtons::UP)
          _select = QUIT;
        else if (_select == QUIT && std::get<1>(tmp) == AButtons::DOWN)
          _select = PLAY;
        else {
          if (std::get<1>(tmp) == AButtons::ENTER) {
            (*i).launch();
            break;
          }
          else if (std::get<1>(tmp) == AButtons::ESC)
            break;
        }
      }
    }
  }
  _run = false;
}
