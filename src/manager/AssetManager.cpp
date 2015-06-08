//
// AssetManager.cpp for Bomberman in /home/chambo_e/epitech/cpp_bomberman/src/bomberman/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Fri May 22 18:04:57 2015 Emmanuel Chambon
// Last update Mon Jun  8 06:39:19 2015 Emmanuel Chambon
//

#include "AssetManager.hh"
#include "Cube.hh"
#include "GameEngine.hh"
#include "Camera.hh"
#include "Skybox.hh"

gdl::Texture* lol;

AssetManager    &AssetManager::instance()
{
    static AssetManager *instance = new AssetManager();
    return *instance;
}

AssetManager::AssetManager() : _mutex(std::make_shared<std::mutex>())
{
	// std::vector<std::future<void>>	f;

	// f.push_back(std::async(std::launch::async, std::bind(&AssetManager::loadBoardHandler, this)));
	// f.push_back(std::async(std::launch::async, std::bind(&AssetManager::loadThemeHandler, this)));
	// f.push_back(std::async(std::launch::async, std::bind(&AssetManager::loadSoundHandler, this)));
	// f.push_back(std::async(std::launch::async, std::bind(&AssetManager::loadScoreHandler, this)));
	// f.push_back(std::async(std::launch::async, std::bind(&AssetManager::loadModelHandler, this)));

	// for (auto i = f.begin(); i != f.end(); i++)
	// 	i->get();

  loadBoardHandler();
  loadThemeHandler();
  loadSoundHandler();
  loadScoreHandler();
  loadModelHandler();
  // Models
    // Scores
    // Saves
	// Settings
      // 	gdl::Texture	*te = new gdl::Texture();
      // 	AGameObject	*cube = new Cube(glm::vec3(0, 0, 0));

      // 	te->load("./assets/themes/default/default.floor.tga");
      // 	lol = te;
      // 	cube->setTexture(*te);
      // 	cube->initialize();

      // 	std::cout << "[[[[[[[[[]]]]]]]]]" << te->getHeight() << std::endl;
      // 	gdl::BasicShader	sh;
      // 	 if (!sh.load(FRAGMENT_SHADER, GL_FRAGMENT_SHADER)
      // || !sh.load(VERTEX_SHADER, GL_VERTEX_SHADER)
      // || !sh.build())
      // 	   std::cout << "Bouh" << std::endl;

      // 	 gdl::Clock		_kikou;
      // 	 Camera	cam;

      // 	 Skybox* sk = new Skybox();
      // 	 glEnable(GL_DEPTH_TEST);
      // 	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      // 	 cam.setupCamera(*V);
      // 	 cam.setPosition(glm::vec3(0, 5, -5));
      // 	 cam.refreshPosition();
      // 	 sh.bind();
      // 	 sh.setUniform("view", cam.getTransformationMatrix());
      // 	 sh.setUniform("projection", cam.getProjectionMatrix());
      // 	 cube->draw(sh, _kikou);
      // 	 sk->draw(sh, _kikou);
      // 	 V->flush();
      // 	 std::cout << (V == NULL ? "LOooser " : "ok") << std::endl;
      // 	 sleep(1);
}

AssetManager::~AssetManager()
{

}

void 			AssetManager::loadBoardHandler()
{
	std::shared_ptr<BoardHandler> handler = std::make_shared<BoardHandler>();

	std::lock_guard<std::mutex> guard(*_mutex);
	_assets["boards"] = handler;
}

void 			AssetManager::loadThemeHandler()
{
	std::shared_ptr<ThemeHandler> handler = std::make_shared<ThemeHandler>();

	std::lock_guard<std::mutex> guard(*_mutex);
	_assets["themes"] = handler;
}

void 			AssetManager::loadSoundHandler()
{
	std::shared_ptr<SoundHandler> handler = std::make_shared<SoundHandler>();

	std::lock_guard<std::mutex> guard(*_mutex);
	_assets["sounds"] = handler;
}

void 			AssetManager::loadScoreHandler()
{
	std::shared_ptr<ScoreHandler> handler = std::make_shared<ScoreHandler>();

	std::lock_guard<std::mutex> guard(*_mutex);
	_assets["scores"] = handler;
}

void 			AssetManager::loadModelHandler()
{
	std::shared_ptr<ModelHandler> handler = std::make_shared<ModelHandler>();

	std::lock_guard<std::mutex> guard(*_mutex);
	_assets["models"] = handler;
}

AAsset           &AssetManager::operator[](std::string const &at)
{
	if (_assets.find(at) == _assets.end())
		throw std::out_of_range("Out of range on AssetManager");
	return *_assets[at];
}
