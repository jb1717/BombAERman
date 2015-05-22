//
// Bomberman.cpp for  in /home/chambo_e/epitech/cpp_bomberman/src/bomberman
//
// Made by Emmanuel Chambon
// chambo_e  <chambon.emmanuel@gmail.com>
//
// Started on  Tue May 19 11:18:08 2015 Emmanuel Chambon
// Last update Wed May 20 23:42:55 2015 Emmanuel Chambon
//

#include "Bomberman.hh"
#include "BoardHandler.hh"

Bomberman::Bomberman()
	: _x(1820), _y(980), _window(_x, _y, "BombAERman")
{
	setWidthHeight();

    _window.init();

	// SETBACKGROUND(_window);

	// MAINUI(_window, x, y);

	BoardHandler();

	std::this_thread::sleep_for (std::chrono::seconds(2)); // Debug purpose. Will be removed

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
				_window.setScreenWidth(_x);
				_window.setScreenHeight(_y);
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
