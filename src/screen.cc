#include "screen.hh"

#include <cmath>

#include "utils.hh"

raytracer::Screen::Screen(const raytracer::Camera &camera, float width,
                          float height)
{
  width_ = width;
  height_ = height;

  pixelSize_ = (2 * std::tan(camera.getViewAngle() / 2)) / width;

  raytracer::Vect3 camDir = raytracer::vectorFromAngles(camera.getAng());
  center_ = camera.getPos() + camDir;

  i_ = raytracer::Vect3(camDir.getX(), camDir.getY(), 0.0f);
  raytracer::rotateZ(i_, -pi / 2);
  i_.normalize();

  Vect3 xyDir = raytracer::Vect3(camDir.getX(), camDir.getY(), 0.0f);
  Vect3 angles = raytracer::getAngles(xyDir, camDir);
  j_ = raytracer::Vect3(0, 0, 1);
  raytracer::applyAngle(j_, angles);
  j_.normalize();
}

float raytracer::Screen::getWidth() const
{
  return width_;
}

float raytracer::Screen::getHeight() const
{
  return height_;
}

float raytracer::Screen::getPixelSize() const
{
  return pixelSize_;
}

raytracer::Vect3 raytracer::Screen::getCenter() const
{
  return center_;
}

raytracer::Vect3 raytracer::Screen::getI() const
{
  return i_;
}

raytracer::Vect3 raytracer::Screen::getJ() const
{
  return j_;
}
