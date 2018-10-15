#include "pointlight.hh"

#include "utils.hh"
#include "ray.hh"

raytracer::PointLight::PointLight(const Vect3& pos,
                                  const Color& color,
                                  const float brightness)
  : pos_(pos)
  , color_(color)
  , brightness_(brightness)
{}

raytracer::Vect3 raytracer::PointLight::getPos() const
{
  return pos_;
}

raytracer::Color raytracer::PointLight::getColor() const
{
  return color_;
}

float raytracer::PointLight::getBrightness() const
{
  return brightness_;
}

void raytracer::PointLight::setPos(const raytracer::Vect3& pos)
{
  pos_ = pos;
}

void raytracer::PointLight::setColor(const raytracer::Color& color)
{
  color_ = color;
}

void raytracer::PointLight::setBrightness(const float brightness)
{
  brightness_ = brightness;
}

raytracer::Color
raytracer::PointLight::interact(const std::vector<raytracer::Shapable*>& objs,
                                const raytracer::Vect3& point,
                                const raytracer::FlatShapable& obj) const
{
  std::ignore = obj;

  auto rayDir = raytracer::vectorFromPoints(point, pos_);
  auto ray = raytracer::Ray(point, rayDir);
  if (ray.colidesBefore(objs, rayDir.getNorm()))
   return raytracer::Color(0, 0, 0);

  return color_ * (brightness_ / rayDir.getNorm());
}
