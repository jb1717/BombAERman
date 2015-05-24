//
// Bomberman.cpp for  in /home/chambo_e/epitech/cpp_bomberman/src/bomberman
//
// Made by Emmanuel Chambon
// chambo_e  <chambon.emmanuel@gmail.com>
//
// Started on  Tue May 19 11:18:08 2015 Emmanuel Chambon
// Last update Wed May 20 23:42:55 2015 TommyStarK
//

#include "Bomberman.hh"

Bomberman::Bomberman()
	: _x(1820), _y(980)
{
	setWidthHeight();

	// _ui = new LauncherUI(_x, _y, "BombAERman");

	/*
	**
	** DEMO ASSETMANAGER
	**
	*/

	auto asset = AssetManager();

	// THEMES
	auto themes = THEME_HANDLER(asset["themes"]);

	auto __attribute__((unused)) first_theme = THEME((*themes)[(*themes).getThemes()[0]]); 	// TO ACCESS A THEME
	auto __attribute__((unused)) same_theme = THEME((*themes)["fantasy"]); 					// TO ACCESS A THEME WITH IT NAME

	auto __attribute__((unused)) first_texture_of_first_theme = TEXTURE((*first_theme)[(*first_theme).getTextures()[0]]);
	auto __attribute__((unused)) same_texture_of_first_theme = TEXTURE((*first_theme)["floor1"]);

	auto __attribute__((unused)) direct_access_first_texture = (*THEME((*THEME_HANDLER(asset["themes"]))["fantasy"]))["floor1"];

	// BOARDS
	auto __attribute__((unused)) boards = BOARD_HANDLER(asset["boards"]);
	auto __attribute__((unused)) first_board = BOARD((*boards)[0]);

	auto __attribute__((unused)) direct_access_first_board = BOARD((*BOARD_HANDLER(asset["boards"]))[0]);

	// SOUNDS
	auto sounds = SOUND_HANDLER(asset["sounds"]);

	sounds->play((*sounds)["dimmi"]);

	while (sounds->isPlaying());

	/*
	**
	**
	**
	*/

	//	std::this_thread::sleep_for (std::chrono::seconds(10)); // Debug purpose. Will be removed
}

Bomberman::~Bomberman()
{
}

/*
** Define multiple instance of method for different platforms
*/
#if __linux
void Bomberman::setWidthHeight()
{
	FILE *cmd = popen("xdpyinfo  | grep 'dimensions:'", "r");

	if (cmd)
	{
		char buffer[1024] = { 0 };
		try {
			std::string res(fgets(buffer, sizeof(buffer), cmd));
			std::smatch m;

			if (std::regex_search(res, m, std::regex("([0-9])\\w+")))
			{
				std::string res(m[0]);
				std::regex  sep("x");
				std::regex_token_iterator<std::string::iterator> end;
				std::regex_token_iterator<std::string::iterator> token(res.begin(),
				                                                       res.end(), sep, -1);
				_x = std::stoi(*token++) - 100;
				_y = std::stoi(*token++) - 100;
			}
			pclose(cmd);
		} catch (std::exception& e) {
			std::cout << "Cannot detect display resolution. Default value will be used" << std::endl;
		}
	}
}

#else // if another OS
void Bomberman::setWidthHeight()
{
}

#endif
