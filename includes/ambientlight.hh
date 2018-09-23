#pragma once

#include "fwd.hh"

#include <vector>

#include "color.hh"
#include "lightable.hh"
#include "shapable.hh"

namespace raytracer
{
  class AmbientLight : public Lightable
  {
  public:
    AmbientLight(const Color& color, const float brightness);

    Color getColor() const;
    float getBrightness() const;

    void setColor(const Color& color);
    void setBrightness(const float brightness);

    virtual Color interact(const std::vector<Shapable*>& obj,
                           const Vect3& point,
                           const Shapable&) const override;

  private:
    Color color_;
    float brightness_;
  };
}
