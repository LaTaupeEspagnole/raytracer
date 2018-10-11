#pragma once

#include "fwd.hh"

#include <vector>

#include "vect.hh"
#include "color.hh"
#include "shapable.hh"
#include "lightable.hh"

namespace raytracer
{
  class DirectionalLight : public Lightable
  {
  public:
    DirectionalLight(const Vect3& dir,
                     const Color& color,
                     const float brightness);

    Vect3 getDir() const;
    Color getColor() const;
    float getBrightness() const;

    void setDir(const Vect3& dir);
    void setColor(const Color& color);
    void setBrightness(const float brightness);

    virtual Color interact(const std::vector<Shapable*>& obj,
                           const Vect3& point,
                           const Shapable&) const override;

  private:
    Vect3 dir_;
    Color color_;
    float brightness_;
  };
}
