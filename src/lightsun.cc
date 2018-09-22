#include "lightsun.hh"

raytracer::LightSun::LightSun(const Vect3& pos, const Vect3& color)
  : pos_(pos)
  , color_(color)
{}

raytracer::Vect3 raytracer::LightSun::getPos()
{
  return pos_;
}

raytracer::Vect3 raytracer::LightSun::getColor()
{
  return color_;
}
