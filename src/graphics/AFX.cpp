//
// AFX.cpp for CPP_BOMBERMAN in /home/Jamais/cpp_bomberman/src/graphics
//
// Made by Jamais
// Login   <Jamais@epitech.net>
//
// Started on  Sat Jun  6 04:02:46 2015 Jamais
// Last update Sat Jun  6 19:13:28 2015 Jamais
//

#include	"AFX.hh"

AFX::AFX() : ComplexObject(), _index(0), _timer(0.5), _frameTimer(0.15)
{
  _currentFrame = NULL;
}

AFX::~AFX()
{}

void		AFX::update(gdl::Clock const& clock, Binput& input)
{
  _timer -= clock.getElapsed();
  if (_timer <= 0.0f)
    {
      _index = (_index >= _spareParts.size() - 1 ? 0 : _index + 1);
      _currentFrame = _spareParts[_index];
      _timer = _frameTimer;
    }
  if (_currentFrame)
    _currentFrame->update(clock, input);
}

void		AFX::update(gdl::Clock const& clock, Binput& input, Camera const& camera)
{
  _timer -= clock.getElapsed();
  if (_timer <= 0.0f)
    {
      _index = (_index >= _spareParts.size() - 1 ? 0 : _index + 1);
      _currentFrame = _spareParts[_index];
      _timer = _frameTimer;
    }
  if (_currentFrame)
    {
      _currentFrame->update(clock, input, camera);
    }
}

void		AFX::draw(gdl::AShader& shader, gdl::Clock const& clock)
{
  if (_currentFrame)
    {
      glDisable(GL_DEPTH_TEST);
      _currentFrame->draw(shader, clock);
      glEnable(GL_DEPTH_TEST);
    }
}

void		AFX::setTimer(float time)
{
  _timer = time;
  _frameTimer = time;
}
