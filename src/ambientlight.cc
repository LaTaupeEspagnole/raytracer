#include "ambientlight.hh"

raytracer::AmbientLight::AmbientLight(const raytracer::Color& color,
                                      const float brightness)
  : color_(color)
  , brightness_(brightness)
{}

raytracer::Color raytracer::AmbientLight::getColor() const
{
  return color_;
}

float raytracer::AmbientLight::getBrightness() const
{
  return brightness_;
}

void raytracer::AmbientLight::setColor(const raytracer::Color& color)
{
  color_ = color;
}

void raytracer::AmbientLight::setBrightness(const float brightness)
{
  brightness_ = brightness;
}

raytracer::Color
raytracer::AmbientLight::interact(const std::vector<raytracer::Shapable*>& objs,
                                  const raytracer::Vect3& point,
                                  const raytracer::FlatShapable& obj) const
{
  std::ignore = objs;
  std::ignore = point;
  std::ignore = obj;
  return color_ * brightness_;
}
