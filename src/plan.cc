#include "plan.hh"
/*
float computeA(const Vect3& vect1, const Vect3& vect2)
{
  return vect1.getY() * vect2.getZ() - vect1.getZ() * vect2.getY();
}

float computeB(const Vect3& vect1, const Vect3& vect2)
{
  return vect1.getZ() * vect2.getX() - vect1.getX() * vect2.getZ();
}

float computeC(const Vect3& vect1, const Vect3& vect2)
{
  return vect1.getX() * vect2.getY() - vect1.getY() * vect2.getX();
}
*/
float computeD(const raytracer::Vect3& p, const raytracer::Vect3& n)
{
  return -(n.getX() * p.getX() + n.getY() * p.getY() + n.getZ() * p.getZ());
}

raytracer::Plan::Plan()
{
  d_ = 0.0f;
  norm_ = raytracer::Vect3(1, 0, 0);
}

raytracer::Plan::Plan(const raytracer::Vect3& norm,
                      const raytracer::Vect3& point)
{
  d_ = computeD(point, norm);
  norm_ = norm;
}

raytracer::Plan::Plan(const raytracer::Plan& p)
{
  norm_ = p.getNorm();
  d_ = p.getD();
}

raytracer::Vect3 raytracer::Plan::getNorm() const
{
  return norm_;
}

float raytracer::Plan::getD() const
{
  return d_;
}

std::optional<raytracer::Vect3>
raytracer::Plan::intersecte(raytracer::Ray& ray)
{
  if (norm_.dot(ray.getVect()) == 0.0f)
    return std::nullopt;

  float t = -((norm_.dot(ray.getOrigin()) + d_) / norm_.dot(ray.getVect()));
  raytracer::Vect3 res =
              Vect3(ray.getOrigin().getX() + ray.getVect().getX() * t,
                    ray.getOrigin().getY() + ray.getVect().getY() * t,
                    ray.getOrigin().getZ() + ray.getVect().getZ() * t);

  return std::optional<raytracer::Vect3>{res};
}
