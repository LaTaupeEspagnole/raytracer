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

namespace raytracer
{
  class Square : public Shapable, public FlatShapable
  {
  public:
    Square(const Square& s);
    Square(const Vect3& A,
           const Vect3& B,
           const Vect3& D,
           const Vect3& norm,
           const Color& color);

    Vect3 getPos() const;
    Vect3 getAB() const;
    Vect3 getAD() const;
    Plan getPlan() const;
    Color getColor() const override;

    virtual std::optional<std::tuple<Vect3, FlatShapable*>>
      intersecte(const Ray& ray) override;

  private:
    Plan p_;
    Vect3 pA_;
    Vect3 vAB_;
    Vect3 vAD_;
  };
}
