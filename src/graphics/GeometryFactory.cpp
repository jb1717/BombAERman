//
// GeometryFactory.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Tue May 26 09:17:03 2015 Jamais
// Last update Wed Jun 10 00:54:06 2015 Jamais
//

#include		"GeometryFactory.hh"

GeometryFactory*	GeometryFactory::instanciate()
{
  static GeometryFactory*	geometryCreator = new GeometryFactory;

  return geometryCreator;
}

GeometryFactory::GeometryFactory()
{
  _figures[DOWN_PLANE] = createDownPlane(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), true);
  _figures[UP_PLANE] = createUpPlane(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), true);
  _figures[LEFT_PLANE] = createLeftPlane(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), true);
  _figures[RIGHT_PLANE] = createRightPlane(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), true);
  _figures[FRONT_PLANE] = createFrontPlane(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), true);
  _figures[BACK_PLANE] = createBackPlane(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), true);
  _figures[PLANE] = createPlane(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), true);
  _figures[VERTICAL_PLANE] = createVerticalPlane(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), true);
  _figures[HORIZONTAL_PLANE] = createHorizontalPlane(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), true);
  _figures[DISC] = createDisc(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), true);
  _figures[CUBE] = createCube(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), true);
  _figures[CYLINDER] = createCylinder(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), true);
  _generator[DOWN_PLANE] = &GeometryFactory::createDownPlane;
  _generator[UP_PLANE] = &GeometryFactory::createUpPlane;
  _generator[LEFT_PLANE] = &GeometryFactory::createLeftPlane;
  _generator[RIGHT_PLANE] = &GeometryFactory::createRightPlane;
  _generator[FRONT_PLANE] = &GeometryFactory::createFrontPlane;
  _generator[BACK_PLANE] = &GeometryFactory::createBackPlane;
  _generator[PLANE] = &GeometryFactory::createPlane;
  _generator[VERTICAL_PLANE] = &GeometryFactory::createVerticalPlane;
  _generator[HORIZONTAL_PLANE] = &GeometryFactory::createHorizontalPlane;
  _generator[DISC] = &GeometryFactory::createDisc;
  _generator[CUBE] = &GeometryFactory::createCube;
  _generator[CYLINDER] = &GeometryFactory::createCylinder;

}

GeometryFactory::~GeometryFactory()
{
  std::map<eGeometry, gdl::Geometry *>::iterator	i;

  for(i = _figures.begin(); i != _figures.end(); i++)
    {
      _figures.erase(i);
    }
}

gdl::Geometry*		GeometryFactory::createDownPlane(glm::vec4 const& color, bool generate) const
{
  static bool		planeInstance = false;
  gdl::Geometry		*plane = new gdl::Geometry;

  if (generate)
    {
      if (planeInstance)
	{
	  delete plane;
	  plane = new gdl::Geometry;
	}
      plane->setColor(color);
      plane->pushVertex(glm::vec3( 0.5f, -0.5f, -0.5f));	plane->pushUv(glm::vec2(1.0f, 0.0f));
      plane->pushVertex(glm::vec3( 0.5f, -0.5f,  0.5f));	plane->pushUv(glm::vec2(0.0f, 0.0f));
      plane->pushVertex(glm::vec3(-0.5f, -0.5f,  0.5f));	plane->pushUv(glm::vec2(0.0f, 1.0f));
      plane->pushVertex(glm::vec3(-0.5f, -0.5f, -0.5f));	plane->pushUv(glm::vec2(1.0f, 1.0f));
      plane->build();
    }
  return plane;
}

gdl::Geometry*		GeometryFactory::createUpPlane(glm::vec4 const& color, bool generate) const
{
  static bool		planeInstance = false;
  gdl::Geometry		*plane = new gdl::Geometry;

  if (generate)
    {
      if (planeInstance)
	{
	  delete plane;
	  plane = new gdl::Geometry;
	}
      plane->setColor(color);
      plane->pushVertex(glm::vec3( 0.5f,  0.5f,  0.5f));	plane->pushUv(glm::vec2(0.0f, 1.0f));
      plane->pushVertex(glm::vec3( 0.5f,  0.5f, -0.5f));	plane->pushUv(glm::vec2(1.0f, 1.0f));
      plane->pushVertex(glm::vec3(-0.5f,  0.5f, -0.5f));	plane->pushUv(glm::vec2(1.0f, 0.0f));
      plane->pushVertex(glm::vec3(-0.5f,  0.5f,  0.5f));	plane->pushUv(glm::vec2(0.0f, 0.0f));
      plane->build();
    }
  return plane;
}

gdl::Geometry*		GeometryFactory::createRightPlane(glm::vec4 const& color, bool generate) const
{
  static bool		planeInstance = false;
  gdl::Geometry		*plane = new gdl::Geometry;

  if (generate)
    {
      if (planeInstance)
	{
	  delete plane;
	  plane = new gdl::Geometry;
	}
      plane->setColor(color);
      plane->pushVertex(glm::vec3(-0.5f, -0.5f,  0.5f));   	plane->pushUv(glm::vec2(0.0f, 0.0f));
      plane->pushVertex(glm::vec3(-0.5f,  0.5f,  0.5f));   	plane->pushUv(glm::vec2(0.0f, 1.0f));
      plane->pushVertex(glm::vec3(-0.5f,  0.5f, -0.5f));   	plane->pushUv(glm::vec2(1.0f, 1.0f));
      plane->pushVertex(glm::vec3(-0.5f, -0.5f, -0.5f));   	plane->pushUv(glm::vec2(1.0f, 0.0f));
      plane->build();
    }
  return plane;
}

gdl::Geometry*		GeometryFactory::createLeftPlane(glm::vec4 const& color, bool generate) const
{
  static bool		planeInstance = false;
  gdl::Geometry		*plane = new gdl::Geometry;

  if (generate)
    {
      if (planeInstance)
	{
	  delete plane;
	  plane = new gdl::Geometry;
	}
      plane->setColor(color);
      plane->pushVertex(glm::vec3(0.5f, -0.5f,  -0.5f));   	plane->pushUv(glm::vec2(0.0f, 0.0f));
      plane->pushVertex(glm::vec3(0.5f,  0.5f,  -0.5f));   	plane->pushUv(glm::vec2(0.0f, 1.0f));
      plane->pushVertex(glm::vec3(0.5f,  0.5f,   0.5f));   	plane->pushUv(glm::vec2(1.0f, 1.0f));
      plane->pushVertex(glm::vec3(0.5f, -0.5f,   0.5f));   	plane->pushUv(glm::vec2(1.0f, 0.0f));
      plane->build();
    }
  return plane;
}

gdl::Geometry*		GeometryFactory::createBackPlane(glm::vec4 const& color, bool generate) const
{
  static bool		planeInstance = false;
  gdl::Geometry		*plane = new gdl::Geometry;

  if (generate)
    {
      if (planeInstance)
	{
	  delete plane;
	  plane = new gdl::Geometry;
	}
      plane->setColor(color);
      plane->pushVertex(glm::vec3( 0.5f, -0.5f, 0.5f));    	plane->pushUv(glm::vec2(0.0f, 0.0f));
      plane->pushVertex(glm::vec3( 0.5f,  0.5f, 0.5f));    	plane->pushUv(glm::vec2(0.0f, 1.0f));
      plane->pushVertex(glm::vec3(-0.5f,  0.5f, 0.5f));    	plane->pushUv(glm::vec2(1.0f, 1.0f));
      plane->pushVertex(glm::vec3(-0.5f, -0.5f, 0.5f));    	plane->pushUv(glm::vec2(1.0f, 0.0f));
      plane->build();
    }
  return plane;
}

gdl::Geometry*		GeometryFactory::createFrontPlane(glm::vec4 const& color, bool generate) const
{
  static bool		planeInstance = false;
  gdl::Geometry		*plane = new gdl::Geometry;

  if (generate)
    {
      if (planeInstance)
	{
	  delete plane;
	  plane = new gdl::Geometry;
	}
      plane->setColor(color);
      plane->pushVertex(glm::vec3( 0.5f, -0.5f, -0.5f));   	plane->pushUv(glm::vec2(1.0f, 0.0f));
      plane->pushVertex(glm::vec3( 0.5f,  0.5f, -0.5f));   	plane->pushUv(glm::vec2(1.0f, 1.0f));
      plane->pushVertex(glm::vec3(-0.5f,  0.5f, -0.5f));   	plane->pushUv(glm::vec2(0.0f, 1.0f));
      plane->pushVertex(glm::vec3(-0.5f, -0.5f, -0.5f));   	plane->pushUv(glm::vec2(0.0f, 0.0f));
      plane->build();
    }
  return plane;
}

gdl::Geometry*		GeometryFactory::createPlane(glm::vec4 const& color, bool generate) const
{
  static bool		planeInstance = false;
  gdl::Geometry		*plane = new gdl::Geometry;

  if (generate)
    {
      if (planeInstance)
	{
	  delete plane;
	  plane = new gdl::Geometry;
	}
      plane->setColor(color);
      plane->pushVertex(glm::vec3( 0.5f, -0.5f, 0.0f));   	plane->pushUv(glm::vec2(1.0f, 0.0f));
      plane->pushVertex(glm::vec3( 0.5f,  0.5f, 0.0f));   	plane->pushUv(glm::vec2(1.0f, 1.0f));
      plane->pushVertex(glm::vec3(-0.5f,  0.5f, 0.0f));   	plane->pushUv(glm::vec2(0.0f, 1.0f));
      plane->pushVertex(glm::vec3(-0.5f, -0.5f, 0.0f));   	plane->pushUv(glm::vec2(0.0f, 0.0f));
      plane->build();
    }
  return plane;
}

gdl::Geometry*		GeometryFactory::createVerticalPlane(glm::vec4 const& color, bool generate) const
{
  static bool		planeInstance = false;
  static gdl::Geometry 	*plane = new gdl::Geometry;

  if (generate)
    {
      if (planeInstance)
	{
	  delete plane;
	  plane = new gdl::Geometry;
	}
      plane->setColor(color);
      plane->pushVertex(glm::vec3( 0.5f, -0.5f, 0.0));   	plane->pushUv(glm::vec2(0.0f, 0.0f));
      plane->pushVertex(glm::vec3( 0.5f,  0.5f, 0.0f));   	plane->pushUv(glm::vec2(0.0f, 1.0f));
      plane->pushVertex(glm::vec3(-0.5f,  0.5f, 0.0f));   	plane->pushUv(glm::vec2(1.0f, 1.0f));
      plane->pushVertex(glm::vec3(-0.5f, -0.5f, 0.0f));   	plane->pushUv(glm::vec2(1.0f, 0.0f));
      plane->build();
      planeInstance = true;
    }
  return plane;
}

gdl::Geometry*		GeometryFactory::createHorizontalPlane(glm::vec4 const& color, bool generate) const
{
  static bool		planeInstance = false;
  static gdl::Geometry 	*plane = new gdl::Geometry;

  if (generate)
    {
      if (planeInstance)
	{
	  delete plane;
	  plane = new gdl::Geometry;
	}
      plane->setColor(color);
      plane->pushVertex(glm::vec3( 0.5f,  0.0f, -0.5f));   	plane->pushUv(glm::vec2(0.0f, 0.0f));
      plane->pushVertex(glm::vec3( 0.5f,  0.0f,  0.5f));   	plane->pushUv(glm::vec2(0.0f, 1.0f));
      plane->pushVertex(glm::vec3(-0.5f,  0.0f,  0.5f));   	plane->pushUv(glm::vec2(1.0f, 1.0f));
      plane->pushVertex(glm::vec3(-0.5f,  0.0f, -0.5f));   	plane->pushUv(glm::vec2(1.0f, 0.0f));
      plane->build();
      planeInstance = true;
    }
  return plane;
}

gdl::Geometry*		GeometryFactory::createCylinder(glm::vec4 const& color, bool generate) const
{
  static bool		cylinderInstance = false;
  static gdl::Geometry 	*cylinder = new gdl::Geometry;

  if (generate)
    {
      if (cylinderInstance)
	{
	  delete cylinder;
	  cylinder = new gdl::Geometry;
	}
      cylinder->setColor(color);
      int	slices = 1440;
      auto inc = 2 * M_PI / slices;
      float	theta, theta2;

      for (int i = 0; i < slices; i++)
	{
	  theta2 = theta + inc;
	  // cylinder->pushVertex(glm::vec3(0.0f, 0.5f, 0.0f));
	  // cylinder->pushUv(glm::vec2(0.5f, 0.5f));
	  cylinder->pushVertex(glm::vec3(0.25 * cos(theta), 0.5f, 0.25 * sin(theta)));
	  cylinder->pushVertex(glm::vec3(0.25 * cos(theta2), 0.5f, 0.25 * sin(theta2)));
	  cylinder->pushVertex(glm::vec3(0.25 * cos(theta), -0.5f, 0.25 * sin(theta)));
	  cylinder->pushVertex(glm::vec3(0.25 * cos(theta2), -0.5f, 0.25 * sin(theta2)));
	  cylinder->pushUv(glm::vec2(theta, 1.0f));
	  cylinder->pushUv(glm::vec2(theta2, 1.0f));
	  cylinder->pushUv(glm::vec2(theta, 0.0f));
	  cylinder->pushUv(glm::vec2(theta2, 0.0f));
	  theta = theta2;
	}
      cylinder->build();
    }
  return cylinder;
}

gdl::Geometry*		GeometryFactory::createDisc(glm::vec4 const& color, bool generate) const
{
  static bool		discInstance = false;
  static gdl::Geometry	*disc = new gdl::Geometry;

  if (generate)
    {
      if (discInstance)
	{
	  delete disc;
	  disc = new gdl::Geometry;
	}
      disc->setColor(color);
      int			slices = 360 * 10;
      float			in = 2 * M_PI / slices;
      float			theta = 0.0f;

      for (int i = 0; i < slices; i++)
	{
	  disc->pushVertex(glm::vec3(0.0f, 0.0f, 0.0f));
	  disc->pushUv(glm::vec2(0.5f, 0.5f));
	  disc->pushVertex(glm::vec3(0.5 * cos(theta), 0.5 * sin(theta), 0.0f));
	  disc->pushUv(glm::vec2(0.5f, 0.5f));
	  theta += in;
	}
      disc->build();
      discInstance = true;
    }
  return disc;
}

gdl::Geometry*		GeometryFactory::createCube(glm::vec4 const& color, bool generate) const
{
  static bool		cubeInstance = false;
  static gdl::Geometry 	*cube = new gdl::Geometry;

  if (generate)
    {
      if (cubeInstance)
	{
	  delete cube;
	  cube = new gdl::Geometry;
	}
      cube->setColor(color);
      cube->pushVertex(glm::vec3( 0.5f, -0.5f, -0.5f));   	cube->pushUv(glm::vec2(1.0f, 0.0f));
      cube->pushVertex(glm::vec3( 0.5f, -0.5f,  0.5f));   	cube->pushUv(glm::vec2(0.0f, 0.0f));
      cube->pushVertex(glm::vec3(-0.5f, -0.5f,  0.5f));   	cube->pushUv(glm::vec2(0.0f, 1.0f));
      cube->pushVertex(glm::vec3(-0.5f, -0.5f, -0.5f));   	cube->pushUv(glm::vec2(1.0f, 1.0f));
      cube->pushVertex(glm::vec3( 0.5f,  0.5f,  0.5f));   	cube->pushUv(glm::vec2(0.0f, 1.0f));
      cube->pushVertex(glm::vec3( 0.5f,  0.5f, -0.5f));   	cube->pushUv(glm::vec2(1.0f, 1.0f));
      cube->pushVertex(glm::vec3(-0.5f,  0.5f, -0.5f));   	cube->pushUv(glm::vec2(1.0f, 0.0f));
      cube->pushVertex(glm::vec3(-0.5f,  0.5f,  0.5f));   	cube->pushUv(glm::vec2(0.0f, 0.0f));
      cube->pushVertex(glm::vec3(-0.5f, -0.5f,  0.5f));   	cube->pushUv(glm::vec2(0.0f, 0.0f));
      cube->pushVertex(glm::vec3(-0.5f,  0.5f,  0.5f));   	cube->pushUv(glm::vec2(0.0f, 1.0f));
      cube->pushVertex(glm::vec3(-0.5f,  0.5f, -0.5f));   	cube->pushUv(glm::vec2(1.0f, 1.0f));
      cube->pushVertex(glm::vec3(-0.5f, -0.5f, -0.5f));   	cube->pushUv(glm::vec2(1.0f, 0.0f));
      cube->pushVertex(glm::vec3( 0.5f, -0.5f, -0.5f));   	cube->pushUv(glm::vec2(0.0f, 0.0f));
      cube->pushVertex(glm::vec3( 0.5f,  0.5f, -0.5f));   	cube->pushUv(glm::vec2(0.0f, 1.0f));
      cube->pushVertex(glm::vec3( 0.5f,  0.5f,  0.5f));   	cube->pushUv(glm::vec2(1.0f, 1.0f));
      cube->pushVertex(glm::vec3( 0.5f, -0.5f,  0.5f));   	cube->pushUv(glm::vec2(1.0f, 0.0f));
      cube->pushVertex(glm::vec3( 0.5f, -0.5f,  0.5f));    	cube->pushUv(glm::vec2(0.0f, 0.0f));
      cube->pushVertex(glm::vec3( 0.5f,  0.5f,  0.5f));    	cube->pushUv(glm::vec2(0.0f, 1.0f));
      cube->pushVertex(glm::vec3(-0.5f,  0.5f,  0.5f));    	cube->pushUv(glm::vec2(1.0f, 1.0f));
      cube->pushVertex(glm::vec3(-0.5f, -0.5f,  0.5f));    	cube->pushUv(glm::vec2(1.0f, 0.0f));
      cube->pushVertex(glm::vec3( 0.5f, -0.5f, -0.5f));   	cube->pushUv(glm::vec2(1.0f, 0.0f));
      cube->pushVertex(glm::vec3( 0.5f,  0.5f, -0.5f));   	cube->pushUv(glm::vec2(1.0f, 1.0f));
      cube->pushVertex(glm::vec3(-0.5f,  0.5f, -0.5f));   	cube->pushUv(glm::vec2(0.0f, 1.0f));
      cube->pushVertex(glm::vec3(-0.5f, -0.5f, -0.5f));   	cube->pushUv(glm::vec2(0.0f, 0.0f));
      cube->build();
      cubeInstance = true;
    }
  return cube;
}

gdl::Geometry&		GeometryFactory::getGeometry(eGeometry const& type, glm::vec4 const& color, bool generate)
{
  gdl::Geometry*	result;

  if (generate)
      result = (this->*_generator[type])(color, generate);
  else
    result = _figures[type];
  //  return generate ? *((this->*_generator[type])(color, generate)) : *_figures[type];
  return generate ? (*(this->*_generator[type])(color, generate)) : *_figures[type];
  return *result;
}
