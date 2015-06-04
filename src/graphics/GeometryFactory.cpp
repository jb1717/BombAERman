//
// GeometryFactory.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Tue May 26 09:17:03 2015 Jamais
// Last update Thu Jun  4 01:17:37 2015 Jamais
//

#include		"GeometryFactory.hh"

GeometryFactory::GeometryFactory()
{
  _figures[DOWN_PLANE] = createDownPlane();
  _figures[UP_PLANE] = createUpPlane();
  _figures[LEFT_PLANE] = createLeftPlane();
  _figures[RIGHT_PLANE] = createRightPlane();
  _figures[FRONT_PLANE] = createFrontPlane();
  _figures[BACK_PLANE] = createBackPlane();
  _figures[CUBE] = createCube();
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
