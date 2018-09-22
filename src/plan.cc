#include "plan.hh"

float computeD(const raytracer::Vect3& p, const raytracer::Vect3& n)
{
  return -(n.getX() * p.getX() + n.getY() * p.getY() + n.getZ() * p.getZ());
}

raytracer::Plan::Plan()
{
  d_ = 0.0f;
  norm_ = raytracer::Vect3(1, 0, 0);
  color_ = raytracer::Color(1, 1, 1);
}

raytracer::Plan::Plan(const raytracer::Vect3& norm,
                      const raytracer::Vect3& point,
                      const raytracer::Color& color)
{
  d_ = computeD(point, norm);
  norm_ = norm;
  color_ = color;
}

raytracer::Plan::Plan(const raytracer::Plan& p)
{
  norm_ = p.getNorm();
  d_ = p.getD();
  color_ = p.getColor();
}

raytracer::Vect3 raytracer::Plan::getNorm() const
{
  return norm_;
}

float raytracer::Plan::getD() const
{
  return d_;
}

raytracer::Color raytracer::Plan::getColor() const
{
  return color_;
}

void raytracer::Plan::setColor(const raytracer::Color& color)
{
  color_ = color;
}

std::optional<std::tuple<raytracer::Vect3, raytracer::Color>>
raytracer::Plan::intersecte(const raytracer::Ray& ray)
{
  if (norm_.dot(ray.getVect()) == 0.0f)
    return std::nullopt;

  float t = -((norm_.dot(ray.getOrigin()) + d_) / norm_.dot(ray.getVect()));
  if (t < 0.001f)
    return std::nullopt;

  raytracer::Vect3 res =
              Vect3(ray.getOrigin().getX() + ray.getVect().getX() * t,
                    ray.getOrigin().getY() + ray.getVect().getY() * t,
                    ray.getOrigin().getZ() + ray.getVect().getZ() * t);

  return std::optional<std::tuple<raytracer::Vect3, raytracer::Color>>{
          std::make_tuple(res, color_)};
}
