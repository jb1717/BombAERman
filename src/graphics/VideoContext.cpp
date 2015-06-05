//
// VideoContext.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 02:17:07 2015 Jamais
// Last update Fri Jun  5 18:40:17 2015 Jamais
//

#include	"VideoContext.hh"

VideoContext*	VideoContext::instanciate(unsigned int screenWidth, unsigned int screenHeight, const std::string windowName)
{
  static VideoContext	*vContext = new VideoContext(screenWidth, screenHeight, windowName);
  return vContext;
}

VideoContext::VideoContext(unsigned int screenWidth, unsigned int screenHeight, const std::string windowName) :
  _screenWidth(screenWidth), _screenHeight(screenHeight), _windowName(windowName)
{}

VideoContext::~VideoContext()
{
  stop();
}

bool		VideoContext::init()
{
  if (start(_screenWidth, _screenHeight, _windowName) == false)
    return false;
  // glEnable(GL_DEPTH_TEST);
  return true;
}

bool		VideoContext::init(int initFlags, int windowsFlags)
{
  if (start(_screenWidth, _screenHeight, _windowName, initFlags, windowsFlags) == false)
    return false;
  glEnable(GL_DEPTH_TEST);
  return true;
}

void		VideoContext::updateContext(gdl::Clock& clock, gdl::Input &input) const
{
  updateInputs(input);
  updateClock(clock);
}

void		VideoContext::setScreenWidth(unsigned int screenWidth)
{
  _screenWidth = screenWidth;
}

void		VideoContext::setScreenHeight(unsigned int screenHeight)
{
  _screenHeight = screenHeight;
}

void		VideoContext::setWindowName(const std::string& windowName)
{
  _windowName = windowName;
}

unsigned int	VideoContext::getScreenWidth() const
{
  return _screenWidth;
}

unsigned int	VideoContext::getScreenHeight() const
{
  return _screenHeight;
}
