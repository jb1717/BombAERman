//
// PlayUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 17:22:00 2015 TommyStarK
// Last update Sun May 24 18:02:08 2015 TommyStarK
//

#include "UIManager/PlayUI.hh"

PlayUI::PlayUI()
{

}

PlayUI::~PlayUI()
{

}

void                          PlayUI::launch()
{

}

stateUI                       PlayUI::handlerEvent()
{
  return (std::tuple<bool, std::string>(false, this->getName()));
}
