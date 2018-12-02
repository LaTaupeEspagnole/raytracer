#include "gameui.hh"

gameui::UIScreen::UIScreen(std::string pageTitle,
                 unsigned width,
                 unsigned height,
                 unsigned screenState)
{
  this->width = width;
  this->height = height;
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    // FIXME : ERROR HANDELING
    return;
  }
  else
  {
    Uint32 flags = SDL_WINDOW_SHOWN;
    if (screenState == 1)
      flags = flags | SDL_WINDOW_FULLSCREEN;
    else if (screenState == 2)
      flags = flags | SDL_WINDOW_FULLSCREEN_DESKTOP;

    this->window = SDL_CreateWindow(pageTitle.c_str(),
                                     SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED,
                                     width,
                                     height,
                                     flags);
    this->screenSurface = NULL;//SDL_GetWindowSurface(this->window);
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
  }
}

gameui::UIScreen::~UIScreen()
{
  SDL_FreeSurface(this->screenSurface);
  SDL_DestroyWindow(this->window);
  SDL_Quit();
}

void gameui::UIScreen::updateScreen()
{
  SDL_RenderPresent(this->renderer);
  SDL_UpdateWindowSurface(this->window);
}

void gameui::UIScreen::loadFrame(std::vector<raytracer::Color>* pixels)
{
  auto texture = SDL_CreateTexture(this->renderer,
                                     SDL_GetWindowSurface(this->window)->format->format,
                                     SDL_TEXTUREACCESS_STATIC,
                                     this->width,
                                     this->height);
  Uint32* pixelsTab = new Uint32[this->width * this->height];
  for (unsigned i = 0; i < this->width * this->height; i++)
  {
    pixelsTab[i] = SDL_MapRGB(SDL_GetWindowSurface(this->window)->format,
                                  (Uint8)((*pixels)[i].getR() * 255),
                                  (Uint8)((*pixels)[i].getG() * 255),
                                  (Uint8)((*pixels)[i].getB() * 255));
  }
  SDL_UpdateTexture(texture, NULL, pixelsTab, this->width * sizeof(Uint32));
  SDL_RenderClear(this->renderer);
  SDL_RenderCopy(this->renderer, texture, NULL, NULL);
  SDL_RenderPresent(this->renderer);
}