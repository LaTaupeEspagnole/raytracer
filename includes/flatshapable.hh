#pragma once

#include "fwd.hh"

#include <optional>
#include <tuple>

#include "vect.hh"
#include "ray.hh"
#include "color.hh"

namespace raytracer
{
  class FlatShapable
  {
  public:
    virtual Color getColor() const = 0;

    virtual std::optional<std::tuple<Vect3, FlatShapable*>>
      intersecte(const Ray& ray) = 0;
  };
}
