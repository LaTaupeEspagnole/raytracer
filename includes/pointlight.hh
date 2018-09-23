#pragma once

#include "fwd.hh"

#include <vector>

#include "vect.hh"
#include "color.hh"
#include "shapable.hh"

namespace raytracer
{
  class PointLight
  {
  public:
    PointLight(const Vect3& pos, const Color& color);

    Vect3 getPos();
    Color getColor();

    Color interact(const std::vector<Shapable*>& objects,
                   const Vect3& point) const;

  private:
    Vect3 pos_;
    Color color_;
  };
}
