#pragma once

#include "fwd.hh"

#include <optional>
#include <tuple>

#include "ray.hh"
#include "vect.hh"
#include "shapable.hh"
#include "color.hh"
#include "flatshapable.hh"

namespace raytracer
{
  class Plan : public Shapable, public FlatShapable
  {
  public:
    Plan();
    Plan(const Plan& p);
    Plan(const Vect3& norm, const Vect3& point, const Color& color);

    Vect3 getNorm() const;
    float getD() const;
    Color getColor() const override;
    void setColor(const Color& color);

    std::optional<std::tuple<Vect3, FlatShapable*>>
      intersecte(const Ray& ray) override;

  private:
    float d_;
    Vect3 norm_;
    Color color_;
  };
}
