//
// Created by Admin on 24.07.2021.
//

#ifndef VLUASTUDIO_GLFW_H
#define VLUASTUDIO_GLFW_H

#include "gl.hpp"
#include <stdexcept>

class c_glfw {
public:
    c_glfw() {
        if (!glfwInit()) throw std::runtime_error("Failed to initialize glfw!");
    }
};

#endif //VLUASTUDIO_GLFW_H
