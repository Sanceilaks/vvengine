//
// Created by Admin on 24.07.2021.
//

#include "input_system.h"

#include "../app.h"

#include "../gui/imgui/imgui_impl_glfw.h"

namespace callbacks {
    void cursor_enter_callback(GLFWwindow* window, int entered){

    }

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
    }

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
        ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
    }

    void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
        ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
    }

    void cursor_position_callback(GLFWwindow* window, double x_pos, double y_pos) {

    }

    void char_callback(GLFWwindow* window, unsigned int c) {
        ImGui_ImplGlfw_CharCallback(window, c);
    }
}

void input_system::c_input_system::pool_events() {
    glfwPollEvents();
}

input_system::c_input_system::c_input_system() {
    glfwSetCharCallback(window()->get_software_window(), callbacks::char_callback);
    glfwSetMouseButtonCallback(window()->get_software_window(), callbacks::mouse_button_callback);
    glfwSetKeyCallback(window()->get_software_window(), callbacks::key_callback);
    glfwSetScrollCallback(window()->get_software_window(), callbacks::scroll_callback);
    glfwSetCursorEnterCallback(window()->get_software_window(), callbacks::cursor_enter_callback);
    glfwSetCursorPosCallback(window()->get_software_window(), callbacks::cursor_position_callback);

    app().add_listener("frame_end", "input_system_pool_events", [this](const std::any& data) {
        this->pool_events();
    });
}

input_system::c_input_system::~c_input_system() {

}
