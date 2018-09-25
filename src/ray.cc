#include "ray.hh"

#include <tuple>
#include <optional>

#include "color.hh"
#include "utils.hh"

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
raytracer::Ray::colidesBefore(const std::vector<raytracer::Shapable*>& objects,
                              const float dist) const
{
  for (auto o : objects)
  {
    auto inter = o->intersecte(*this);
    if (inter.has_value())
    {
      auto distObj
        = raytracer::vectorFromPoints(origin_,
                                      std::get<0>(inter.value())).getNorm();
      if (distObj < dist)
        return true;
    }
  }
  return false;
}
