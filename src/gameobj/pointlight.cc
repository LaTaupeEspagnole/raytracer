#include "pointlight.hh"

#include "utils.hh"
#include "ray.hh"

gameobj::PointLight::PointLight(const raytracer::Vect3& pos,
                                  const raytracer::Color& color,
                                  const float brightness)
  : pos_(pos)
  , color_(color)
  , brightness_(brightness)
{}

raytracer::Vect3 gameobj::PointLight::getPos() const
{
  return pos_;
}

raytracer::Color gameobj::PointLight::getColor() const
{
  return color_;
}

float gameobj::PointLight::getBrightness() const
{
  return brightness_;
}

void gameobj::PointLight::setPos(const raytracer::Vect3& pos)
{
  pos_ = pos;
}

void gameobj::PointLight::setColor(const raytracer::Color& color)
{
  color_ = color;
}

void gameobj::PointLight::setBrightness(const float brightness)
{
  brightness_ = brightness;
}

raytracer::Color
gameobj::PointLight::interact(const std::vector<gameobj::Shapable*>& objs,
                                const raytracer::Vect3& point,
                                const gameobj::FlatShapable& obj) const
{
  std::ignore = obj;

  auto rayDir = raytracer::vectorFromPoints(point, pos_);
  auto ray = raytracer::Ray(point, rayDir);
  if (ray.colidesBefore(objs, rayDir.getNorm()))
   return raytracer::Color(0, 0, 0);

  return color_ * (brightness_ / rayDir.getNorm());
}
