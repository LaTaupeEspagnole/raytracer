#pragma once

#include <vector>

#include "vect.hh"
#include "square.hh"
#include "shapable.hh"
#include "landmark.hh"

namespace raytracer
{
  class Cube : public Shapable
  {
  public:
    /*
    ** pos is the position of the cube's center
    ** landmark is the landmark of the cube
    ** objectAngles are the rotation to apply to the object after creating
    */
    Cube(const Vect3& center,
         const float side,
         const Vect3& angles);

    Vect3 getCenter() const;
    float getSide() const;
    Vect3 getAngles() const;
    Landmark getLandmark() const;

    virtual std::optional<Vect3> intersecte(Ray& ray) override;

  private:
    Vect3 center_;
    float side_;
    Vect3 angles_;
    Landmark landmark_;
    std::vector<Square> squares_;
  };
}
