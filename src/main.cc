#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

#include <SDL2/SDL.h>

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
#include "lightable.hh"
#include "ambientlight.hh"
#include "dirlight.hh"
#include "gameui.hh"

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

int main(int argc, char *argv[])
{
  bool showWindow = false;
  bool writeFile = false;
  bool borderless = false;
  int indexArgv = 1;

  while (indexArgv < argc)
  {
    if (strcmp(argv[indexArgv], "--show-window") == 0)
      showWindow = true;
    else if (strcmp(argv[indexArgv], "--write-file") == 0)
      writeFile = true;
    else if (strcmp(argv[indexArgv], "--borderless") == 0)
      borderless = true;
    else
    {
      std::cout << "Usage: " << argv[0] << " [OPTIONS]" << std::endl;
      std::cout << "--show-window -> Show the graphicale window" << std::endl;
      std::cout << "--write-file  -> Show the graphicale window" << std::endl;
      std::cout << "--borderless  -> The graphical window will be borderless" << std::endl;
      return 1;
    }
    indexArgv++;
  }

  auto camPos = raytracer::Vect3(0, -10, 0);
  auto camAngle = raytracer::Vect3(0, raytracer::pi / 16, raytracer::pi / 8);
  float width = 1280;
  float height = 720;

  raytracer::Camera cam = raytracer::Camera(camPos,
                                            camAngle,
                                            raytracer::pi / 2);
  raytracer::Screen screen = raytracer::Screen(cam, width, height);

  auto objectList = std::vector<gameobj::Shapable*>();

  auto square1 = gameobj::Square(
                  raytracer::Vect3(0, 20, -10),
                  raytracer::Vect3(40, 20, -10),
                  raytracer::Vect3(0, -20, -10),
                  raytracer::Vect3(0, 0, 1),
                  raytracer::Color(1, 0, 0));

  auto cube1 = gameobj::Cube(raytracer::Vect3(30, 0, 0), 2,
                               raytracer::Vect3(0, raytracer::pi / 4, raytracer::pi / 4),
                               raytracer::Color(0, 0, 1));

  objectList.push_back(&square1);
  objectList.push_back(&cube1);

  auto lightList = std::vector<gameobj::Lightable*>();
  auto light1 = gameobj::PointLight(raytracer::Vect3(30, 5, 10),
                                      raytracer::Color(1, 1, 1),
                                      6);
  auto light2 = gameobj::AmbientLight(raytracer::Color(1, 1, 1), 0.4);

  auto light3 = gameobj::PointLight(raytracer::Vect3(25, 10, -9),
                                      raytracer::Color(1, 1, 1),
                                      1);
/*
  auto light4 = gameobj::DirectionalLight(-raytracer::Vect3(0, 0, 1),
                                            raytracer::Color(1, 1, 1),
                                            1);
*/
  lightList.push_back(&light1);
  lightList.push_back(&light2);
  lightList.push_back(&light3);
  //lightList.push_back(&light4);

  auto rayList = raytracer::genRays(cam, screen);

  auto pixels = raytracer::renderFrame(objectList, rayList, lightList);

  if (showWindow)
  {
    uint32_t flags = gameui::WINDOWPARAM::NO_FULLSCREEN;
    if (borderless)
      flags = flags | gameui::WINDOWPARAM::BORDERLESS;
    auto window = gameui::UIScreen("Raytracer Project",
                                   width,
                                   height,
                                   flags);
    window.loadFrame(&pixels);
    window.updateScreen();
    SDL_Delay(2000);
  }

  if (writeFile)
  {
    writeRender("test.ppm", pixels, width, height);
  }

  return 0;
}
