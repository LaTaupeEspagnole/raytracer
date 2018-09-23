#include "color.hh"

raytracer::Color::Color()
  : r_(0)
  , g_(0)
  , b_(0)
{}

raytracer::Color::Color(const float r, const float g, const float b)
  : r_(r)
  , g_(g)
  , b_(b)
{}

float raytracer::Color::getR() const
{
  return r_;
}

float raytracer::Color::getG() const
{
  return g_;
}

float raytracer::Color::getB() const
{
  return b_;
}

void raytracer::Color::setR(const float v)
{
  r_ = v;
}

void raytracer::Color::setG(const float v)
{
  g_ = v;
}

void raytracer::Color::setB(const float v)
{
  b_ = v;
}

void raytracer::Color::normalize()
{
  if (r_ > 1.0f)
    r_ = 1.0f;
  if (g_ > 1.0f)
    g_ = 1.0f;
  if (b_ > 1.0f)
    b_ = 1.0f;
}

raytracer::Color
raytracer::Color::operator+(const raytracer::Color& other) const
{
  return raytracer::Color(r_ + other.getR(),
                          g_ + other.getG(),
                          b_ + other.getB());
}

raytracer::Color
raytracer::Color::operator+=(const raytracer::Color& other)
{
  r_ += other.getR();
  g_ += other.getG();
  b_ += other.getB();
  return *this;
}

raytracer::Color
raytracer::Color::operator-(const raytracer::Color& other) const
{
  return raytracer::Color(r_ - other.getR(),
                          g_ - other.getG(),
                          b_ - other.getB());
}

raytracer::Color
raytracer::Color::operator*(const float other) const
{
  return raytracer::Color(r_ * other,
                          g_ * other,
                          b_ * other);
}

raytracer::Color
raytracer::Color::operator*(const raytracer::Color& other) const
{
  return raytracer::Color(r_ * other.getR(),
                          g_ * other.getG(),
                          b_ * other.getB());
}

raytracer::Color
raytracer::operator*(const float num, const Color& color)
{
  return color * num;
}
