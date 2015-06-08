//
// GraphicString.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Wed Jun  3 11:24:34 2015 Jamais
// Last update Sun Jun  7 02:58:18 2015 Jamais
//

#include	"GraphicString.hh"

GraphicString::GraphicString() : ComplexObject(), _text(""), _size(1)
{}

GraphicString::GraphicString(std::string const& text) : ComplexObject(), _text(text), _size(1)
{
  GeometryFactory	*factory = GeometryFactory::instanciate();
  render(*factory);
}

GraphicString::GraphicString(std::string const& text, unsigned int size) : ComplexObject(), _text(text), _size(size)
{
  GeometryFactory	*factory = GeometryFactory::instanciate();
  render(*factory);
}

GraphicString::~GraphicString()
{}

GraphicString&			GraphicString::operator=(std::string const& modelString)
{
  GeometryFactory	*factory = GeometryFactory::instanciate();
  _text = modelString;
  clear();
  render(*factory);
  delete factory;
  return *this;
}

GraphicString&			GraphicString::operator=(GraphicString const& model)
{
  GeometryFactory	*factory = GeometryFactory::instanciate();
  _text = model.getText();
  clear();
  render(*factory);
  delete factory;
  return *this;
}

Geometric*			GraphicString::operator[](unsigned int index)
{
  return _spareParts[index];
}

GraphicString&			GraphicString::operator+(std::string const& modelString)
{
  _text += modelString;
  return *this;
}

std::string			GraphicString::getText() const
{
  return _text;
}

void				GraphicString::setText(std::string const& text)
{
  _text = text;
}

bool				GraphicString::render(UNUSED GeometryFactory& factory)
{
  Geometric*			graphicChar;
  int				x;

  x = _text.size() / 2 * -1;
  for (unsigned int i = 0; i < _text.size(); i++)
    {
      gdl::Texture*			lok = new gdl::Texture();
      if (_text.substr(i, 1) != " ")
	{
	  lok->load("./assets/fonts/" + _text.substr(i, 1) + ".tga");
	  graphicChar = new Geometric(glm::vec3(_position.x - x, 5, 5));
	  graphicChar->setGeometry(factory.getGeometry(GeometryFactory::VERTICAL_PLANE));
	  graphicChar->setTexture(*lok);
	  //	  graphicChar->initialize();
	  push_back(graphicChar);
	}
      x++;
    }
  return true;
}

void				GraphicString::clear()
{
  // for (auto i = _spareParts.begin(); i != _spareParts.end(); i++)
  //   {
  //     delete (*i);
  //   }
  //  _spareParts.clear();
}
