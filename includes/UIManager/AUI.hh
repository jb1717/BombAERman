//
// AUI.hh for BombAERman in /home/tommy/Dropbox/Epitech/2ème Année/cpp_bomberman/includes/UIManager/
//
// Made by TommyStarK
// Login   <milox_t@epitech.eu>
//
// Started on  Sat May 23 22:57:54 2015 TommyStarK
// Last update Sat Jun 13 10:23:54 2015 TommyStarK
//

#ifndef  _AUI_HH_
# define _AUI_HH_

# include <tuple>
# include <string>
# include <functional>
# include "Input.hh"
# include "Binput.hh"
# include "Clock.hh"
# include "Camera.hh"
# include "Texture.hh"
# include "Settings.hh"
# include "AssetManager.hh"
# include "gameEngine/graphics.hh"
# include "gameEngine/Cube.hh"
# include "gameEngine/AGameObject.hh"
# include "gameEngine/GameEngine.hh"
# include "gameEngine/VideoContext.hh"
# include "gameEngine/GeometryFactory.hh"
# include "gameEngine/GraphicString.hh"

typedef std::tuple<bool, std::string>  stateUI;


class               AUI
{
public:
  virtual ~AUI() {};


// private necessary attributes to display & catch events.
protected:
  bool                        _isRunning;
  std::string                 _name;
  gdl::Clock                  _clock;
  Binput                      _input;

// Private display attributes.
protected:
    Camera                    _camera;
    gdl::BasicShader          _shader;
    GeometryFactory           *_factory;
    VideoContext              *_window;

protected:
    virtual void              updateContext() = 0;

// Public getters & setters to manage UI by its own name.
public:
  void                        setName(const std::string &);
  std::string                 getName() const;

public:
  virtual void                launch() = 0;
  virtual stateUI             handlerEvent() = 0;

};


#endif /* end of include guard: _AUI_HH_ */
