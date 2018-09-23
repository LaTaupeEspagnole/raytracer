#pragma once

#include "fwd.hh"

#include <optional>
#include <tuple>

#include "vect.hh"
#include "ray.hh"
#include "color.hh"
#include "shapable.hh"

namespace raytracer
{
  class Shapable
  {
  public:

    virtual Color getColor() const = 0;

    virtual std::optional<std::tuple<Vect3, Shapable*>>
      intersecte(const Ray& ray) = 0;
  };
}
