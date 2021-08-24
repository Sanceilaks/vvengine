#pragma once

#include "gl.hpp"

#include <stdexcept>

class c_glew {
public:
    c_glew() {
        glewExperimental = true;
        if (glewInit() != GLEW_OK) throw std::runtime_error("Failed to initialize glew");
    }
};