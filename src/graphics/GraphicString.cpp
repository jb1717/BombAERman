//
// GraphicString.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Wed Jun  3 11:24:34 2015 Jamais
// Last update Fri Jun 12 00:12:18 2015 Jamais
//

#include	"GraphicString.hh"
#include	"AssetManager.hh"

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
  return *this;
}

GraphicString&			GraphicString::operator=(GraphicString const& model)
{
  GeometryFactory	*factory = GeometryFactory::instanciate();
  _text = model.getText();
  clear();
  render(*factory);
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
  _spareParts.clear();
  _text = text;
  auto factory = GeometryFactory::instanciate();
  render(*factory);
}

bool				GraphicString::render(UNUSED GeometryFactory& factory)
{
  auto				asset = AssetManager::instance();
  Geometric*			graphicChar;
  gdl::Texture*			charTexture;
  int				x;
  unsigned int			i;

  x = _text.size() / 2 * -1;
  for (i = 0; i < _text.size(); i++)
    {
      if (_text.substr(i, 1) != " " && _text.substr(i, 1) != ".")
	{
	  try {
	  charTexture = (*THEME((*THEME_HANDLER(asset["themes"]))["fonts"]))[_text.substr(i, 1)];
	  } catch (std::out_of_range e) { std::cout << e.what() << std::endl;}
	  // if (i > _spareParts.size())
	    graphicChar = new Geometric(glm::vec3(_position.x - x, _position.y, _position.z));
	  // else
	  //   {
	  //     graphicChar = _spareParts[i];
	  //     graphicChar->translate(glm::vec3(_position.x - x, _position.y, _position.z));
	  //   }
	  graphicChar->setGeometry(factory.getGeometry(GeometryFactory::VERTICAL_PLANE));
	  graphicChar->setTexture(*charTexture);
	  graphicChar->initialize();
	  push_back(graphicChar);
	}
      x++;
    }
  return true;
}

void				GraphicString::scale(glm::vec3 const& scale)
{
  ComplexObject::scale(scale);
}

void				GraphicString::clear()
{
}
