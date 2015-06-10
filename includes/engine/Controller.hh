//
// Controller.hh for Bomberman in /home/jibb/rendu/cpp_bomberman/includes
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Sun May  3 16:35:29 2015 Jean-Baptiste Grégoire
// Last update Wed Jun 10 13:26:09 2015 Jean-Baptiste Grégoire
//

#ifndef CONTROLLER_HH_
# define CONTROLLER_HH_

# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/stat.h>
# include <strings.h>
# include <sys/file.h>
# include <errno.h>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <algorithm>
# include "Event.hh"

# define DEAD_ZONE    0.5
# define JOY_MAX_VAL  32767

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

class		Controller
{
public:
  Controller();
  ~Controller();

public:
  bool    handleEvent(bomber::Event &event, bomber::Event::KeyID key);
  bool		plugged() const;
  void    controllerUpdate();

protected:
  static void    qualifyEvent(t_controller *ctrler, bomber::Event &event);
  void          resetAxis(int key);

protected:
  uint32_t	_id;
  int       _fd;
  bool		_isPlugged;
  t_controller	_ctrler;
  std::string	_ctrlerFile;
  struct stat	_statBuf;
  std::vector<bomber::Event> _state;
};

#endif // !CONTROLLER_HH_
