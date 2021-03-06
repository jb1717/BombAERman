//
// ABomb.hh for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Wed May 20 19:18:56 2015 Jamais
// Last update Fri Jun 12 03:59:36 2015 Jamais
//

#ifndef			____ABOMB_HH___
# define		____ABOMB_HH___

# include		"graphics.hh"

# include		"AGameObject.hh"
# include		"AGameModel.hh"

class			ABomb : public AGameModel
{
protected:
  float			_timer;

public:
  ABomb();
  ABomb(glm::vec3 const& _position);
  ABomb(std::string const& filePath);
  ABomb(glm::vec3 const& _position, std::string const& filePath);
  ABomb(std::string const& filePath, glm::vec3 const& _position);

public:
  ~ABomb();

public:
  void			update(gdl::Clock const& clock, Binput& input);

public:
  float			getTimer() const;

public:
  void			setTimer(float timer);

public:
  bool			isExplosed();
};

#endif			/* !____ABOMB_HH___ */
