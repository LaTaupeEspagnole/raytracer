#include "dirlight.hh"

#include "ray.hh"

gameobj::DirectionalLight::DirectionalLight(const raytracer::Vect3& dir,
                                              const raytracer::Color& color,
                                              const float brightness)
  : dir_(dir)
  , color_(color)
  , brightness_(brightness)
{}

raytracer::Vect3 gameobj::DirectionalLight::getDir() const
{
  return dir_;
}

raytracer::Color gameobj::DirectionalLight::getColor() const
{
  return color_;
}

float gameobj::DirectionalLight::getBrightness() const
{
  return brightness_;
}

void gameobj::DirectionalLight::setDir(const raytracer::Vect3& dir)
{
  dir_ = dir;
}

void gameobj::DirectionalLight::setColor(const raytracer::Color& color)
{
  color_ = color;
}

void gameobj::DirectionalLight::setBrightness(const float brightness)
{
  brightness_ = brightness;
}

raytracer::Color
gameobj::DirectionalLight::interact(
  const std::vector<gameobj::Shapable*>& objs,
  const raytracer::Vect3& point,
  const gameobj::FlatShapable&) const
{
  auto ray = raytracer::Ray(point, -dir_);
  if (ray.colides(objs))
    return raytracer::Color(0, 0, 0);

  return color_ * brightness_;
}
