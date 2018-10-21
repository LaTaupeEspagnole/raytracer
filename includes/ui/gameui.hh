#pragma once

#include "fwd.hh"

#include <vector>

namespace gameui
{
    class UiScreen
    {
    public:
        UiScreen();

    private:
        std::vector<raytracer::Color>& sceneRender_;
    };
}