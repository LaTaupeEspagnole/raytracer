#pragma once

#include <optional>
#include <tuple>

#include "vect.hh"
#include "ray.hh"
#include "color.hh"

namespace raytracer
{
  class Shapable
  {
  public:
    virtual std::optional<std::tuple<Vect3, Color>>
      intersecte(const Ray& ray) = 0;
  };
}
