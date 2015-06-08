//
// GraphicString.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Wed Jun  3 11:24:34 2015 Jamais
// Last update Mon Jun  8 10:01:44 2015 Jamais
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
  auto				asset = AssetManager::instance();
  Geometric*			graphicChar;
  gdl::Texture*			charTexture;
  int				x;

  x = _text.size() / 2 * -1;
  for (unsigned int i = 0; i < _text.size(); i++)
    {
      if (_text.substr(i, 1) != " ")
	{
	  try {
	  charTexture = (*THEME((*THEME_HANDLER(asset["themes"]))["fonts"]))[_text.substr(i, 1)];
	  } catch (std::out_of_range e) { std::cout << e.what() << std::endl;}
	  graphicChar = new Geometric(glm::vec3(_position.x - x, 0, 0));
	  graphicChar->setGeometry(factory.getGeometry(GeometryFactory::VERTICAL_PLANE));
	  graphicChar->setTexture(*charTexture);
	  graphicChar->initialize();
	  push_back(graphicChar);
	}
      x++;
    }
  std::cout << x << std::endl;
  return true;
}

void				GraphicString::scale(glm::vec3 const& scale)
{
  ComplexObject::scale(scale);
  for (size_t i = 0; i < _spareParts.size(); i++)
    {
      _spareParts[i]->translate(glm::vec3(i * scale.x * (i < _spareParts.size() ? 1 : -1), 0, -2));
    }
}

void				GraphicString::clear()
{
  // for (auto i = _spareParts.begin(); i != _spareParts.end(); i++)
  //   {
  //     delete (*i);
  //   }
  //  _spareParts.clear();
}
