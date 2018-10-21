#include "ambientlight.hh"

gameobj::AmbientLight::AmbientLight(const raytracer::Color& color,
                                      const float brightness)
  : color_(color)
  , brightness_(brightness)
{}

raytracer::Color gameobj::AmbientLight::getColor() const
{
  return color_;
}

float gameobj::AmbientLight::getBrightness() const
{
  return brightness_;
}

void gameobj::AmbientLight::setColor(const raytracer::Color& color)
{
  color_ = color;
}

void gameobj::AmbientLight::setBrightness(const float brightness)
{
  brightness_ = brightness;
}

raytracer::Color
gameobj::AmbientLight::interact(const std::vector<gameobj::Shapable*>& objs,
                                  const raytracer::Vect3& point,
                                  const gameobj::FlatShapable& obj) const
{
  std::ignore = objs;
  std::ignore = point;
  std::ignore = obj;
  return color_ * brightness_;
}
