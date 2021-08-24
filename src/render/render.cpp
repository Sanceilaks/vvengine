//
// Created by Admin on 24.07.2021.
//

#include "render.h"

#include <spdlog/spdlog.h>

#include "../app.h"

void error_callback(int code, const char * desc)  {
    spdlog::error("GLEW Error {}:{}", code, desc);
}

render::c_render::c_render() {
    spdlog::info("Initializing render");
    try {
        glfw = std::make_shared<c_glfw>();
    } catch (const std::runtime_error& e) {
        spdlog::critical("Failed to initialize render with error: {}", e.what());
        throw std::runtime_error("Render initialization is failed");
    }
    glfwSetErrorCallback(error_callback);

    //setup callbacks
    app().add_listener("initialization", "render_initialization", [this](const std::any& data) {
        this->initialize_glew();
    });

    app().add_listener("frame_end", "render_frame_end", [this](const std::any& data){
        int display_w, display_h;
        glfwGetFramebufferSize(window()->get_software_window(), &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(1.f, 1.f, 1.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        this->notify("final_render", 0);
    });
}

void render::c_render::initialize_glew() {
    glew = std::make_shared<c_glew>();
}

