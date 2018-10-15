#pragma once

#include "fwd.hh"
#include "shapable.hh"
#include "flatshapable.hh"

namespace raytracer
{
  class Lightable
  {
  public:

    Color getColor() const;
    float getBrightness() const;

    void setColor(const Color& color);
    void setBrightness(const float brightness);

    virtual Color interact(const std::vector<Shapable*>& obj,
                           const Vect3& point,
                           const FlatShapable&) const = 0;
  };
}
