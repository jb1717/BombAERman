//
// GeometryFactory.hh for CPP_COMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sun May 24 05:21:40 2015 Jamais
// Last update Tue Jun  9 12:11:19 2015 Jamais
//

#ifndef				___GEOMETRY_FACTORY_HH___
# define			___GEOMETRY_FACTORY_HH___

# include			"graphics.hh"
# include			"Geometric.hh"

class				GeometryFactory
{
public:
  enum	eGeometry
    {
      RIGHT_PLANE = 0,
      LEFT_PLANE,
      UP_PLANE,
      DOWN_PLANE,
      FRONT_PLANE,
      BACK_PLANE,
      PLANE,
      VERTICAL_PLANE,
      HORIZONTAL_PLANE,
      DISC,
      CUBE,
      CYLINDER
    };


private:
  std::map<eGeometry, gdl::Geometry* >	_figures;
  std::map<eGeometry, gdl::Geometry* (GeometryFactory::*)(glm::vec4 const& color, bool generate) const >	_generator;

private:
  gdl::Geometry*		createDownPlane(glm::vec4 const& color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), bool generate = false) const;
  gdl::Geometry*		createUpPlane(glm::vec4 const& color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), bool generate = false) const;
  gdl::Geometry*		createRightPlane(glm::vec4 const& color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), bool generate = false) const;
  gdl::Geometry*		createLeftPlane(glm::vec4 const& color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), bool generate = false) const;
  gdl::Geometry*		createFrontPlane(glm::vec4 const& color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), bool generate = false) const;
  gdl::Geometry*		createBackPlane(glm::vec4 const& color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), bool generate = false) const;
  gdl::Geometry*		createPlane(glm::vec4 const& color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), bool generate = false) const;
  gdl::Geometry*		createVerticalPlane(glm::vec4 const& color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), bool generate = false) const;
  gdl::Geometry*		createHorizontalPlane(glm::vec4 const& color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), bool generate = false) const;
  gdl::Geometry*		createDisc(glm::vec4 const& color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), bool generate = false) const;
  gdl::Geometry*		createCube(glm::vec4 const& color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), bool generate = false) const;
  gdl::Geometry*		createCylinder(glm::vec4 const& color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), bool generate = false) const;

private:
  GeometryFactory();

public:
  static GeometryFactory*
  instanciate();

public:
  ~GeometryFactory();

public:
  gdl::Geometry&		getGeometry(eGeometry const& type, glm::vec4 const& color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), bool generate = false);

};

#endif				/* !___GEOMETRY_FACTORY_HH___ */
