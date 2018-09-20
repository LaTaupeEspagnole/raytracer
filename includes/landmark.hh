#pragma once

#include "vect.hh"

namespace raytracer
{
  class Landmark
  {
  public:
    Landmark();
    Landmark(const Vect3& o,
             const Vect3& x,
             const Vect3& y,
             const Vect3& z);

    Vect3 getO() const;
    Vect3 getX() const;
    Vect3 getY() const;
    Vect3 getZ() const;

    Vect3 transposePoint(const Vect3& point) const;
    Vect3 transposeVect(const Vect3& vect) const;

  private:
    Vect3 o_;
    Vect3 x_;
    Vect3 y_;
    Vect3 z_;
  };
}
