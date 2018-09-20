#pragma once

#include <optional>

#include "ray.hh"
#include "vect.hh"
#include "shapable.hh"

namespace raytracer
{
  class Plan : public Shapable
  {
  public:
    Plan();
    Plan(const Plan& p);
    Plan(const Vect3& norm, const Vect3& point);

    Vect3 getNorm() const;
    float getD() const;

    std::optional<Vect3> intersecte(Ray& ray) override;

  private:
    Vect3 norm_;
    float d_;
  };
}
