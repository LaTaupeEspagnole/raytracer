#include "vect.hh"

#include <cmath>

raytracer::Vect3::Vect3()
{
  x_ = 0;
  y_ = 0;
  z_ = 0;
}

raytracer::Vect3::Vect3(float x, float y, float z)
{
  x_ = x;
  y_ = y;
  z_ = z;
}

raytracer::Vect3::Vect3(const Vect3& v)
{
  x_ = v.getX();
  y_ = v.getY();
  z_ = v.getZ();
}

float raytracer::Vect3::getX() const
{
  return x_;
}

float raytracer::Vect3::getY() const
{
  return y_;
}

float raytracer::Vect3::getZ() const
{
  return z_;
}

void raytracer::Vect3::setX(const float v)
{
  x_ = v;
}

void raytracer::Vect3::setY(const float v)
{
  y_ = v;
}

void raytracer::Vect3::setZ(const float v)
{
  z_ = v;
}

bool raytracer::Vect3::isNullVect() const
{
  return x_ == 0.0f && y_ == 0.0f && z_ == 0.0f;
}

float raytracer::Vect3::getNorm() const
{
  return std::sqrt(std::pow(x_, 2)
                  + std::pow(y_, 2)
                  + std::pow(z_, 2));
}

float raytracer::Vect3::dot(const Vect3& other) const
{
  return x_ * other.getX() + y_ * other.getY() + z_ * other.getZ();
}

void raytracer::Vect3::normalize()
{
  float norm = this->getNorm();
  x_ = x_ / norm;
  y_ = y_ / norm;
  z_ = z_ / norm;
}

raytracer::Vect3 raytracer::Vect3::operator+(const Vect3& other) const
{
  return Vect3(x_ + other.getX(), y_ + other.getY(), z_ + other.getZ());
}

raytracer::Vect3 raytracer::Vect3::operator-(const Vect3& other) const
{
  return Vect3(x_ - other.getX(), y_ - other.getY(), z_ - other.getZ());
}

raytracer::Vect3 raytracer::Vect3::operator*(const float other) const
{
  return Vect3(x_ * other, y_ * other, z_ * other);
}

raytracer::Vect3 raytracer::operator*(const float num, const Vect3& vect)
{
  return Vect3(vect.getX() * num, vect.getY() * num, vect.getZ() * num);
}

raytracer::Vect2::Vect2()
{
  x_ = 0;
  y_ = 0;
}

raytracer::Vect2::Vect2(float x, float y)
{
  x_ = x;
  y_ = y;
}

raytracer::Vect2::Vect2(const Vect2& v)
{
  x_ = v.getX();
  y_ = v.getY();
}

float raytracer::Vect2::getX() const
{
  return x_;
}

float raytracer::Vect2::getY() const
{
  return y_;
}

void raytracer::Vect2::setX(const float v)
{
  x_ = v;
}

void raytracer::Vect2::setY(const float v)
{
  y_ = v;
}

bool raytracer::Vect2::isNullVect() const
{
  return x_ == 0.0f && y_ == 0.0f;
}

float raytracer::Vect2::getNorm() const
{
  return std::sqrt(std::pow(x_, 2) + std::pow(y_, 2));
}

float raytracer::Vect2::dot(const Vect2& other) const
{
  return x_ * other.getX() + y_ * other.getY();
}

void raytracer::Vect2::normalize()
{
  float norm = this->getNorm();
  x_ = x_ / norm;
  y_ = y_ / norm;
}

raytracer::Vect2 raytracer::Vect2::operator+(const Vect2& other) const
{
  return Vect2(x_ + other.getX(), y_ + other.getY());
}

raytracer::Vect2 raytracer::Vect2::operator-(const Vect2& other) const
{
  return Vect2(x_ - other.getX(), y_ - other.getY());
}

raytracer::Vect2 raytracer::Vect2::operator*(const float other) const
{
  return Vect2(x_ * other, y_ * other);
}

raytracer::Vect2 raytracer::operator*(const float num, const Vect2& vect)
{
  return Vect2(vect.getX() * num, vect.getY() * num);
}
