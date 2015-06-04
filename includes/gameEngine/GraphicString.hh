//
// GraphicString.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Fri May 29 02:34:39 2015 Jamais
// Last update Wed Jun  3 20:08:31 2015 Jamais
//

#ifndef			___GRAPHIC_STRING_HH___
# define		___GRAPHIC_STRING_HH___

# include		"graphics.hh"

# include		"AGameObject.hh"
# include		"ComplexObject.hh"
# include		"GeometryFactory.hh"

class			GraphicString : public ComplexObject
{
protected:
  std::string		_text;
  int			_size;

public:
  GraphicString();
  GraphicString(std::string const& text);
  GraphicString(std::string const& text, unsigned int size);
  ~GraphicString();

public:
  GraphicString&	operator=(std::string const& modelString);
  GraphicString&	operator=(GraphicString const& model);
  Geometric*		operator[](unsigned int index);
  GraphicString&	operator+(std::string const& modelString);

public:
  std::string		getText() const;

public:
  void			setText(std::string const& text);

public:
  bool			render(GeometryFactory& factory);

};

#endif			/* !___GRAPHIC_STRING_HH___ */
