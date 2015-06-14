//
// ThemeHandler.hh for Biomberman in /home/chambo_e/epitech/cpp_bomberman/src/bomberman/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Fri May 22 21:07:26 2015 Emmanuel Chambon
// Last update Sun Jun 14 02:57:51 2015 Emmanuel Chambon
//

#include "ThemeHandler.hh"

ThemeHandler::ThemeHandler()
{
	load();
}

/*
** Load all themes located in assets/themes
*/
void ThemeHandler::load()
{
	DIR *dir;
	struct dirent *ent;

	if ((dir = opendir ("./assets/themes")) != NULL) {
		try {
			while ((ent = readdir (dir)) != NULL) {
				if (std::string(ent->d_name)[0] != '.')
					loadTheme("assets/themes/" + std::string(ent->d_name), ent->d_name);
			}
		} catch (std::invalid_argument &e) {
			std::cerr << e.what() << std::endl;
		}
		closedir (dir);
	} else {
		throw std::runtime_error("Cannot close themes folder.");
	}
}

/*
** Load theme located at [path]
*/
void ThemeHandler::loadTheme(std::string const &path, std::string const &name)
{
	std::shared_ptr<Theme> theme = std::make_shared<Theme>(path, name);

	// Lock to avoid race condition
	std::lock_guard<std::mutex> guard(_mutex);
	_themes[name] = theme;
}

// Return vector of themes names
std::vector<std::string>                ThemeHandler::getThemes() const
{
	std::vector<std::string> ret;

	for (auto i : _themes)
		ret.push_back(i.first);
	return ret;
}

/*
** Return theme [at]
*/
Theme               &ThemeHandler::operator[](std::string const &at)
{
	if (_themes.find(at) == _themes.end())
		throw std::out_of_range("Out of range ThemeHandler.");
	return *_themes[at];
}

/*
** Return theme [at]
*/
Theme              &ThemeHandler::operator[](long int at)
{
	if (at < 0) {
		for (std::map<std::string, std::shared_ptr<Theme>>::reverse_iterator i = _themes.rbegin();
		     i != _themes.rend(); i++) {
			if (at == 0)
				return *(*i).second;
			at++;
		}
		throw std::out_of_range("Out of range ThemeHandler.");
	} else {
		ssize_t x = 0;
		for (auto i  = _themes.begin(); i != _themes.end(); i++) {
			if (x == at)
				return *(*i).second;
			x++;
		}
		throw std::out_of_range("Out of range ThemeHandler.");
	}
	throw std::invalid_argument("Invalid Argument ThemeHandler.");
}
