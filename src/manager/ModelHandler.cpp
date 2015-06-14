//
// ModelHandler.cpp for Bomberman in /home/chambo_e/epitech/cpp_bomberman/src/manager/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Mon Jun  1 10:02:54 2015 Emmanuel Chambon
// Last update Sun Jun 14 02:41:23 2015 Emmanuel Chambon
//

#include "ModelHandler.hh"

ModelHandler::ModelHandler() : _videoContext(VideoContext::instanciate())
{
	load();
}

/*
** Load all models located in assets/models
*/
void ModelHandler::load()
{
	struct dirent *ent;
	DIR *dir;

	if ((dir = opendir ("./assets/models")) != NULL) {
		try {
			while ((ent = readdir (dir)) != NULL) {
				if (std::string(ent->d_name)[0] != '.' && std::regex_match(ent->d_name, std::regex("((.*)\\.(fbx))")))
					loadModel("assets/models/" + std::string(ent->d_name), ent->d_name);
				// _models[ent->d_name] = new AGameModel("assets/models/" + std::string(ent->d_name));;
			}
		} catch (std::invalid_argument &e) {
			std::cerr << e.what() << std::endl;
		}
		closedir (dir);
	} else {
		throw std::runtime_error("Cannot open models folder.");
	}
}

/*
** Load the model located at [path]
** and store it as [name]
*/
void ModelHandler::loadModel(std::string const &path, std::string const &name)
{
	std::shared_ptr<AGameModel> model = std::make_shared<AGameModel>(path);

	_models[name] = model;
}

/*
** Return the [at] model
*/
AGameModel                  &ModelHandler::operator[](std::string const &at)
{
	if (_models.find(at) == _models.end())
		throw std::out_of_range("Out of range ModelHandler.");
	return *_models[at];
}
