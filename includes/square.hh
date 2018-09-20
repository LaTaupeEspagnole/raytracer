#pragma once

#include <optional>

#include "vect.hh"
#include "plan.hh"
#include "ray.hh"
#include "shapable.hh"

namespace raytracer
{
  class Square : public Shapable
  {
  public:
    Square(const Square& s);
    Square(const Vect3& A,
           const Vect3& B,
           const Vect3& D,
           const Vect3& norm);

    Vect3 getPos() const;
    Vect3 getAB() const;
    Vect3 getAD() const;
    Plan getPlan() const;

    virtual std::optional<Vect3> intersecte(Ray& ray) override;

  private:
    Plan p_;
    Vect3 pA_;
    Vect3 vAB_;
    Vect3 vAD_;
  };
}
