#include "utils.hh"

#include <optional>
#include <tuple>

#include "flatshapable.hh"

void raytracer::rotateX(raytracer::Vect3& vect, const float angle)
{
  float y = vect.getY();
  float z = vect.getZ();
  vect.setY(y * std::cos(angle) - z * std::sin(angle));
  vect.setZ(y * std::sin(angle) + z * std::cos(angle));
}

void raytracer::rotateY(raytracer::Vect3& vect, const float angle)
{
  float x = vect.getX();
  float z = vect.getZ();
  vect.setX(x * std::cos(angle)  + z * std::sin(angle));
  vect.setZ(-x * std::sin(angle) + z * std::cos(angle));
}

void raytracer::rotateZ(raytracer::Vect3& vect, const float angle)
{
  float x = vect.getX();
  float y = vect.getY();
  vect.setX(x * std::cos(angle) - y * std::sin(angle));
  vect.setY(x * std::sin(angle) + y * std::cos(angle));
}

raytracer::Vect3 raytracer::applyAngle(raytracer::Vect3& vect,
                                       const raytracer::Vect3& angles)
{
  raytracer::rotateX(vect, angles.getX());
  raytracer::rotateY(vect, angles.getY());
  raytracer::rotateZ(vect, angles.getZ());
  return vect;
}

raytracer::Vect3 raytracer::vectorFromAngles(const raytracer::Vect3& angles)
{
  raytracer::Vect3 baseVect = raytracer::Vect3(1, 0, 0);
  raytracer::applyAngle(baseVect, angles);
  return baseVect;
}

raytracer::Vect3 raytracer::getAngles(const raytracer::Vect3& v1,
                                      const raytracer::Vect3& v2)
{
  // Vector without the X, Y and Z axis
  raytracer::Vect2 v1XAxe = raytracer::Vect2(v1.getY(), v1.getZ());
  raytracer::Vect2 v2XAxe = raytracer::Vect2(v2.getY(), v2.getZ());

  raytracer::Vect2 v1YAxe = raytracer::Vect2(v1.getX(), v1.getZ());
  raytracer::Vect2 v2YAxe = raytracer::Vect2(v2.getX(), v2.getZ());

  raytracer::Vect2 v1ZAxe = raytracer::Vect2(v1.getX(), v1.getY());
  raytracer::Vect2 v2ZAxe = raytracer::Vect2(v2.getX(), v2.getY());

  // Angles between the two vectors for each axis
  float xAngle = 0.0f;
  if (!v1XAxe.isNullVect() && !v2XAxe.isNullVect())
    std::acos(v1XAxe.dot(v2XAxe) / (v1XAxe.getNorm() * v2XAxe.getNorm()));

  float yAngle = 0.0f;
  if (!v1YAxe.isNullVect() && !v2YAxe.isNullVect())
    std::acos(v1YAxe.dot(v2YAxe) / (v1YAxe.getNorm() * v2YAxe.getNorm()));

  float zAngle = 0.0f;
  if (!v1ZAxe.isNullVect() && !v2ZAxe.isNullVect())
    std::acos(v1ZAxe.dot(v2ZAxe) / (v1ZAxe.getNorm() * v2ZAxe.getNorm()));

  return raytracer::Vect3(xAngle, yAngle, zAngle);
}

raytracer::Vect3
raytracer::vectorFromPoints(const raytracer::Vect3& v1,
                            const raytracer::Vect3& v2)
{
  return raytracer::Vect3(v2.getX() - v1.getX(),
                          v2.getY() - v1.getY(),
                          v2.getZ() - v1.getZ());
}

std::vector<raytracer::Ray>
raytracer::genRays(const raytracer::Camera& cam,
                   const raytracer::Screen& screen)
{
  Vect3 topLeftPos = screen.getCenter()
        - (screen.getI() * ((screen.getWidth() / 2)) * screen.getPixelSize())
        + (screen.getJ() * ((screen.getHeight() / 2)) * screen.getPixelSize());

  auto res = std::vector<raytracer::Ray>();

  for (float j = 0.0f; j < screen.getHeight(); j += 1.0f)
  {
    for (float i = 0.0f; i < screen.getWidth(); i += 1.0f)
    {
      auto point = topLeftPos + i * (screen.getI() * screen.getPixelSize())
                              - j * (screen.getJ() * screen.getPixelSize());
      auto vect = raytracer::vectorFromPoints(cam.getPos(), point);
      res.push_back(raytracer::Ray(cam.getPos(), vect));
    }
  }
  return res;
}

int raytracer::closerToOrigin(raytracer::Vect3 origin,
                              raytracer::Vect3 point1,
                              raytracer::Vect3 point2)
{
  raytracer::Vect3 v1 = raytracer::vectorFromPoints(origin, point1);
  raytracer::Vect3 v2 = raytracer::vectorFromPoints(origin, point2);
  if (v1.getNorm() > v2.getNorm())
    return 2;
  return 1;
}

std::vector<raytracer::Color>
raytracer::renderFrame(const std::vector<gameobj::Shapable*>& objects,
                       const std::vector<raytracer::Ray>& rays,
                       const std::vector<gameobj::Lightable*>& lightList)
{
  auto res = std::vector<raytracer::Color>();
  for (auto r : rays)
  {
    auto rayOrigin = r.getOrigin();
    std::optional<std::tuple<raytracer::Vect3,
                             raytracer::Vect2,
                             gameobj::FlatShapable*>> closer
      = std::nullopt;
    for (auto o : objects)
    {
      std::optional<std::tuple<raytracer::Vect3,
                               raytracer::Vect2,
                               gameobj::FlatShapable*>> inter
        = o->intersecte(r);
      if (inter.has_value())
      {
        if (closer.has_value())
        {
          auto closerVal = std::get<0>(closer.value());
          auto interVal = std::get<0>(inter.value());
          if (closerToOrigin(rayOrigin, closerVal, interVal) == 2)
            closer = std::optional<std::tuple<raytracer::Vect3,
                                              raytracer::Vect2,
                                              gameobj::FlatShapable*>>
                      (inter.value());
        }
        else
          closer = std::optional<std::tuple<raytracer::Vect3,
                                            raytracer::Vect2,
                                            gameobj::FlatShapable*>>
                      (inter.value());
      }
    }

    if (closer.has_value())
    {
      auto resl = std::get<2>(closer.value())->getColor();
      auto intencity = raytracer::Color(0, 0, 0);
      for (auto l : lightList)
        intencity += l->interact(objects,
                                 std::get<0>(closer.value()),
                                 *std::get<2>(closer.value()));
      intencity.normalize();
      res.push_back(resl * intencity);
    }
    else
      res.push_back(raytracer::Color(0, 0, 0));

  }
  return res;
}
