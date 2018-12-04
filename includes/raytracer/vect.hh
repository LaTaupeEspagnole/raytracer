#pragma once

/**
 * \file
 * \brief Vect2 and Vect3 class managing vector operation
 */

#include "fwd.hh"

namespace raytracer
{
  class Vect3
  {
  public:
    /**
     * \brief Default constructor.
     */
    Vect3();
    /**
     * \brief Intuitive constructor.
     * \param x value of the x coordinate.
     * \param y value of the y coordinate.
     * \param z value of the z coordinate.
     */
    Vect3(float x, float y, float z);
    /**
     * \brief Copy constructor.
     * \param v vect to copy.
     */
    Vect3(const Vect3& v);

    /**
     * \brief Getter of x value.
     * \return Value of x value.
     */
    float getX() const;
    /**
     * \brief Getter of y value.
     * \return Value of y value.
     */
    float getY() const;
    /**
     * \brief Getter of z value.
     * \return Value of z value.
     */
    float getZ() const;
    /**
     * \brief Setter of x value.
     * \param v value to set x with.
     */
    void setX(const float v);
    /**
     * \brief Setter of y value.
     * \param v value to set y with.
     */
    void setY(const float v);
    /**
     * \brief Setter of z value.
     * \param v value to set z with
    */
    void setZ(const float v);

    /**
     * \brief Check if the vector is null.
     * \return True if the vector is null, False otherwise.
     */
    bool isNullVect() const;
    /**
     * \brief Get the norm of the vector.
     * \return The norm of the vector.
     */
    float getNorm() const;
    /**
     * \brief Get the dot product of this vect with an other.
     * \return The dot product of the two vectors.
     */
    float dot(const Vect3& other) const;
    /**
     * \brief Normalize the vector.
     */
    void normalize();

    /**
     * \brief Overload of the opposite operator.
     * \return The opposite vector of this one.
     */
    Vect3 operator-() const;
    /**
     * \brief Overload of the addition operator between two vectors.
     * \param other the vector to add to this one.
     * \return A new vector.
     */
    Vect3 operator+(const Vect3& other) const;
    /**
     * \brief Overload of the subtraction operator between two vectors.
     * \param other the vector to subtract to this one.
     * \return A new vector.
     */
    Vect3 operator-(const Vect3& other) const;
    /**
     * \brief Overload of the product multiplication between a vector and a float.
     * \param other the float to multiply with this vector.
     * \return A new vector.
     */
    Vect3 operator*(const float other) const;
    friend Vect3 operator*(const float num, const Vect3& vect);

  private:
    float x_; /**< the x coordinate */
    float y_; /**< the y coordinate */
    float z_; /**< the z coordinate */
  };

  /**
   * \brief Overload of the product multiplication between a float and a vector.
   * \param num the float to multiply with the vector.
   * \param vect the vector to multiply with the float.
   * \return A new vector.
   */
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

    Vect2 operator-() const;
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
