//
// Created by Admin on 22.07.2021.
//

#ifndef VLUASTUDIO_C_WINDOW_H
#define VLUASTUDIO_C_WINDOW_H

#include <string>
#include <memory>

#include "../render/gl.hpp"

#include "../gui/imgui/imgui.h"
#include "../observer.h"

//TODO: IMPL THIS
namespace os {
    class c_window : public observer::i_observer{
        GLFWwindow* software_window;

        std::string title;
    public:
        c_window(const std::string& title, const ImVec2& size, const ImVec2& position);
        ~c_window();

        ImVec2 get_size();
        ImVec2 get_pos();
        std::string get_title();
        void set_title(const std::string& title);
        void set_context_current();
        bool should_close();
        void swap_buffer();
        void resizable(bool state);
        bool is_resizable();

        auto get_software_window() { return software_window; }
    };

    struct window_resize_event_data {
        c_window* window;
        const int x, y;
    };

}

#endif //VLUASTUDIO_C_WINDOW_H
