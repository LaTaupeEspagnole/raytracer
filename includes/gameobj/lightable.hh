#pragma once

#include "fwd.hh"
#include "shapable.hh"
#include "flatshapable.hh"

namespace gameobj
{
  class Lightable
  {
  public:

    raytracer::Color getColor() const;
    float getBrightness() const;

    void setColor(const raytracer::Color& color);
    void setBrightness(const float brightness);

    virtual raytracer::Color interact(const std::vector<Shapable*>& obj,
                           const raytracer::Vect3& point,
                           const FlatShapable&) const = 0;
  };
}
