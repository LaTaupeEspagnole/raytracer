#include "ray.hh"

raytracer::Ray::Ray(const raytracer::Vect3& origin,
                    const raytracer::Vect3& vect)
{
  origin_ = origin;
  vect_ = vect;
  vect_.normalize();
}

raytracer::Vect3 raytracer::Ray::getOrigin() const
{
  return origin_;
}

raytracer::Vect3 raytracer::Ray::getVect() const
{
  return vect_;
}
