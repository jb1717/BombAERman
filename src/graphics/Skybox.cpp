//
// Skybox.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sat May 23 01:13:10 2015 Jamais
// Last update Sun Jun  7 02:54:55 2015 Jamais
//

#include		"Skybox.hh"
# include		"GeometryFactory.hh"


Skybox::Skybox()
{
  Geometric	*f = new Geometric();
  //  gdl::Geometry	*g = new gdl::Geometry;
  gdl::Texture	*down = new gdl::Texture();
  gdl::Texture	*up = new gdl::Texture();
  gdl::Texture	*front = new gdl::Texture();
  gdl::Texture	*back = new gdl::Texture();
  gdl::Texture	*right = new gdl::Texture();
  gdl::Texture	*left = new gdl::Texture();

  //  std::string	skyboxName("hell");
  // std::string	skyboxName("StormySky");

  // std::string	filepath("./assets/Textures/SkyBoxTextures/" + skyboxName + "/" + skyboxName);
  std::string	filepath(STORMSKY);
  GeometryFactory* x = GeometryFactory::instanciate();


  //std::string	filepath(HELL);
  down->load(filepath + "_dn.tga", false);
  up->load(filepath +  "_up.tga", false);
  back->load(filepath + "_bk.tga", false);
  front->load(filepath + "_ft.tga", false);
  left->load(filepath + "_lf.tga", false);
  right->load(filepath + "_rt.tga", false);

  /**/
  // g->pushVertex(glm::vec3(0.5, -0.5, 0.5));	g->pushUv(glm::vec2(0.0f, 0.0f));
  // g->pushVertex(glm::vec3(0.5, 0.5, 0.5));	g->pushUv(glm::vec2(0.0f, 1.0f));
  // g->pushVertex(glm::vec3(-0.5, 0.5, 0.5));	g->pushUv(glm::vec2(1.0f, 1.0f));
  // g->pushVertex(glm::vec3(-0.5, -0.5, 0.5));	g->pushUv(glm::vec2(1.0f, 0.0f));
  f = new Geometric();
  f->setTexture(*back);
  f->initialize();
  f->setGeometry(x->getGeometry(GeometryFactory::BACK_PLANE));
  // f->setGeometry(*g);
  f->scale(glm::vec3(20000, 20000, 20000));
  _faces.push_back(f);

  // g = new gdl::Geometry;
  // g->pushVertex(glm::vec3(0.5, -0.5, -0.5));	g->pushUv(glm::vec2(1.0f, 0.0f));
  // g->pushVertex(glm::vec3(0.5, 0.5, -0.5));	g->pushUv(glm::vec2(1.0f, 1.0f));
  // g->pushVertex(glm::vec3(-0.5, 0.5, -0.5));	g->pushUv(glm::vec2(0.0f, 1.0f));
  // g->pushVertex(glm::vec3(-0.5, -0.5, -0.5));	g->pushUv(glm::vec2(0.0f, 0.0f));
  f = new Geometric();
  f->setTexture(*front);
  f->initialize();
  f->setGeometry(x->getGeometry(GeometryFactory::FRONT_PLANE));
  // f->setGeometry(*g);
  f->scale(glm::vec3(20000, 20000, 20000));
  _faces.push_back(f);

  // g = new gdl::Geometry;
  // g->pushVertex(glm::vec3(0.5, -0.5, -0.5));	g->pushUv(glm::vec2(0.0f, 0.0f));
  // g->pushVertex(glm::vec3(0.5, 0.5, -0.5));	g->pushUv(glm::vec2(0.0f, 1.0f));
  // g->pushVertex(glm::vec3(0.5, 0.5, 0.5));	g->pushUv(glm::vec2(1.0f, 1.0f));
  // g->pushVertex(glm::vec3(0.5, -0.5, 0.5));	g->pushUv(glm::vec2(1.0f, 0.0f));
  f = new Geometric();
  f->setTexture(*left);
  f->initialize();
  f->setGeometry(x->getGeometry(GeometryFactory::LEFT_PLANE));
  // f->setGeometry(*g);
  f->scale(glm::vec3(20000, 20000, 20000));
  _faces.push_back(f);

  // g = new gdl::Geometry;
  // // g->setColor(glm::vec4(0, 0, 1, 1));
  // g->pushVertex(glm::vec3(-0.5, -0.5, 0.5));	g->pushUv(glm::vec2(0.0f, 0.0f));
  // g->pushVertex(glm::vec3(-0.5, 0.5, 0.5));	g->pushUv(glm::vec2(0.0f, 1.0f));
  // g->pushVertex(glm::vec3(-0.5, 0.5, -0.5));	g->pushUv(glm::vec2(1.0f, 1.0f));
  // g->pushVertex(glm::vec3(-0.5, -0.5, -0.5));	g->pushUv(glm::vec2(1.0f, 0.0f));
  f = new Geometric();
  f->setTexture(*right);
  f->initialize();
  // f->setGeometry(*g);
  f->setGeometry(x->getGeometry(GeometryFactory::RIGHT_PLANE));
  f->scale(glm::vec3(20000, 20000, 20000));
  _faces.push_back(f);

  // upper face
  // g = new gdl::Geometry;
  // // g->setColor(glm::vec4(1, 0, 1, 1));
  // g->pushVertex(glm::vec3(0.5, 0.5, 0.5));	g->pushUv(glm::vec2(0.0f, 1.0f));
  // g->pushVertex(glm::vec3(0.5, 0.5, -0.5));	g->pushUv(glm::vec2(1.0f, 1.0f));
  // g->pushVertex(glm::vec3(-0.5, 0.5, -0.5));	g->pushUv(glm::vec2(1.0f, 0.0f));
  // g->pushVertex(glm::vec3(-0.5, 0.5, 0.5));	g->pushUv(glm::vec2(0.0f, 0.0f));
  f = new Geometric();
  f->setTexture(*up);
  f->initialize();
  f->translate(glm::vec3(0, -100, 0));
  f->setGeometry(x->getGeometry(GeometryFactory::UP_PLANE));
  // f->setGeometry(*g);
  f->scale(glm::vec3(20020, 20000, 20020));
  _faces.push_back(f);

  // g = new gdl::Geometry;
  // // g->setColor(glm::vec4(0, 0, 0, 1));
  // g->pushVertex(glm::vec3(0.5, -0.5, -0.5));	g->pushUv(glm::vec2(1.0f, 0.0f));
  // g->pushVertex(glm::vec3(0.5, -0.5, 0.5));	g->pushUv(glm::vec2(0.0f, 0.0f));
  // g->pushVertex(glm::vec3(-0.5, -0.5, 0.5));	g->pushUv(glm::vec2(0.0f, 1.0f));
  // g->pushVertex(glm::vec3(-0.5, -0.5, -0.5));	g->pushUv(glm::vec2(1.0f, 1.0f));
  f = new Geometric();

  f->setTexture(*down);
  f->initialize();
  f->translate(glm::vec3(0, 100, 0));
  f->setGeometry(x->getGeometry(GeometryFactory::DOWN_PLANE));
  //  f->setGeometry(*g);
  f->scale(glm::vec3(20000 - 10, 20000, 20000 - 10));
  _faces.push_back(f);
}

void		Skybox::draw(gdl::AShader& shader, gdl::Clock const& clock)
{

  // glDisable(GL_DEPTH_TEST);
  // glDepthMask(GL_FALSE);
  std::vector<Geometric *>::iterator	i;
  for (i = _faces.begin(); i != _faces.end(); i++)
    (*i)->draw(shader, clock);
   glDepthMask(GL_TRUE);
  glEnable(GL_DEPTH_TEST);
}

Skybox::~Skybox()
{

}
