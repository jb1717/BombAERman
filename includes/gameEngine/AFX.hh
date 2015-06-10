//
// AFX.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Tue Jun  2 19:41:33 2015 Jamais
// Last update Sat Jun  6 04:42:29 2015 Jamais
//

#ifndef			____AFX_HH___
# define		____AFX_HH___

# include		"ComplexObject.hh"
# include   "Binput.hh"
# include		"Camera.hh"

# define		TRUE_POS(x, y, b) (y * b->getPos.x)

class			AFX : public ComplexObject
{
protected:
  AGameObject*		_currentFrame;

protected:
  size_t		_index;
  float			_timer;
  float			_frameTimer;

public:
  AFX();
  ~AFX();

public:
  virtual void	       	update(gdl::Clock const& clock, Binput& input);
  virtual void	       	update(gdl::Clock const& clock, Binput& input, Camera const& camera);
  void			draw(gdl::AShader& shader, gdl::Clock const& clock);

public:
  void			setTimer(float time);
};

#endif			/* !____AFX_HH___ */
