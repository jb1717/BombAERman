//
// Event.hh for Bomberman in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Sun May  3 17:40:33 2015 Jean-Baptiste Grégoire
// Last update Tue May  5 15:53:13 2015 Jean-Baptiste Grégoire
//

#ifndef EVENT_HH_
# define EVENT_HH_

# include <stdint.h>

namespace	bomber
{
  class		Event
  {
  public:
    enum	EventType
      {
	ControllerPlugged,
	ControllerUnplugged,
	KeyPressed,
	KeyReleased,
	JoystickMove
      };

    enum	KeyID
      {
	JoyLeftUp,
	JoyLeftDown,
	JoyLeftLeft,
	JoyLeftRight,
	JoyRightUp,
	JoyRightDown,
	JoyRightLeft,
	JoyRightRight,
	JoyMiddleUp,
	JoyMiddleDown,
	JoyMiddleLeft,
	JoyMiddleRight,
	ControllerUp,
	ControllerDown,
	ControllerLeft,
	ControllerRight,
	Free1,
	Free2,
	Free3,
	Free4,
	TriggerLB,
	TriggerRB,
	TriggerLT,
	TriggerRT,
	Start,
	Select,
	Power,
	Undifined
      };

  public:
  	Event &operator=(Event const &o);

  public:
    EventType	type;
    KeyID	key;
    int16_t	value;
  };
}

#endif // !EVENT_HH_
