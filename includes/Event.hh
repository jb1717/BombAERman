//
// Event.hh for Bomberman in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Sun May  3 17:40:33 2015 Jean-Baptiste Grégoire
// Last update Sun May  3 17:54:20 2015 Jean-Baptiste Grégoire
//

#ifndef EVENT_HH_
# define EVENT_HH_

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
	ControllerUp,
	ControllerDown,
	ControllerLeft,
	ControllerRight,
	XboxA,
	XboxB,
	XboxX,
	XboxY,
	TriggerLB,
	TriggerRB,
	TriggerLT,
	TriggetRT
      };

  public:
    EventType	type;
    KeyID	key;
  };
}

#endif // !EVENT_HH_
