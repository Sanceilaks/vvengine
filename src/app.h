//
// Created by Admin on 22.07.2021.
//

#ifndef VLUASTUDIO_APP_H
#define VLUASTUDIO_APP_H

#include <string>
#include "os/window.h"
#include "render/render.h"
#include "input_system/input_system.h"

#include "spdlog/spdlog.h"
#include "gui/gui.h"

#include <memory>

class c_app : public observer::i_observer {
    static c_app* instance_;
    c_app() {}

    const std::string app_name = "asd";
    const std::string app_version = "asd";

    std::shared_ptr<spdlog::logger> logger;
    std::shared_ptr<os::c_window> window;
    std::shared_ptr<render::c_render> render;
    std::shared_ptr<gui::c_gui> gui;
    std::shared_ptr<input_system::c_input_system> input_system;
public:
    static c_app& instance() { if (!c_app::instance_) c_app::instance_ = new c_app(); return *instance_; }

    void initialize();
    void shutdown();

    void run();

    auto get_window() const { return window.get(); }
    auto get_logger() const { return logger.get(); }
    auto get_render() const { return render.get(); }
    auto get_gui() const { return gui.get(); }
    auto get_input_system() const { return input_system.get(); }
};

#define app() c_app::instance()
#define input_system() app().get_input_system()
#define window() app().get_window()
#define render() app().get_render()
#define logger() app().get_logger()
#define gui() app().get_gui()

#endif //VLUASTUDIO_APP_H