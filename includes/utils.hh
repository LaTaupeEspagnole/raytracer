#pragma once

#include "fwd.hh"

#include <cmath>
#include <vector>

#include "vect.hh"
#include "ray.hh"
#include "screen.hh"
#include "camera.hh"
#include "shapable.hh"
#include "square.hh"
#include "pointlight.hh"
#include "color.hh"
#include "lightable.hh"

namespace raytracer
{
  const float pi = std::acos(-1);

  /* Rotates vect around the X-axis */
  void rotateX(Vect3& vect, const float angle);

  /* Rotates vect around the Y-axis */
  void rotateY(Vect3& vect, const float angle);

  /* Rotates vect around the Z-axis */
  void rotateZ(Vect3& vect, const float angle);

  /* Apply a vector of angles to a vector */
  Vect3 applyAngle(Vect3& vect, const Vect3& angles);

  /* Make a vector using the base vector (1, 0, 0) and aplying angles on it */
  Vect3 vectorFromAngles(const Vect3& angles);

  /* Returns a vector of angle for X, Y and Z axis to go from vect1 to vect2 */
  Vect3 getAngles(const Vect3& v1, const Vect3& v2);

  /* Make a vector with two points */
  Vect3 vectorFromPoints(const Vect3& v1, const Vect3& v2);

  /* Generates the screen rays */
  std::vector<Ray> genRays(const Camera& cam, const Screen& screen);

  /* Returns witch is the closer point from the origin
  ** (1 for point1 & 2 for point2)
  */
  int closerToOrigin(Vect3 origin, Vect3 point1, Vect3 point2);

  /* Generates a frame */
  std::vector<Color> renderFrame(const std::vector<Shapable*>& objects,
                                 const std::vector<Ray>& rays,
                                 const std::vector<Lightable*>& lightList);
}
