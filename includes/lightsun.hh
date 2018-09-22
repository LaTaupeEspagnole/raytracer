#pragma once

#include "vect.hh"

namespace raytracer
{
  class LightSun
  {
  public:
    LightSun(const Vect3& pos, const Vect3& color);

    Vect3 getPos();
    Vect3 getColor();

  private:
    Vect3 pos_;
    Vect3 color_;
  };
}
