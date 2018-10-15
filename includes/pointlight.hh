#pragma once

#include "fwd.hh"

#include <vector>

#include "vect.hh"
#include "color.hh"
#include "shapable.hh"
#include "lightable.hh"
#include "flatshapable.hh"

namespace raytracer
{
  class PointLight : public Lightable
  {
  public:
    PointLight(const Vect3& pos, const Color& color, const float brightness);

    Vect3 getPos() const;
    Color getColor() const;
    float getBrightness() const;

    void setPos(const Vect3& pos);
    void setColor(const Color& color);
    void setBrightness(const float brightness);

    virtual Color interact(const std::vector<Shapable*>& obj,
                           const Vect3& point,
                           const FlatShapable&) const override;

  private:
    Vect3 pos_;
    Color color_;
    float brightness_;
  };
}
