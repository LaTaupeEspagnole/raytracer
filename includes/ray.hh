#pragma once

#include "vect.hh"

namespace raytracer
{
  class Ray
  {
  public:
    Ray(const Vect3& origin, const Vect3& vect);

    Vect3 getOrigin() const;
    Vect3 getVect() const;

  private:
    Vect3 origin_;
    Vect3 vect_;
  };
}
