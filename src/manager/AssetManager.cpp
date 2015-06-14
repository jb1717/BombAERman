//
// AssetManager.cpp for Bomberman in /home/chambo_e/epitech/cpp_bomberman/src/bomberman/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Fri May 22 18:04:57 2015 Emmanuel Chambon
// Last update Sun Jun 14 02:34:11 2015 Emmanuel Chambon
//

#include "AssetManager.hh"
#include "Cube.hh"
#include "GameEngine.hh"
#include "Camera.hh"
#include "Skybox.hh"

/*
** Singleton instanciation
*/
AssetManager    &AssetManager::instance()
{
	static AssetManager *instance = new AssetManager();
	return *instance;
}

AssetManager::AssetManager() : _mutex(std::make_shared<std::mutex>())
{
	std::vector<std::future<void>>        f;

	// Asynchronous load of handlers
	f.push_back(std::async(std::launch::async, std::bind(&AssetManager::loadBoardHandler, this)));
	f.push_back(std::async(std::launch::async, std::bind(&AssetManager::loadSoundHandler, this)));
	f.push_back(std::async(std::launch::async, std::bind(&AssetManager::loadScoreHandler, this)));
	f.push_back(std::async(std::launch::async, std::bind(&AssetManager::loadSaveHandler, this)));

	for (auto i = f.begin(); i != f.end(); i++)
		i->get();

	// Manual load of GDL related stuff due to conflict with async approach
	loadThemeHandler();
	loadModelHandler();
}


/*
** Loading methods
** Each of them are protected by a lock guard
** to avoid race conditions on the _assets variable
*/
void AssetManager::loadBoardHandler()
{
	std::shared_ptr<BoardHandler> handler = std::make_shared<BoardHandler>();

	std::lock_guard<std::mutex> guard(*_mutex);
	_assets["boards"] = handler;
}

void AssetManager::loadThemeHandler()
{
	std::shared_ptr<ThemeHandler> handler = std::make_shared<ThemeHandler>();

	std::lock_guard<std::mutex> guard(*_mutex);
	_assets["themes"] = handler;
}

void AssetManager::loadSoundHandler()
{
	std::shared_ptr<SoundHandler> handler = std::make_shared<SoundHandler>();

	std::lock_guard<std::mutex> guard(*_mutex);
	_assets["sounds"] = handler;
}

void AssetManager::loadScoreHandler()
{
	std::shared_ptr<ScoreHandler> handler = std::make_shared<ScoreHandler>();

	std::lock_guard<std::mutex> guard(*_mutex);
	_assets["scores"] = handler;
}

void AssetManager::loadModelHandler()
{
	std::shared_ptr<ModelHandler> handler = std::make_shared<ModelHandler>();

	std::lock_guard<std::mutex> guard(*_mutex);
	_assets["models"] = handler;
}

void AssetManager::loadSaveHandler()
{
	std::shared_ptr<SaveHandler> handler = std::make_shared<SaveHandler>();

	std::lock_guard<std::mutex> guard(*_mutex);
	_assets["saves"] = handler;
}

/*
** Public acessor
*/
AAsset           &AssetManager::operator[](std::string const &at)
{
	if (_assets.find(at) == _assets.end())
		throw std::out_of_range("Out of range on AssetManager");
	return *_assets[at];
}
