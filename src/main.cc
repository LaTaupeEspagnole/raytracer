#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

#include "ray.hh"
#include "camera.hh"
#include "vect.hh"
#include "screen.hh"
#include "square.hh"
#include "utils.hh"
#include "cube.hh"
#include "color.hh"
#include "pointlight.hh"
#include "shapable.hh"

void writeRender(std::string filename,
                  std::vector<raytracer::Color>& pixels,
                  unsigned width,
                  unsigned height)
{
  std::ofstream ostrm(filename);
  ostrm << "P3\n" << std::to_string(width) << " " << std::to_string(height) << "\n255\n";

  for (unsigned h = 0; h < height; h++)
  {
    for (unsigned w = 0; w < width; w++)
    {
      auto v = pixels[w + width * h];
      ostrm << std::to_string(static_cast<int>(std::floor(v.getR() * 255.0f))) << " ";
      ostrm << std::to_string(static_cast<int>(std::floor(v.getG() * 255.0f))) << " ";
      ostrm << std::to_string(static_cast<int>(std::floor(v.getB() * 255.0f))) << " ";
    }
  }

  ostrm.close();
}

int main()
{
  auto camPos = raytracer::Vect3(0, 0, 0);
  auto camAngle = raytracer::Vect3(0, 0, 0);
  float width = 1280;
  float height = 720;

  raytracer::Camera cam = raytracer::Camera(camPos,
                                            camAngle,
                                            raytracer::pi / 2);
  raytracer::Screen screen = raytracer::Screen(cam, width, height);

  auto objectList = std::vector<raytracer::Shapable*>();

  auto square1 = raytracer::Square(
                  raytracer::Vect3(0, 20, -10),
                  raytracer::Vect3(40, 20, -10),
                  raytracer::Vect3(0, -20, -10),
                  raytracer::Vect3(0, 0, 1),
                  raytracer::Color(1, 0, 0));

  auto cube1 = raytracer::Cube(raytracer::Vect3(30, 0, 0), 2,
                               raytracer::Vect3(0, raytracer::pi / 4, raytracer::pi / 4),
                               raytracer::Color(0, 0, 1));

  objectList.push_back(&square1);
  objectList.push_back(&cube1);

  auto lightList = std::vector<raytracer::PointLight>();
  auto light1 = raytracer::PointLight(raytracer::Vect3(30, 5, 10),
                                      raytracer::Color(1, 1, 1));

  lightList.push_back(light1);

  auto rayList = raytracer::genRays(cam, screen);

  auto pixels = raytracer::renderFrame(objectList, rayList, lightList);

  writeRender("test.ppm", pixels, width, height);

  return 0;
}
