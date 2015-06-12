//
// Skybox.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sat May 23 01:13:10 2015 Jamais
// Last update Fri Jun 12 03:23:17 2015 Jamais
//

#include		"Skybox.hh"
#include		"GeometryFactory.hh"
#include		"AssetManager.hh"

Skybox::Skybox()
{
}

void		Skybox::generate(std::string const& themeName)
{
  auto				asset = AssetManager::instance();
  auto				factory = GeometryFactory::instanciate();
  Geometric*		face;
  std::stringstream	sstrm;

  for (int i = 0; i < 6; i++)
    {
      sstrm.str("");
      face = new Geometric();
      face->setGeometry(factory->getGeometry(static_cast<GeometryFactory::eGeometry>(i)));
      sstrm << SKYBOX_TEXTURE_BASE_NAME << i;
      try { face->setTexture(*(*THEME((*THEME_HANDLER(asset["themes"]))[themeName]))[sstrm.str()]);}
      catch (std::out_of_range e)
	{
	  std::cerr << "{Skybox loading : " << e.what() << ". Error while loading "
		    << sstrm.str() << " in " << themeName << " theme}" << std::endl;
	};
      face->scale(glm::vec3(20000 - 10, 20000, 20000 - 10));
      _faces.push_back(face);
    }
}
void		Skybox::draw(gdl::AShader& shader, gdl::Clock const& clock)
{
  glDisable(GL_DEPTH_TEST);
  glDepthMask(GL_FALSE);
  for (auto i = _faces.begin(); i != _faces.end(); i++)
    (*i)->draw(shader, clock);
  glDepthMask(GL_TRUE);
  glEnable(GL_DEPTH_TEST);}

Skybox::~Skybox()
{

}
