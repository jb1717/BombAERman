//
// Controller.cpp for Controller in /home/jibb/rendu/cpp_bomberman
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Sun May  3 16:38:09 2015 Jean-Baptiste Grégoire
// Last update Tue May  5 20:00:52 2015 Jean-Baptiste Grégoire
//

#include "Controller.hh"

Controller::Controller(uint32_t id) : _id(id), _isPlugged(false)
{
  std::stringstream	tmp;

  tmp << "/dev/input/js";
  tmp << id;
  _ctrlerFile.assign(tmp.str());
  _in.open(_ctrlerFile.c_str(), std::ios::in);
  if (_in.good() == false)
    std::cout << "Controller " << id << "not plugged !" << std::endl;
  else
    _isPlugged = true;
  bzero(&_ctrler, sizeof(t_controller));
}

void		Controller::handleEvent(bomber::Event &event)
{
  if (_isPlugged == false && stat(_ctrlerFile.c_str(), &_statBuf) == 0)
    {
      _in.close();
      _in.open(_ctrlerFile.c_str(), std::ios::in);
      if (_in.good())
	{
	  _isPlugged = true;
	  event.type = bomber::Event::ControllerPlugged;
	}
    }
  _in.read(reinterpret_cast<char *>(&_ctrler), sizeof(t_controller));
  if (_in.good() == false)
    {
      event.type = bomber::Event::ControllerUnplugged;
      _isPlugged = false;
    }
  else
    {
      if (_ctrler.type == JOYSTICK)
	event.type = bomber::Event::JoystickMove;
      else
	{
	  if (_ctrler.value == 1)
	    event.type = bomber::Event::KeyPressed;
	  else
	    event.type = bomber::Event::KeyReleased;
	}
      switch (_ctrler.number)
	{
	case 0:
	  if (event.type == bomber::Event::JoystickMove)
	    event.key = (_ctrler.value > 0 ? bomber::Event::JoyMiddleRight : bomber::Event::JoyMiddleLeft);
	  else
	    event.key = bomber::Event::XboxY;
	  break;
	case 1:
	  if (event.type == bomber::Event::JoystickMove)
	    event.key = (_ctrler.value > 0 ? bomber::Event::JoyMiddleDown : bomber::Event::JoyMiddleUp);
	  else
	    event.key = bomber::Event::XboxB;
	  break;
	case 2:
	  if (event.type == bomber::Event::JoystickMove)
	    event.key = (_ctrler.value > 0 ? bomber::Event::JoyRightRight : bomber::Event::JoyRightLeft);
	  else
	    event.key = bomber::Event::XboxA;
	  break;
	case 3: event.key  = (event.type == bomber::Event::JoystickMove ? bomber::Event::TriggerLB : bomber::Event::XboxX); break;
	case 4: event.key = (event.type == bomber::Event::JoystickMove ? bomber::Event::TriggerRB : bomber::Event::TriggerLT); break;
	case 5:
	  if (event.type == bomber::Event::JoystickMove)
	    event.key = (_ctrler.value > 0 ? bomber::Event::JoyRightDown : bomber::Event::JoyRightUp);
	  else
	    event.key = bomber::Event::TriggerRT;
	  break;
	case 6: event.key = (_ctrler.value > 0 ? bomber::Event::JoyLeftRight : bomber::Event::JoyLeftLeft); break;
	case 7: event.key = (_ctrler.value > 0 ? bomber::Event::JoyLeftDown : bomber::Event::JoyLeftUp); break;
	case 8: event.key = bomber::Event::Start; break;
	case 9: event.key = bomber::Event::Select; break;
	case 10: event.key = bomber::Event::Start; break;
	case 11: event.key = bomber::Event::Undifined; break;
	case 12: event.key = bomber::Event::Power; break;
	case 13: event.key = bomber::Event::Undifined; break;
	default: event.key = bomber::Event::Undifined; break;
	}
    }
  event.value = _ctrler.value;
}

bool		Controller::plugged() const
{
  return (_isPlugged);
}

Controller::~Controller()
{
  _in.close();
}
