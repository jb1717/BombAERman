//
// ThemeHandler.hh for Biomberman in /home/chambo_e/epitech/cpp_bomberman/src/bomberman/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Fri May 22 21:07:26 2015 Emmanuel Chambon
// Last update Sat May 23 19:39:07 2015 Emmanuel Chambon
//

#include "manager/ThemeHandler.hh"

ThemeHandler::ThemeHandler()
{
	load();
}

ThemeHandler::~ThemeHandler()
{
}

void ThemeHandler::load()
{
	DIR *dir;
	struct dirent *ent;
	// Container for async calls
	std::vector<std::future<void>>  f;

	if ((dir = opendir ("./assets/themes")) != NULL) {
		// bind function to avoid static function
		auto func = std::bind(&ThemeHandler::loadTheme, this, std::placeholders::_1, std::placeholders::_2);
		while ((ent = readdir (dir)) != NULL) {
			if (std::string(ent->d_name)[0] != '.')
				// Asynchronous load
				f.push_back(std::async (std::launch::async, func,
				                        "assets/themes/" + std::string(ent->d_name), ent->d_name));
		}
		try {
			for (auto i = f.begin(); i != f.end(); i++)
				// Asynchronous termination
				i->get();
		} catch (std::invalid_argument &e) {
			std::cerr << e.what() << std::endl;
		}
		closedir (dir);
	} else {
		throw std::runtime_error("Cannot themes folder.");
	}
}

void ThemeHandler::load(std::initializer_list<std::initializer_list<std::string>> const &paths)
{
	for (auto i : paths)
		for (auto x : i)
			std::cout << x << std::endl;
}

void ThemeHandler::loadTheme(std::string const &path, std::string const &name)
{
	std::shared_ptr<Theme> theme = std::make_shared<Theme>(path, name);

	_mutex.lock();
	_themes[name] = theme;
	_mutex.unlock();
}

std::shared_ptr<Theme>               ThemeHandler::operator[](std::string const &at)
{
	if (_themes.find(at) != _themes.end())
		return _themes[at];
	return nullptr;
}

std::shared_ptr<Theme>              ThemeHandler::operator[](ssize_t at)
{
	if (at < 0) {
		for (std::map<std::string, std::shared_ptr<Theme>>::reverse_iterator i = _themes.rbegin();
		     i != _themes.rend(); i++) {
			if (at == 0)
				return (*i).second;
			at++;
		}
		return nullptr;
	} else {
		ssize_t x = 0;
		for (auto i  = _themes.begin(); i != _themes.end(); i++) {
			if (x == at)
				return (*i).second;
			x++;
		}
		return nullptr;
	}
	return nullptr;
}
