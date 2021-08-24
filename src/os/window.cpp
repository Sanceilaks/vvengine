//
// Created by Admin on 22.07.2021.
//

#include "window.h"
#include "../app.h"
#include <spdlog/spdlog.h>

#define cast_to_window(ptr) reinterpret_cast<os::c_window*>(ptr)
#define get_window_ptr(win) cast_to_window(glfwGetWindowUserPointer(win))

namespace callbacks {

}

os::c_window::c_window(const std::string &title, const ImVec2 &size, const ImVec2 &position) {
    spdlog::trace("Initializing window: {}", title);
    software_window = glfwCreateWindow((int)size.x, (int)size.y, title.c_str(), nullptr, nullptr);
    if (!software_window) {
        spdlog::critical("Cannot initialize window {}", title);
        throw std::runtime_error("Window cannot be initalized");
    }
    glfwSetWindowUserPointer(software_window, this);

    this->title = title;

    //initialize callbacks
    app().add_listener("frame_end", "window_swap_buffers", [&](const std::any& data){
        this->swap_buffer();
    });
    app().add_listener("context_initialization", "window_on_context_created", [this](const std::any& data){
        this->set_context_current();
        glfwSwapInterval(1);
    });
}

os::c_window::~c_window() {
    glfwDestroyWindow(software_window);
    software_window = nullptr;
}

ImVec2 os::c_window::get_size() {
    int x, y;
    glfwGetWindowSize(software_window, &x, &y);
    return ImVec2(x, y);
}

ImVec2 os::c_window::get_pos() {
    int x, y;
    glfwGetWindowPos(software_window, &x, &y);
    return ImVec2(x, y);
}

std::string os::c_window::get_title() {
    return title;
}

void os::c_window::set_context_current() {
    glfwMakeContextCurrent(software_window);
}

bool os::c_window::should_close() {
    return glfwWindowShouldClose(software_window);
}

void os::c_window::swap_buffer() {
    glfwSwapBuffers(software_window);
}

void os::c_window::set_title(const std::string &title) {
    glfwSetWindowTitle(software_window, title.c_str());
    this->title = title;
}

void os::c_window::resizable(bool state) {
    glfwSetWindowAttrib(software_window, GLFW_RESIZABLE, state);
}

bool os::c_window::is_resizable() {
    return static_cast<bool>(glfwGetWindowAttrib(software_window, GLFW_RESIZABLE));
}
