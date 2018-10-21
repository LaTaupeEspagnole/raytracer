#pragma once

#include "fwd.hh"

#include <vector>

#include "vect.hh"
#include "shapable.hh"

namespace raytracer
{
  class Ray
  {
  public:
    Ray(const Vect3& origin, const Vect3& vect);

    Vect3 getOrigin() const;
    Vect3 getVect() const;

    bool colidesBefore(const std::vector<gameobj::Shapable*>& objects,
                       const float dist) const;

    bool colides(const std::vector<gameobj::Shapable*>& objects) const;

  private:
    Vect3 origin_;
    Vect3 vect_;
  };
}
