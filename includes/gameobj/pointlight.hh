#pragma once

#include "fwd.hh"

#include <vector>

#include "vect.hh"
#include "color.hh"
#include "shapable.hh"
#include "lightable.hh"
#include "flatshapable.hh"

namespace gameobj
{
  class PointLight : public Lightable
  {
  public:
    PointLight(const raytracer::Vect3& pos,
                const raytracer::Color& color,
                const float brightness);

    raytracer::Vect3 getPos() const;
    raytracer::Color getColor() const;
    float getBrightness() const;

    void setPos(const raytracer::Vect3& pos);
    void setColor(const raytracer::Color& color);
    void setBrightness(const float brightness);

    virtual raytracer::Color interact(const std::vector<Shapable*>& obj,
                           const raytracer::Vect3& point,
                           const FlatShapable&) const override;

  private:
    raytracer::Vect3 pos_;
    raytracer::Color color_;
    float brightness_;
  };
}
