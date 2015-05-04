//
// IInput.hh for Bomberman in /home/jibb/rendu/cpp_bomberman/includes
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Sun May  3 15:45:24 2015 Jean-Baptiste Grégoire
// Last update Sun May  3 17:39:50 2015 Jean-Baptiste Grégoire
//

#ifndef IINPUT_HH_
# define IINPUT_HH_

class		IInput
{
public:
  Input();
  virtual ~Input() = 0;

public:
  virtual void	handleEvent(bomber::Event &event) = 0;
};

#endif // !IINPUT_HH_
