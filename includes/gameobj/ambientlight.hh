#pragma once

#include "fwd.hh"

#include <vector>

#include "color.hh"
#include "lightable.hh"
#include "shapable.hh"
#include "flatshapable.hh"

namespace gameobj
{
  class AmbientLight : public Lightable
  {
  public:
    AmbientLight(const raytracer::Color& color, const float brightness);

    raytracer::Color getColor() const;
    float getBrightness() const;

    void setColor(const raytracer::Color& color);
    void setBrightness(const float brightness);

    virtual raytracer::Color interact(const std::vector<Shapable*>& obj,
                           const raytracer::Vect3& point,
                           const FlatShapable&) const override;

  private:
    raytracer::Color color_;
    float brightness_;
  };
}
