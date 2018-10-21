#include "camera.hh"

#include "utils.hh"

raytracer::Camera::Camera()
{
  pos_ = raytracer::Vect3();
  angleVect_ = raytracer::Vect3(0.0f, 0.0f, 0.0f);
  viewAngle_ = raytracer::pi / 2;
}

raytracer::Camera::Camera(raytracer::Vect3 pos,
                          raytracer::Vect3 angleVect,
                          float viewAngle = raytracer::pi / 2)
{
  pos_ = pos;
  angleVect_ = angleVect;
  viewAngle_ = viewAngle;
}

raytracer::Vect3 raytracer::Camera::getPos() const
{
  return pos_;
}

raytracer::Vect3 raytracer::Camera::getAng() const
{
  return angleVect_;
}

float raytracer::Camera::getViewAngle() const
{
  return viewAngle_;
}
