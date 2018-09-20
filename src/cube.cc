#include "cube.hh"

#include "utils.hh"

raytracer::Cube::Cube(const Vect3& center,
                      const float side,
                      const Vect3& angles)
{
  center_ = center;
  side_ = side;
  angles_ = angles;

  auto xi = raytracer::Vect3(1, 0, 0);
  auto yi = raytracer::Vect3(0, 1, 0);
  auto zi = raytracer::Vect3(0, 0, 1);

  auto x = raytracer::applyAngle(xi, angles);
  auto y = raytracer::applyAngle(yi, angles);
  auto z = raytracer::applyAngle(zi, angles);
  landmark_ = raytracer::Landmark(center, x, y, z);

  squares_ = std::vector<raytracer::Square>();

  float semSide = side / 2;
  auto A = landmark_.transposePoint(raytracer::Vect3(-semSide,  semSide,  semSide));
  auto B = landmark_.transposePoint(raytracer::Vect3(-semSide, -semSide,  semSide));
  auto C = landmark_.transposePoint(raytracer::Vect3(-semSide, -semSide, -semSide));
  auto D = landmark_.transposePoint(raytracer::Vect3(-semSide,  semSide, -semSide));
  auto E = landmark_.transposePoint(raytracer::Vect3( semSide,  semSide, -semSide));
  auto F = landmark_.transposePoint(raytracer::Vect3( semSide,  semSide,  semSide));
  auto G = landmark_.transposePoint(raytracer::Vect3( semSide, -semSide,  semSide));
  auto H = landmark_.transposePoint(raytracer::Vect3( semSide, -semSide, -semSide));
  auto nABD = landmark_.transposeVect(raytracer::Vect3(-1, 0, 0));
  auto nBGC = landmark_.transposeVect(raytracer::Vect3(0, -1, 0));
  auto nGFH = landmark_.transposeVect(raytracer::Vect3(1, 0, 0));
  auto nFAE = landmark_.transposeVect(raytracer::Vect3(0, 1, 0));
  auto nDCE = landmark_.transposeVect(raytracer::Vect3(0, 0, -1));
  auto nFGA = landmark_.transposeVect(raytracer::Vect3(0, 0, 1));

  squares_.push_back(raytracer::Square(A, B, D, nABD));
  squares_.push_back(raytracer::Square(B, G, C, nBGC));
  squares_.push_back(raytracer::Square(G, F, H, nGFH));
  squares_.push_back(raytracer::Square(F, A, E, nFAE));
  squares_.push_back(raytracer::Square(D, C, E, nDCE));
  squares_.push_back(raytracer::Square(F, G, A, nFGA));
}

raytracer::Vect3 raytracer::Cube::getCenter() const
{
  return center_;
}

float raytracer::Cube::getSide() const
{
  return side_;
}

raytracer::Vect3 raytracer::Cube::getAngles() const
{
  return angles_;
}

raytracer::Landmark raytracer::Cube::getLandmark() const
{
  return landmark_;
}

std::optional<raytracer::Vect3> raytracer::Cube::intersecte(raytracer::Ray& ray)
{
  unsigned i = 0;
  std::optional<Vect3> closer = std::nullopt;

  while (i < squares_.size() && !closer.has_value())
  {
    closer = squares_[i].intersecte(ray);
    ++i;
  }

  while (i < squares_.size())
  {
    auto cur = squares_[i].intersecte(ray);
    if (cur.has_value()
        && raytracer::closerToOrigin(ray.getOrigin(),
              closer.value(), cur.value()) == 2)
      closer = cur;

    ++i;
  }
  return closer;
}
