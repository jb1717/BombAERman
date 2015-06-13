//
// PauseUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 03:46:33 2015 TommyStarK
// Last update Fri Jun 12 22:21:50 2015 TommyStarK
//

#include "UIManager/PauseUI.hh"

PauseUI::PauseUI()
{

}

PauseUI::~PauseUI()
{

}

void                          PauseUI::updateContext()
{
  
}

void                          PauseUI::launch()
{
  std::cout << "########### GAME STOPPED - PAUSE UI ##########" << std::endl;
}

stateUI                       PauseUI::handlerEvent()
{
  return (std::tuple<bool, std::string>(false, this->getName()));
}
