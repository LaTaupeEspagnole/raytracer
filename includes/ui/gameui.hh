#pragma once

/**
 * \file
 * \brief Vect2 and Vect3 class managing vector operation
 */

#include "fwd.hh"

#include "color.hh"

#include <SDL2/SDL.h>

#include <vector>
#include <string>

namespace gameui
{
  /**
   * \brief Posible parameters for a window
   */
  enum WINDOWPARAM
  {
    NO_FULLSCREEN = 0, /*!< Size the window to a fixed resolution */
    FULLSCREEN = 1, /*!< Size the window fullscreen but don't change resolution */
    FULLSCREEN_DESKTOP = 2, /*!< Size the window fullscreen and change resolution to sceen resolution */
    BORDERLESS = 4 /*!< Make a borderless window */
  };

  /**
   * \brief Class to interacte with the user visual output
   */
  class UIScreen
  {
  public:
    /**
   * \brief Constructor of the object
   * \param pageTitle Title of the page
   * \param width width of the window
   * \param height height of the window
   * \param windowParam Parameter of the window
   * 
   * The windowParam parameter has to be filled using the WINDOWPARAM enum.
   */
    UIScreen(std::string pageTitle,
             unsigned width,
             unsigned height,
             uint32_t windowParam);

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