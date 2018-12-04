#include "cube.hh"

#include "utils.hh"

gameobj::Cube::Cube(const raytracer::Vect3& center,
                      const float side,
                      const raytracer::Vect3& angles,
                      const raytracer::Color& color)
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

  squares_ = std::vector<gameobj::Square>();

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

  squares_.push_back(gameobj::Square(A, B, D, nABD, color));
  squares_.push_back(gameobj::Square(B, G, C, nBGC, color));
  squares_.push_back(gameobj::Square(G, F, H, nGFH, color));
  squares_.push_back(gameobj::Square(F, A, E, nFAE, color));
  squares_.push_back(gameobj::Square(D, C, E, nDCE, color));
  squares_.push_back(gameobj::Square(F, G, A, nFGA, color));
}

raytracer::Vect3 gameobj::Cube::getCenter() const
{
  return center_;
}

float gameobj::Cube::getSide() const
{
  return side_;
}

raytracer::Vect3 gameobj::Cube::getAngles() const
{
  return angles_;
}

raytracer::Landmark gameobj::Cube::getLandmark() const
{
  return landmark_;
}

raytracer::Color gameobj::Cube::getColor() const
{
  return squares_[0].getColor();
}

std::optional<std::tuple<raytracer::Vect3,
                         raytracer::Vect2,
                         gameobj::FlatShapable*>>
gameobj::Cube::intersecte(const raytracer::Ray& ray)
{
  unsigned i = 0;
  std::optional<std::tuple<raytracer::Vect3,
                           raytracer::Vect2,
                           gameobj::FlatShapable*>> closer
    = std::nullopt;

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
              std::get<0>(closer.value()), std::get<0>(cur.value())) == 2)
      closer = cur;

    ++i;
  }
  return closer;
}
