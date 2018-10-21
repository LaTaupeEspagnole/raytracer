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
  class DirectionalLight : public Lightable
  {
  public:
    DirectionalLight(const raytracer::Vect3& dir,
                     const raytracer::Color& color,
                     const float brightness);

    raytracer::Vect3 getDir() const;
    raytracer::Color getColor() const;
    float getBrightness() const;

    void setDir(const raytracer::Vect3& dir);
    void setColor(const raytracer::Color& color);
    void setBrightness(const float brightness);

    virtual raytracer::Color interact(const std::vector<Shapable*>& obj,
                           const raytracer::Vect3& point,
                           const FlatShapable&) const override;

  private:
    raytracer::Vect3 dir_;
    raytracer::Color color_;
    float brightness_;
  };
}
