//
// IInput.hh for Bomberman in /home/jibb/rendu/cpp_bomberman/includes
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Sun May  3 15:45:24 2015 Jean-Baptiste Grégoire
// Last update Tue May  5 14:33:45 2015 Jean-Baptiste Grégoire
//

#ifndef IINPUT_HH_
# define IINPUT_HH_

# include "Event.hh"

class		IInput
{
public:
  IInput() {}
  virtual ~IInput() {}

public:
  virtual void	handleEvent(bomber::Event &event) = 0;
};

#endif // !IINPUT_HH_
