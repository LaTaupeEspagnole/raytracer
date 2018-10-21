#pragma once

#include "fwd.hh"

#include "vect.hh"

namespace raytracer
{
  class Camera
  {
  public:
    Camera();
    Camera(Vect3 pos, Vect3 angleVect, float viewAngle);

    Vect3 getPos() const;
    Vect3 getAng() const;
    float getViewAngle() const;

  private:
    Vect3 pos_;
    Vect3 angleVect_;
    float viewAngle_;
  };
}
