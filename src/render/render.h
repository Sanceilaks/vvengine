//
// Created by Admin on 24.07.2021.
//

#ifndef VLUASTUDIO_RENDER_H
#define VLUASTUDIO_RENDER_H

#include "glew.hpp"
#include "glfw.hpp"

#include <memory>
#include <utility>

#include "../os/window.h"

namespace render {
    class c_render : public observer::i_observer {
        std::shared_ptr<c_glew> glew;
        std::shared_ptr<c_glfw> glfw;

    public:
        c_render();

        //after context creation
        void initialize_glew();
    };
}

#endif //VLUASTUDIO_RENDER_H
