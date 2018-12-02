#pragma once

#include "fwd.hh"

#include "color.hh"

#include <SDL2/SDL.h>

#include <vector>
#include <string>

namespace gameui
{
  class UIScreen
  {
  public:
    UIScreen(std::string pageTitle,
             unsigned width,
             unsigned height,
             unsigned screenState);

    ~UIScreen();

    void updateScreen();
    void loadFrame(std::vector<raytracer::Color>* pixels);

  private:
    unsigned width;
    unsigned height;
    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_Renderer *renderer;
  };
}