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

namespace gameobj
{
  class Cube : public Shapable
  {
  public:
    /*
    ** pos is the position of the cube's center
    ** landmark is the landmark of the cube
    ** objectAngles are the rotation to apply to the object after creating
    */
    Cube(const raytracer::Vect3& center,
         const float side,
         const raytracer::Vect3& angles,
         const raytracer::Color& color);

    raytracer::Vect3 getCenter() const;
    float getSide() const;
    raytracer::Vect3 getAngles() const;
    raytracer::Landmark getLandmark() const;
    raytracer::Color getColor() const;

    virtual std::optional<std::tuple<raytracer::Vect3, FlatShapable*>>
      intersecte(const raytracer::Ray& ray) override;

  private:
    raytracer::Vect3 center_;
    float side_;
    raytracer::Vect3 angles_;
    raytracer::Landmark landmark_;
    std::vector<Square> squares_;
  };
}
