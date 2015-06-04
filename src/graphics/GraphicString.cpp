//
// GraphicString.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Wed Jun  3 11:24:34 2015 Jamais
// Last update Thu Jun  4 01:17:35 2015 Jamais
//

#include	"GraphicString.hh"

GraphicString::GraphicString() : ComplexObject(), _text(""), _size(1)
{}

GraphicString::GraphicString(std::string const& text) : ComplexObject(), _text(text), _size(1)
{}

GraphicString::GraphicString(std::string const& text, unsigned int size) : ComplexObject(), _text(text), _size(size)
{}

GraphicString::~GraphicString()
{}

GraphicString&			GraphicString::operator=(std::string const& modelString)
{
  _text = modelString;
  return *this;
}

GraphicString&			GraphicString::operator=(GraphicString const& model)
{
  _text = model.getText();
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
  gdl::Texture			*l = new gdl::Texture;
  GeometryFactory*		gf = new GeometryFactory();

  for (unsigned int i = 0; i < _text.size(); i++)
    {
      graphicChar = new Geometric(glm::vec3(_position.x + (static_cast<float>(i) * (_size * _scale.x)), _position.y, _position.z), _rotation, _scale);
      gdl::Geometry *x = new gdl::Geometry();

      *x = gf->getGeometry(GeometryFactory::FRONT_PLANE);
      x->pushVertex(glm::vec3( 0.5f, -0.5f, -0.5f));   	x->pushUv(glm::vec2(1.0f, 0.0f));
      x->pushVertex(glm::vec3( 0.5f, -0.5f,  0.5f));   	x->pushUv(glm::vec2(0.0f, 0.0f));
      x->pushVertex(glm::vec3(-0.5f, -0.5f,  0.5f));   	x->pushUv(glm::vec2(0.0f, 1.0f));
      x->pushVertex(glm::vec3(-0.5f, -0.5f, -0.5f));   	x->pushUv(glm::vec2(1.0f, 1.0f));
      x->pushVertex(glm::vec3( 0.5f,  0.5f,  0.5f));   	x->pushUv(glm::vec2(0.0f, 1.0f));
      x->pushVertex(glm::vec3( 0.5f,  0.5f, -0.5f));   	x->pushUv(glm::vec2(1.0f, 1.0f));
      x->pushVertex(glm::vec3(-0.5f,  0.5f, -0.5f));   	x->pushUv(glm::vec2(1.0f, 0.0f));
      x->pushVertex(glm::vec3(-0.5f,  0.5f,  0.5f));   	x->pushUv(glm::vec2(0.0f, 0.0f));
      x->pushVertex(glm::vec3(-0.5f, -0.5f,  0.5f));   	x->pushUv(glm::vec2(0.0f, 0.0f));
      x->pushVertex(glm::vec3(-0.5f,  0.5f,  0.5f));   	x->pushUv(glm::vec2(0.0f, 1.0f));
      x->pushVertex(glm::vec3(-0.5f,  0.5f, -0.5f));   	x->pushUv(glm::vec2(1.0f, 1.0f));
      x->pushVertex(glm::vec3(-0.5f, -0.5f, -0.5f));   	x->pushUv(glm::vec2(1.0f, 0.0f));
      x->pushVertex(glm::vec3( 0.5f, -0.5f, -0.5f));   	x->pushUv(glm::vec2(0.0f, 0.0f));
      x->pushVertex(glm::vec3( 0.5f,  0.5f, -0.5f));   	x->pushUv(glm::vec2(0.0f, 1.0f));
      x->pushVertex(glm::vec3( 0.5f,  0.5f,  0.5f));   	x->pushUv(glm::vec2(1.0f, 1.0f));
      x->pushVertex(glm::vec3( 0.5f, -0.5f,  0.5f));   	x->pushUv(glm::vec2(1.0f, 0.0f));
      x->pushVertex(glm::vec3( 0.5f, -0.5f,  0.5f));    	x->pushUv(glm::vec2(0.0f, 0.0f));
      x->pushVertex(glm::vec3( 0.5f,  0.5f,  0.5f));    	x->pushUv(glm::vec2(0.0f, 1.0f));
      x->pushVertex(glm::vec3(-0.5f,  0.5f,  0.5f));    	x->pushUv(glm::vec2(1.0f, 1.0f));
      x->pushVertex(glm::vec3(-0.5f, -0.5f,  0.5f));    	x->pushUv(glm::vec2(1.0f, 0.0f));
      x->pushVertex(glm::vec3( 0.5f, -0.5f, -0.5f));   	x->pushUv(glm::vec2(1.0f, 0.0f));
      x->pushVertex(glm::vec3( 0.5f,  0.5f, -0.5f));   	x->pushUv(glm::vec2(1.0f, 1.0f));
      x->pushVertex(glm::vec3(-0.5f,  0.5f, -0.5f));   	x->pushUv(glm::vec2(0.0f, 1.0f));
      x->pushVertex(glm::vec3(-0.5f, -0.5f, -0.5f));   	x->pushUv(glm::vec2(0.0f, 0.0f));

      x->build();
      graphicChar->setGeometry(*x);
      std::cout << "./assets/fonts/" << _text[i] << ".tga" << std::endl;
      //      std::cout << std::boolalpha << l->load("assets/fonts/" + _text.substr(i, i + 1) + ".tga") << std::endl;
      l->load(CRATE1);
      graphicChar->setTexture(*l);
      _spareParts.push_back(graphicChar);
    }
  return true;
}
