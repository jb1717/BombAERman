//
// Controller.hh for Bomberman in /home/jibb/rendu/cpp_bomberman/includes
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Sun May  3 16:35:29 2015 Jean-Baptiste Grégoire
// Last update Sun May  3 17:54:39 2015 Jean-Baptiste Grégoire
//

#ifndef CONTROLLER_HH_
# define CONTROLLER_HH_

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
  Controller();
  ~Controller();

public:
  void		handleEvent(bomber::Event &event);
  bool		plugged() const;

private:
  uint8_t	_id;
  int		_fd;
  bool		_isPlugged;
  t_controller	_ctrler;
};

#endif // !CONTROLLER_HH_
