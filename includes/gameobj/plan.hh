#pragma once

#include "fwd.hh"

#include <optional>
#include <tuple>

#include "ray.hh"
#include "vect.hh"
#include "shapable.hh"
#include "color.hh"
#include "flatshapable.hh"

namespace gameobj
{
  class Plan : public Shapable, public FlatShapable
  {
  public:
    Plan();
    Plan(const Plan& p);
    Plan(const raytracer::Vect3& norm,
          const raytracer::Vect3& point,
          const raytracer::Color& color);

    raytracer::Vect3 getNorm() const;
    float getD() const;
    raytracer::Color getColor() const override;
    void setColor(const raytracer::Color& color);

    std::optional<std::tuple<raytracer::Vect3, FlatShapable*>>
      intersecte(const raytracer::Ray& ray) override;

  private:
    float d_;
    raytracer::Vect3 norm_;
    raytracer::Color color_;
  };
}
