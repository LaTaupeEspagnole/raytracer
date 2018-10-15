#include "dirlight.hh"

#include "ray.hh"

raytracer::DirectionalLight::DirectionalLight(const Vect3& dir,
                                              const Color& color,
                                              const float brightness)
  : dir_(dir)
  , color_(color)
  , brightness_(brightness)
{}

raytracer::Vect3 raytracer::DirectionalLight::getDir() const
{
  return dir_;
}

raytracer::Color raytracer::DirectionalLight::getColor() const
{
  return color_;
}

float raytracer::DirectionalLight::getBrightness() const
{
  return brightness_;
}

void raytracer::DirectionalLight::setDir(const raytracer::Vect3& dir)
{
  dir_ = dir;
}

void raytracer::DirectionalLight::setColor(const raytracer::Color& color)
{
  color_ = color;
}

void raytracer::DirectionalLight::setBrightness(const float brightness)
{
  brightness_ = brightness;
}

raytracer::Color
raytracer::DirectionalLight::interact(
  const std::vector<raytracer::Shapable*>& objs,
  const raytracer::Vect3& point,
  const raytracer::FlatShapable&) const
{
  auto ray = raytracer::Ray(point, -dir_);
  if (ray.colides(objs))
    return raytracer::Color(0, 0, 0);

  return color_ * brightness_;
}
