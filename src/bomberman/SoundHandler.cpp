//
// SoundHandler.cpp for  in /home/chambo_e/epitech/cpp_bomberman/src/bomberman/
//
// Made by Emmanuel Chambon
// Login   <chambo_e@epitech.eu>
//
// Started on  Sun May 24 08:37:30 2015 Emmanuel Chambon
// Last update Sun May 24 18:05:19 2015 Emmanuel Chambon
//

#include "manager/SoundHandler.hh"

SoundHandler::SoundHandler()
{
	fmodError(FMOD::System_Create(&_system));
	fmodError(_system->init(32, FMOD_INIT_NORMAL, 0));
	load();
}

SoundHandler::~SoundHandler()
{
	for (auto i : _sounds) {
		fmodError(i.second->release());
	}
    _sounds.clear();
	fmodError(_system->close());
	fmodError(_system->release());
}

void                    SoundHandler::loadSound(std::string const &file)
{
	FMOD::Sound         *sound = nullptr;

	fmodError(_system->createSound(file.c_str(), FMOD_DEFAULT | FMOD_CREATESTREAM, nullptr, &sound));

	std::smatch         m;

	if (std::regex_search(file, m, std::regex("[^/]*$")))
	{
		std::string     res(m[0]);
		std::regex      sep("\\.");
		std::regex_token_iterator<std::string::iterator> end;
		std::regex_token_iterator<std::string::iterator> token(res.begin(),
		                                                       res.end(), sep, -1);

		if (std::distance(token, end) != 2)
			throw std::invalid_argument(file + ": Invalid file.");
		std::string     asset(*token);

		std::lock_guard<std::mutex> lock(_mutex);
		_sounds[asset] = sound;
	}
}

void                    SoundHandler::load()
{
	DIR                 *dir;
	struct dirent       *ent;
	std::vector<std::future<void>>  f;

	if ((dir = opendir ("./assets/sounds")) != NULL) {
		auto func = std::bind(&SoundHandler::loadSound, this, std::placeholders::_1);
		while ((ent = readdir (dir)) != NULL) {
			if (std::string(ent->d_name)[0] != '.')
				f.push_back(std::async (std::launch::async, func,
				                        "assets/sounds/" + std::string(ent->d_name)));
		}
		try {
			for (auto i = f.begin(); i != f.end(); i++)
				i->get();
		} catch (std::invalid_argument &e) {
			std::cerr << e.what() << std::endl;
		}
		closedir (dir);
	} else {
		std::cerr << "Cannot open sounds folder. They will not be available" << std::endl;
	}
}

void                    SoundHandler::pause()
{
	bool                paused;

	fmodError(_channel->getPaused(&paused));
	fmodError(_channel->setPaused(!paused));
}

void                    SoundHandler::resume()
{
	pause();
}

void                    SoundHandler::stop()
{
	bool                paused;

	fmodError(_channel->isPlaying(&paused));
	if (paused)
		fmodError(_channel->stop());
}

void                    SoundHandler::play(FMOD::Sound *sound)
{
	fmodError(_system->playSound(sound, 0, false, &_channel));
    fmodError(_channel->setVolume(_backgroundVolume));
}

void                    SoundHandler::playSample(FMOD::Sound *sound)
{
	fmodError(_system->playSound(sound, 0, false, &_channelSample));
    fmodError(_channelSample->setVolume(_foregroundVolume));
}

bool                    SoundHandler::isPlaying()
{
	bool                paused;

	fmodError(_channel->isPlaying(&paused));
	return paused;
}

void                    SoundHandler::setForegroundVolume(float volume)
{
    _foregroundVolume = volume;
    fmodError(_channelSample->setVolume(_foregroundVolume));
}

void                    SoundHandler::setBackgroundVolume(float volume)
{
    _backgroundVolume = volume;
    fmodError(_channel->setVolume(_backgroundVolume));
}

FMOD::Sound             *SoundHandler::operator[](std::string const &at)
{
	if (_sounds.find(at) == _sounds.end())
		throw std::out_of_range("Out of range ThemeHandler.");
	return _sounds[at];
}

void                    SoundHandler::fmodError(FMOD_RESULT res)
{
	if (res != FMOD_OK)
		throw std::runtime_error("A problem happened with fmod. Please check your sounds assets.");
}
