//
// VideoContext.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 17 00:54:03 2015 Jamais
// Last update Thu Jun  4 19:58:25 2015 Jamais
//

#ifndef			___VIDEO_CONTEXT_HH___
# define		___VIDEO_CONTEXT_HH___

# include		"graphics.hh"

class			VideoContext : public gdl::SdlContext
{
protected:
  unsigned int		_screenWidth;
  unsigned int		_screenHeight;
  std::string		_windowName;

public:
  VideoContext(unsigned int screenWidth = 800, unsigned int screenHeight = 600, const std::string windowName = "");
  ~VideoContext();

public:
  bool			init();
  bool			init(int initFlags/* = SDL_INIT_VIDEO*/, int windowsFlags/* = SDL_WINDOW_OPENGL*/);
  void			updateContext(gdl::Clock &clock, gdl::Input& input) const;

public:
  void			setScreenWidth(unsigned int screenWidth);
  void			setScreenHeight(unsigned int screenHeight);
  void			setWindowName(const std::string& windowName);

public:
  unsigned int		getScreenWidth() const;
  unsigned int		getScreenHeight() const;

};

#endif			/* !___VIDEO_CONTEXT_HH___ */
