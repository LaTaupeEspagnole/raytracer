#pragma once

#include <optional>

#include "vect.hh"
#include "ray.hh"

namespace raytracer
{
  class Shapable
  {
  public:
    virtual std::optional<Vect3> intersecte(Ray& ray) = 0;
  };
}
