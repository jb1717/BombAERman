//
// Controller.hh for Bomberman in /home/jibb/rendu/cpp_bomberman/includes
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Sun May  3 16:35:29 2015 Jean-Baptiste Grégoire
// Last update Tue May  5 19:43:20 2015 Jean-Baptiste Grégoire
//

#ifndef CONTROLLER_HH_
# define CONTROLLER_HH_

# include <stdint.h>
# include <sys/stat.h>
# include <strings.h>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include "IInput.hh"
# include "Event.hh"

typedef struct	s_controller
{
  uint32_t	time;
  int16_t	value;
  uint8_t	type;
  uint8_t	number;
}		t_controller;

enum		e_type
  {
    BUTTON = 1,
    JOYSTICK = 2
  };

class		Controller : public IInput
{
public:
  Controller(uint32_t id);
  ~Controller();

public:
  void		handleEvent(bomber::Event &event);
  bool		plugged() const;

private:
  uint32_t	_id;
  bool		_isPlugged;
  std::ifstream	_in;
  t_controller	_ctrler;
  std::string	_ctrlerFile;
  struct stat	_statBuf;
};

#endif // !CONTROLLER_HH_
