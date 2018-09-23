#include "ray.hh"

#include <tuple>
#include <optional>

#include "color.hh"

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

bool
raytracer::Ray::colides(const std::vector<raytracer::Shapable*>& objects) const
{
  for (auto o : objects)
  {
    if (o->intersecte(*this).has_value())
      return true;
  }
  return false;
}
