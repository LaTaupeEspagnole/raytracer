#pragma once

#include "fwd.hh"

#include "vect.hh"
#include "camera.hh"

namespace raytracer
{
  class Screen
  {
  public:
    Screen(const Camera& camera, float width, float height);

    float getWidth() const;
    float getHeight() const;
    float getPixelSize() const;
    Vect3 getCenter() const;
    Vect3 getI() const;
    Vect3 getJ() const;

  private:
    float width_;
    float height_;
    float pixelSize_;
    Vect3 center_;
    Vect3 i_;
    Vect3 j_;
  };
}
