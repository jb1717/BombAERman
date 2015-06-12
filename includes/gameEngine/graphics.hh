//
// graphics.hh for CPP_BOMBERMAN in /home/paasch_j/cpp_bomberman
//
// Made by Johan Paasche
// Login   <paasch_j@epitech.net>
//
// Started on  Mon Apr 27 14:00:52 2015 Johan Paasche
// Last update Fri Jun 12 08:48:37 2015 Jamais
//

#ifndef		___GRAPHICS_HH___
# define	___GRAPHICS_HH___

# include	<iostream>
# include	<fstream>

# include	"OpenGL.hh"
# include	"glm/glm.hpp"
# include	"glm/gtc/matrix_transform.hpp"

# include	<Game.hh>
# include	<Clock.hh>
# include	<Input.hh>
# include	<SdlContext.hh>
# include	<Geometry.hh>
# include	<Texture.hh>
# include	<BasicShader.hh>
# include	<Model.hh>

# include	"FILES.hh"

# define	UNUSED		__attribute__((unused))

std::ostream&	operator<<(std::ostream& os, glm::vec3 const& v);

#endif		/* !___GRAPHICS_HH___ */
