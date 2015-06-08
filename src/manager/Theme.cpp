//
// Theme.cpp for Bomberman in /home/chambo_e/epitech/cpp_bomberman/src/bomberman/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Sat May 23 04:33:27 2015 Emmanuel Chambon
// Last update Mon Jun  8 06:06:10 2015 Emmanuel Chambon
//

#include "Theme.hh"

Theme::Theme(std::string const &path, std::string const &name)
	: _name(name)
{
	load(path);
}

Theme::~Theme()
{

}

void Theme::loadTheme(std::string const &file)
{
	std::smatch m;
	std::regex rg("[^/]*$");

	if (std::regex_search(file, m, std::regex("[^/]*$")))
	{
	  std::string res(m[0]);
	  std::regex sep("\\.");
	  std::regex_token_iterator<std::string::iterator> end;
	  std::regex_token_iterator<std::string::iterator> token(res.begin(),
								 res.end(), sep, -1);

	  if (std::distance(token, end) != 3)
	    throw std::invalid_argument(file + ": Invalid file.");
	  if (*token++ != _name)
	    throw std::invalid_argument(file + ": Invalid file.");
	  std::string asset(*token);

	  std::shared_ptr<gdl::Texture>   txtr = std::make_shared<gdl::Texture>();
	  txtr->load(file);
	  std::lock_guard<std::mutex> guard(_mutex);
	  _textures[asset] = txtr;
	  if (_textures[asset]->getHeight() == 0)
	    throw std::invalid_argument(file + ": Invalid texture file.");
	}
}

void Theme::load(std::string const &path)
{
	DIR *dir;
	struct dirent *ent;
	// Container for async calls
	std::vector<std::future<void>>  f;

	if ((dir = opendir (path.c_str())) != NULL) {
		// bind function to avoid static function
		auto func = std::bind(&Theme::loadTheme, this, std::placeholders::_1);
		while ((ent = readdir (dir)) != NULL) {
		try {
		  if (std::string(ent->d_name)[0] != '.')
		    // Asynchronous load
		    // f.push_back(std::async (std::launch::async, func,
		    //                         path + "/" + std::string(ent->d_name)));
		    loadTheme(path + "/" + std::string(ent->d_name));
		} catch (std::invalid_argument &e) {
		  std::cerr << e.what() << std::endl;
		}
		}
		// 	for (auto i = f.begin(); i != f.end(); i++)
		// 		// Asynchronous termination
		// 		i->get();
		closedir (dir);
	} else {
		throw std::runtime_error("Cannot open theme folder: " + path);
	}
}

std::vector<std::string>				Theme::getTextures() const
{
	std::vector<std::string> ret;

	for (auto i : _textures)
		ret.push_back(i.first);
	return ret;
}

gdl::Texture                                    *Theme::operator[](std::string const &at)
{
	if (_textures.find(at) == _textures.end())
		throw std::out_of_range("Out of range Textures.");
	return _textures[at].get();
}
