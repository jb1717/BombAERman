//
// ModelHandler.cpp for Bomberman in /home/chambo_e/epitech/cpp_bomberman/src/manager/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Mon Jun  1 10:02:54 2015 Emmanuel Chambon
// Last update Wed Jun  3 13:43:20 2015 Emmanuel Chambon
//

#include "ModelHandler.hh"

ModelHandler::ModelHandler()
{
	_videoContext = new VideoContext(1920, 1280, "Afghanistan : 1994 ...");

	_videoContext->init();

	load();
}

ModelHandler::~ModelHandler()
{

}

void ModelHandler::load()
{
	struct dirent *ent;
	DIR *dir;

	if ((dir = opendir ("./assets/models")) != NULL) {
		try {
			while ((ent = readdir (dir)) != NULL) {
				if (std::string(ent->d_name)[0] != '.' && std::regex_match(ent->d_name, std::regex("((.*)\\.(fbx))")))
					loadModel("assets/models/" + std::string(ent->d_name), ent->d_name);
			}
		} catch (std::invalid_argument &e) {
			std::cerr << e.what() << std::endl;
		}
		closedir (dir);
	} else {
		throw std::runtime_error("Cannot open models folder.");
	}
	delete _videoContext;
}

void ModelHandler::loadModel(std::string const &path, std::string const &name)
{
	std::shared_ptr<AGameModel> model = std::make_shared<AGameModel>(path);

	std::lock_guard<std::mutex> guard(_mutex);
	_models[name] = model;
}

AGameModel                  &ModelHandler::operator[](std::string const &at)
{
	if (_models.find(at) == _models.end())
		throw std::out_of_range("Out of range ModelHandler.");
	return *_models[at];
}
