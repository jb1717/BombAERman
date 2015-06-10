//
// Binput.hh for bomberman in /home/jibb/rendu/cpp_bomberman/includes/engine
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Mon Jun  8 17:51:08 2015 Jean-Baptiste Grégoire
// Last update Tue Jun  9 16:30:27 2015 Jean-Baptiste Grégoire
//

#ifndef BINPUT_HH_
# define BINPUT_HH_

# include "SdlContext.hh"
# include "Controller.hh"

class Binput : public Controller
{
public:
	Binput();
	~Binput();

public:
	gdl::Input	_default;
};

#endif /* !BINPUT_HH_ */
