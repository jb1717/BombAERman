//
// GeometryFactory.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Tue May 26 09:17:03 2015 Jamais
// Last update Tue Jun  9 02:34:50 2015 Jamais
//

#include		"GeometryFactory.hh"

GeometryFactory*	GeometryFactory::instanciate()
{
  static GeometryFactory*	geometryCreator = new GeometryFactory;

  return geometryCreator;
}

GeometryFactory::GeometryFactory()
{
  _figures[DOWN_PLANE] = createDownPlane();
  _figures[UP_PLANE] = createUpPlane();
  _figures[LEFT_PLANE] = createLeftPlane();
  _figures[RIGHT_PLANE] = createRightPlane();
  _figures[FRONT_PLANE] = createFrontPlane();
  _figures[BACK_PLANE] = createBackPlane();
  _figures[PLANE] = createPlane();
  _figures[VERTICAL_PLANE] = createVerticalPlane();
  _figures[HORIZONTAL_PLANE] = createHorizontalPlane();
  _figures[DISC] = createDisc();
  _figures[CUBE] = createCube();
  _figures[CYLINDER] = createCylinder();
}

GeometryFactory::~GeometryFactory()
{
  std::map<eGeometry, gdl::Geometry *>::iterator	i;

  for(i = _figures.begin(); i != _figures.end(); i++)
    {
      _figures.erase(i);
    }
}

gdl::Geometry*		GeometryFactory::createDownPlane() const
{
  gdl::Geometry		*plane = new gdl::Geometry;

  plane->pushVertex(glm::vec3( 0.5f, -0.5f, -0.5f));	plane->pushUv(glm::vec2(1.0f, 0.0f));
  plane->pushVertex(glm::vec3( 0.5f, -0.5f,  0.5f));	plane->pushUv(glm::vec2(0.0f, 0.0f));
  plane->pushVertex(glm::vec3(-0.5f, -0.5f,  0.5f));	plane->pushUv(glm::vec2(0.0f, 1.0f));
  plane->pushVertex(glm::vec3(-0.5f, -0.5f, -0.5f));	plane->pushUv(glm::vec2(1.0f, 1.0f));
  plane->build();

  return plane;
}

gdl::Geometry*		GeometryFactory::createUpPlane() const
{
  gdl::Geometry		*plane = new gdl::Geometry;

  plane->pushVertex(glm::vec3( 0.5f,  0.5f,  0.5f));	plane->pushUv(glm::vec2(0.0f, 1.0f));
  plane->pushVertex(glm::vec3( 0.5f,  0.5f, -0.5f));	plane->pushUv(glm::vec2(1.0f, 1.0f));
  plane->pushVertex(glm::vec3(-0.5f,  0.5f, -0.5f));	plane->pushUv(glm::vec2(1.0f, 0.0f));
  plane->pushVertex(glm::vec3(-0.5f,  0.5f,  0.5f));	plane->pushUv(glm::vec2(0.0f, 0.0f));
  plane->build();

  return plane;
}

gdl::Geometry*		GeometryFactory::createRightPlane() const
{
  gdl::Geometry		*plane = new gdl::Geometry;

  plane->pushVertex(glm::vec3(-0.5f, -0.5f,  0.5f));   	plane->pushUv(glm::vec2(0.0f, 0.0f));
  plane->pushVertex(glm::vec3(-0.5f,  0.5f,  0.5f));   	plane->pushUv(glm::vec2(0.0f, 1.0f));
  plane->pushVertex(glm::vec3(-0.5f,  0.5f, -0.5f));   	plane->pushUv(glm::vec2(1.0f, 1.0f));
  plane->pushVertex(glm::vec3(-0.5f, -0.5f, -0.5f));   	plane->pushUv(glm::vec2(1.0f, 0.0f));
  plane->build();

  return plane;
}

gdl::Geometry*		GeometryFactory::createLeftPlane() const
{
  gdl::Geometry		*plane = new gdl::Geometry;

  plane->pushVertex(glm::vec3(0.5f, -0.5f,  -0.5f));   	plane->pushUv(glm::vec2(0.0f, 0.0f));
  plane->pushVertex(glm::vec3(0.5f,  0.5f,  -0.5f));   	plane->pushUv(glm::vec2(0.0f, 1.0f));
  plane->pushVertex(glm::vec3(0.5f,  0.5f,   0.5f));   	plane->pushUv(glm::vec2(1.0f, 1.0f));
  plane->pushVertex(glm::vec3(0.5f, -0.5f,   0.5f));   	plane->pushUv(glm::vec2(1.0f, 0.0f));
  plane->build();

  return plane;
}

gdl::Geometry*		GeometryFactory::createBackPlane() const
{
  gdl::Geometry		*plane = new gdl::Geometry;

  plane->pushVertex(glm::vec3( 0.5f, -0.5f, 0.5f));    	plane->pushUv(glm::vec2(0.0f, 0.0f));
  plane->pushVertex(glm::vec3( 0.5f,  0.5f, 0.5f));    	plane->pushUv(glm::vec2(0.0f, 1.0f));
  plane->pushVertex(glm::vec3(-0.5f,  0.5f, 0.5f));    	plane->pushUv(glm::vec2(1.0f, 1.0f));
  plane->pushVertex(glm::vec3(-0.5f, -0.5f, 0.5f));    	plane->pushUv(glm::vec2(1.0f, 0.0f));
  plane->build();

  return plane;
}

gdl::Geometry*		GeometryFactory::createFrontPlane() const
{
  gdl::Geometry		*plane = new gdl::Geometry;

  plane->pushVertex(glm::vec3( 0.5f, -0.5f, -0.5f));   	plane->pushUv(glm::vec2(1.0f, 0.0f));
  plane->pushVertex(glm::vec3( 0.5f,  0.5f, -0.5f));   	plane->pushUv(glm::vec2(1.0f, 1.0f));
  plane->pushVertex(glm::vec3(-0.5f,  0.5f, -0.5f));   	plane->pushUv(glm::vec2(0.0f, 1.0f));
  plane->pushVertex(glm::vec3(-0.5f, -0.5f, -0.5f));   	plane->pushUv(glm::vec2(0.0f, 0.0f));
  plane->build();

  return plane;
}

gdl::Geometry*		GeometryFactory::createPlane() const
{
  gdl::Geometry		*plane = new gdl::Geometry;

  plane->pushVertex(glm::vec3( 0.5f, -0.5f, 0.0f));   	plane->pushUv(glm::vec2(1.0f, 0.0f));
  plane->pushVertex(glm::vec3( 0.5f,  0.5f, 0.0f));   	plane->pushUv(glm::vec2(1.0f, 1.0f));
  plane->pushVertex(glm::vec3(-0.5f,  0.5f, 0.0f));   	plane->pushUv(glm::vec2(0.0f, 1.0f));
  plane->pushVertex(glm::vec3(-0.5f, -0.5f, 0.0f));   	plane->pushUv(glm::vec2(0.0f, 0.0f));
  plane->build();

  return plane;
}

gdl::Geometry*		GeometryFactory::createVerticalPlane() const
{
  gdl::Geometry		*plane = new gdl::Geometry;

  plane->pushVertex(glm::vec3( 0.5f, -0.5f, 0.0));   	plane->pushUv(glm::vec2(0.0f, 0.0f));
  plane->pushVertex(glm::vec3( 0.5f,  0.5f, 0.0f));   	plane->pushUv(glm::vec2(0.0f, 1.0f));
  plane->pushVertex(glm::vec3(-0.5f,  0.5f, 0.0f));   	plane->pushUv(glm::vec2(1.0f, 1.0f));
  plane->pushVertex(glm::vec3(-0.5f, -0.5f, 0.0f));   	plane->pushUv(glm::vec2(1.0f, 0.0f));
  plane->build();

  return plane;
}

gdl::Geometry*		GeometryFactory::createHorizontalPlane() const
{
  gdl::Geometry		*plane = new gdl::Geometry;

  plane->pushVertex(glm::vec3( 0.5f,  0.0f, -0.5f));   	plane->pushUv(glm::vec2(0.0f, 0.0f));
  plane->pushVertex(glm::vec3( 0.5f,  0.0f,  0.5f));   	plane->pushUv(glm::vec2(0.0f, 1.0f));
  plane->pushVertex(glm::vec3(-0.5f,  0.0f,  0.5f));   	plane->pushUv(glm::vec2(1.0f, 1.0f));
  plane->pushVertex(glm::vec3(-0.5f,  0.0f, -0.5f));   	plane->pushUv(glm::vec2(1.0f, 0.0f));
  plane->build();

  return plane;
}

gdl::Geometry*		GeometryFactory::createCylinder() const
{
  gdl::Geometry		*cylinder = new gdl::Geometry;
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
  return cylinder;
}

gdl::Geometry*		GeometryFactory::createDisc() const
{
  gdl::Geometry		*disc = new gdl::Geometry;
  int			slices = 360 * 10;
  float			in = 2 * M_PI / slices;
  float			theta = 0.0f;

  for (int i = 0; i < slices; i++)
    {
      disc->pushVertex(glm::vec3(0.0f, 0.0f, 0.0f));
      disc->pushUv(glm::vec2(0.5f, 0.5f));
      disc->pushVertex(glm::vec3(0.5 * cos(theta), 0.5 * sin(theta), 0.0f));
      disc->pushUv(glm::vec2(0.5f, 0.5f));
      //      disc->pushUv(glm::vec2(0.5 * cos(theta), 0.5 * sin(theta)));
      theta += in;
    }
  disc->build();
  return disc;
}

gdl::Geometry*		GeometryFactory::createCube() const
{
  gdl::Geometry		*cube = new gdl::Geometry;

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

  return cube;
}

gdl::Geometry&		GeometryFactory::getGeometry(eGeometry const& type)
{
  return *_figures[type];
}
