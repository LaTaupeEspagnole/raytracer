#pragma once

#include "fwd.hh"

#include <vector>
#include <tuple>

#include "ray.hh"
#include "vect.hh"
#include "square.hh"
#include "shapable.hh"
#include "landmark.hh"
#include "color.hh"
#include "flatshapable.hh"

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
         const Vect3& angles,
         const Color& color);

    Vect3 getCenter() const;
    float getSide() const;
    Vect3 getAngles() const;
    Landmark getLandmark() const;
    Color getColor() const;

    virtual std::optional<std::tuple<Vect3, FlatShapable*>>
      intersecte(const Ray& ray) override;

  private:
    Vect3 center_;
    float side_;
    Vect3 angles_;
    Landmark landmark_;
    std::vector<Square> squares_;
  };
}
