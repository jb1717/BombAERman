//
// AssetManager.cpp for Bomberman in /home/chambo_e/epitech/cpp_bomberman/src/bomberman/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Fri May 22 18:04:57 2015 Emmanuel Chambon
// Last update Sat May 23 19:35:54 2015 Emmanuel Chambon
//

#include "manager/AssetManager.hh"

AssetManager::AssetManager()
{
	_assets["boards"] = std::make_shared<BoardHandler>();
	_assets["themes"] = std::make_shared<ThemeHandler>();
    // Themes
    // Models
    // Scores
    // Saves
	// Sounds
	// Settings
}

AssetManager::~AssetManager()
{

}

std::shared_ptr<AAsset>           AssetManager::operator[](std::string const &at)
{
	if (_assets.find(at) == _assets.end())
		throw std::out_of_range("Out of range on AssetManager");
	return _assets[at];
}
