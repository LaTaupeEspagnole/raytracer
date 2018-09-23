#include "pointlight.hh"

#include "utils.hh"
#include "ray.hh"

raytracer::PointLight::PointLight(const Vect3& pos, const Color& color)
  : pos_(pos)
  , color_(color)
{}

raytracer::Vect3 raytracer::PointLight::getPos()
{
  return pos_;
}

raytracer::Color raytracer::PointLight::getColor()
{
  return color_;
}

raytracer::Color
raytracer::PointLight::interact(const std::vector<raytracer::Shapable*>& objects,
                                const raytracer::Vect3& point) const
{
  auto rayDir = raytracer::vectorFromPoints(point, pos_);
  auto ray = raytracer::Ray(point, rayDir);
  if (ray.colides(objects))
   return raytracer::Color(0, 0, 0);

  return color_; // light mitigation formula to add
}
