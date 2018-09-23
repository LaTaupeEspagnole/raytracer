#pragma once

#include "fwd.hh"

#include <optional>
#include <tuple>

#include "ray.hh"
#include "vect.hh"
#include "shapable.hh"
#include "color.hh"

namespace raytracer
{
  class Plan : public Shapable
  {
  public:
    Plan();
    Plan(const Plan& p);
    Plan(const Vect3& norm, const Vect3& point, const Color& color);

    Vect3 getNorm() const;
    float getD() const;
    Color getColor() const;
    void setColor(const Color& color);

    std::optional<std::tuple<Vect3, Color>>
      intersecte(const Ray& ray) override;

  private:
    Vect3 norm_;
    float d_;
    Color color_;
  };
}
