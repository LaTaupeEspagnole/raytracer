#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

#include "camera.hh"
#include "vect.hh"
#include "screen.hh"
#include "square.hh"
#include "utils.hh"
#include "cube.hh"

void writeRender(std::string filename,
                  std::vector<raytracer::Vect3> pixels,
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
      ostrm << std::to_string(static_cast<int>(std::floor(v.getX() * 255.0f))) << " ";
      ostrm << std::to_string(static_cast<int>(std::floor(v.getY() * 255.0f))) << " ";
      ostrm << std::to_string(static_cast<int>(std::floor(v.getZ() * 255.0f))) << " ";
    }
  }

  ostrm.close();
}

int main()
{
  auto camPos = raytracer::Vect3(0, 0, 0);
  auto camAngle = raytracer::Vect3(0, 0, 0);
  float width = 720;
  float height = 480;

  raytracer::Camera cam = raytracer::Camera(camPos,
                                            camAngle,
                                            raytracer::pi / 2);
  raytracer::Screen screen = raytracer::Screen(cam, width, height);

  auto objectList = std::vector<raytracer::Shapable*>();

  auto square1 = raytracer::Square(
                  raytracer::Vect3(0, 20, -10),
                  raytracer::Vect3(40, 20, -10),
                  raytracer::Vect3(0, -20, -10),
                  raytracer::Vect3(0, 0, 1));

  objectList.push_back(&square1);

  auto cube1 = raytracer::Cube(raytracer::Vect3(5, 0, 0), 1,
                               raytracer::Vect3(0, raytracer::pi / 4, raytracer::pi / 4));
  objectList.push_back(&cube1);

  auto rayList = raytracer::genRays(cam, screen);

  auto pixels = raytracer::renderFrame(objectList, rayList);

  writeRender("test.ppm", pixels, width, height);

  return 0;
}
