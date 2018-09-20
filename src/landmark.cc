#include "landmark.hh"

raytracer::Landmark::Landmark()
{
  o_ = raytracer::Vect3(0, 0, 0);
  x_ = raytracer::Vect3(0, 0, 0);
  y_ = raytracer::Vect3(0, 0, 0);
  z_ = raytracer::Vect3(0, 0, 0);
}

raytracer::Landmark::Landmark(const raytracer::Vect3& o,
                              const raytracer::Vect3& x,
                              const raytracer::Vect3& y,
                              const raytracer::Vect3& z)
{
  o_ = o;
  x_ = x;
  y_ = y;
  z_ = z;
}

raytracer::Vect3 raytracer::Landmark::getO() const
{
  return o_;
}

raytracer::Vect3 raytracer::Landmark::getX() const
{
  return x_;
}

raytracer::Vect3 raytracer::Landmark::getY() const
{
  return y_;
}

raytracer::Vect3 raytracer::Landmark::getZ() const
{
  return z_;
}

raytracer::Vect3
raytracer::Landmark::transposeVect(const raytracer::Vect3& vect) const
{
  return vect.getX() * x_ + vect.getY() * y_ + vect.getZ() * z_;
}

raytracer::Vect3
raytracer::Landmark::transposePoint(const raytracer::Vect3& point) const
{
  return this->transposeVect(point) + o_;
}
