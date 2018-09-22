#pragma once

namespace raytracer
{
  class Color
  {
  public:
    Color();
    Color(const float r, const float g, const float b);

    float getR() const;
    float getG() const;
    float getB() const;
    void setR(const float v);
    void setG(const float v);
    void setB(const float v);

    Color operator+(const Color& other) const;
    Color operator-(const Color& other) const;
    Color operator*(const float other) const;
    friend Color operator*(const float num, const Color& color);

  private:
    float r_;
    float g_;
    float b_;
  };

  Color operator*(const float num, const Color& color);
}
