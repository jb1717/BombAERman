//
// PlayUI.cpp for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/src/bomberman/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sun May 24 17:22:00 2015 TommyStarK
// Last update Thu May 28 13:59:22 2015 TommyStarK
//

#include "UIManager/PlayUI.hh"

PlayUI::PlayUI()
{
  getIaNames();
}

PlayUI::~PlayUI()
{

}

void                          PlayUI::getIaNames()
{
  DIR                         *dir = opendir("./src/ai");
  size_t                      pos = 0;
  struct dirent               *current = NULL;
  std::vector<std::string>    tmp;

  if (dir) {
    while ((current = readdir(dir)) != NULL) {
      tmp.push_back(current->d_name);
    }
    for (auto i : tmp) {
      if ((pos = i.find_last_of(".")) != std::string::npos && i.substr(pos) == ".lua")
      {
        std::string token;
        token = i.substr(0, pos);
        _iaNames.push_back(token);
      }
    }
  }
}

void                          PlayUI::launch()
{

}

stateUI                       PlayUI::handlerEvent()
{
  return (std::tuple<bool, std::string>(false, this->getName()));
}
