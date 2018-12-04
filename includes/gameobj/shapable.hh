#pragma once

#include "fwd.hh"

#include <optional>
#include <tuple>

#include "vect.hh"
#include "ray.hh"
#include "color.hh"
#include "shapable.hh"
#include "flatshapable.hh"

namespace gameobj
{
  class Shapable
  {
  public:

    virtual raytracer::Color getColor() const = 0;

    virtual std::optional<std::tuple<raytracer::Vect3,
                                     raytracer::Vect2,
                                     FlatShapable*>>
      intersecte(const raytracer::Ray& ray) = 0;
  };
}
