//
// Texture.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 24 02:39:04 2015 Jamais
// Last update Sun May 24 02:41:59 2015 Jamais
//

#include	"Texture.hh"

Texture::Texture() : gdl::Texture()
{}

Texture::~Texture() {}

void		Texture::setTexParameter(GLenum target, GLenum pname, T* params)
{
  bind();
  glTexParamaterif(target, pname, params);
}
