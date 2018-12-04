#include "plan.hh"

float computeD(const raytracer::Vect3& p, const raytracer::Vect3& n)
{
  return -(n.getX() * p.getX() + n.getY() * p.getY() + n.getZ() * p.getZ());
}

gameobj::Plan::Plan()
  : d_(0.0f)
  , norm_(raytracer::Vect3(1, 0, 0))
  , color_(raytracer::Color(1, 1, 1))
{}

gameobj::Plan::Plan(const raytracer::Vect3& norm,
                      const raytracer::Vect3& point,
                      const raytracer::Color& color)
  : d_(computeD(point, norm))
  , norm_(norm)
  , color_(color)
{}

gameobj::Plan::Plan(const gameobj::Plan& p)
  : d_(p.getD())
  , norm_(p.getNorm())
  , color_(p.getColor())
{}

raytracer::Vect3 gameobj::Plan::getNorm() const
{
  return norm_;
}

float gameobj::Plan::getD() const
{
  return d_;
}

raytracer::Color gameobj::Plan::getColor() const
{
  return color_;
}

void gameobj::Plan::setColor(const raytracer::Color& color)
{
  color_ = color;
}

std::optional<std::tuple<raytracer::Vect3,
                         raytracer::Vect2,
                         gameobj::FlatShapable*>>
gameobj::Plan::intersecte(const raytracer::Ray& ray)
{
  if (norm_.dot(ray.getVect()) == 0.0f)
    return std::nullopt;

  float t = -((norm_.dot(ray.getOrigin()) + d_) / norm_.dot(ray.getVect()));
  if (t < 0.001f) // threashhold to prevent auto colision
    return std::nullopt;

  auto res =  raytracer::Vect3(ray.getOrigin().getX() + ray.getVect().getX() * t,
                    ray.getOrigin().getY() + ray.getVect().getY() * t,
                    ray.getOrigin().getZ() + ray.getVect().getZ() * t);

  return std::make_tuple(res, raytracer::Vect2(), this);
}
