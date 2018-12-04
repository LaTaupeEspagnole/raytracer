#include "square.hh"

#include "utils.hh"

gameobj::Square::Square(const raytracer::Vect3& A,
                        const raytracer::Vect3& B,
                        const raytracer::Vect3& D,
                        const raytracer::Vect3& norm,
                        const raytracer::Color& color)
  : p_(gameobj::Plan(norm, A, color))
  , pA_(A)
  , vAB_(raytracer::vectorFromPoints(A, B))
  , vAD_(raytracer::vectorFromPoints(A, D))
{}

gameobj::Square::Square(const gameobj::Square& s)
  : p_(s.getPlan())
  , pA_(s.getPos())
  , vAB_(s.getAB())
  , vAD_(s.getAD())
{}

raytracer::Vect3 gameobj::Square::getPos() const
{
  return pA_;
}

raytracer::Vect3 gameobj::Square::getAB() const
{
  return vAB_;
}

raytracer::Vect3 gameobj::Square::getAD() const
{
  return vAD_;
}

gameobj::Plan gameobj::Square::getPlan() const
{
  return p_;
}

raytracer::Color gameobj::Square::getColor() const
{
  return p_.getColor();
}

std::optional<std::tuple<raytracer::Vect3,
                         raytracer::Vect2,
                         gameobj::FlatShapable*>>
gameobj::Square::intersecte(const raytracer::Ray& ray)
{
  auto inter = p_.intersecte(ray);
  if (!inter.has_value())
    return std::nullopt;

  raytracer::Vect3 P = std::get<0>(inter.value());
  raytracer::Vect3 AP = raytracer::vectorFromPoints(pA_, P);

  float a = AP.dot(vAB_);
  float b = AP.dot(vAD_);
  if (a >= 0.0f && a <= vAB_.dot(vAB_) && b >= 0.0f && b <= vAD_.dot(vAD_))
    return std::make_tuple(std::get<0>(inter.value()), raytracer::Vect2(a, b), this);
  return std::nullopt;
}
