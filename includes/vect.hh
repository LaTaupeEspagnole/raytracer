#pragma once

namespace raytracer
{
  class Vect3
  {
  public:
    Vect3();
    Vect3(float x, float y, float z);
    Vect3(const Vect3& v);

    float getX() const;
    float getY() const;
    float getZ() const;
    void setX(const float v);
    void setY(const float v);
    void setZ(const float v);

    bool isNullVect() const;
    float getNorm() const;
    float dot(const Vect3& other) const;
    void normalize();

    Vect3 operator+(const Vect3& other) const;
    Vect3 operator-(const Vect3& other) const;
    Vect3 operator*(const float other) const;
    friend Vect3 operator*(const float num, const Vect3& vect);

  private:
    float x_;
    float y_;
    float z_;
  };

  Vect3 operator*(const float num, const Vect3& vect);

  class Vect2
  {
  public:
    Vect2();
    Vect2(float x, float y);
    Vect2(const Vect2& v);

    float getX() const;
    float getY() const;
    void setX(const float v);
    void setY(const float v);

    bool isNullVect() const;
    float getNorm() const;
    float dot(const Vect2& other) const;
    void normalize();

    Vect2 operator+(const Vect2& other) const;
    Vect2 operator-(const Vect2& other) const;
    Vect2 operator*(const float other) const;
    friend Vect2 operator*(const float num, const Vect2& vect);

    private:
      float x_;
      float y_;
  };

  Vect2 operator*(const float num, const Vect2& vect);
}
