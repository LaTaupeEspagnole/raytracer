#pragma once

#include "fwd.hh"

#include <optional>
#include <tuple>

#include "ray.hh"
#include "vect.hh"
#include "plan.hh"
#include "shapable.hh"
#include "color.hh"
#include "flatshapable.hh"

namespace gameobj
{
  class Square : public Shapable, public FlatShapable
  {
  public:
    Square(const Square& s);
    Square(const raytracer::Vect3& A,
           const raytracer::Vect3& B,
           const raytracer::Vect3& D,
           const raytracer::Vect3& norm,
           const raytracer::Color& color);

    raytracer::Vect3 getPos() const;
    raytracer::Vect3 getAB() const;
    raytracer::Vect3 getAD() const;
    gameobj::Plan getPlan() const;
    raytracer::Color getColor() const override;

    virtual std::optional<std::tuple<raytracer::Vect3, FlatShapable*>>
      intersecte(const raytracer::Ray& ray) override;

  private:
    Plan p_;
    raytracer::Vect3 pA_;
    raytracer::Vect3 vAB_;
    raytracer::Vect3 vAD_;
  };
}
