//
// Controller.cpp for Controller in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Sun May  3 16:38:09 2015 Jean-Baptiste Grégoire
// Last update Sun May  3 23:17:23 2015 Jean-Baptiste Grégoire
//

#include "Controller.hh"

Controller::Controller(uint8_t id) : _id(id), _fd(0), _isPlugged(false)
{
  std::string	tmp("/dev/input/js");

  tmp += std::string(id);
  if ((_fd = open(tmp.c_str(), O_RDONLY)) == -1)
    std::cout << "Controller " << id << "not plugged !" << std::endl;
  else
    _isPlugged = true;
  bzero(&_ctrler, sizeof(t_controller));
}

void		Controller::handleEvent(bomber::Event &event)
{
  if (read(_fd, &_ctrler, sizeof(t_controller)) == -1)
    {
      event.type = bomber::ControllerUnplugged;
      _isPlugged = false;
    }
  else if (_isPlugged == false)
    {
      _isPlugged = true;
      event.type = bomber::ControllerPlugged;
    }
  else
    {
      if (_ctrler.type == JOYSTICK)
	event.type = bomber::JoystickMove;
      else
	{
	  if (_ctrler.value == 1)
	    event.type = bomber::KeyPressed;
	  else
	    event.type = bomber::KeyReleased;
	}
      switch (_ctrler.number)
	{
	case 0: event.key = bomber::XboxY; break;
	case 1: event.key = bomber::XboxB; break;
	case 2: event.key = bomber::XboxA; break;
	case 3: event.key = bomber::XboxX; break;
	}
    }
}

bool		Controller::plugged() const
{
  return (_isPlugged);
}

Controller::~Controller()
{
  close(_fd);
}
