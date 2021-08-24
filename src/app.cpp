//
// Created by Admin on 22.07.2021.
//

#include <iostream>
#include "app.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#define WINDOW_SIZE ImVec2(900, 500)
#define WINDOW_POSITION ImVec2(100, 100)

c_app* c_app::instance_ = nullptr;

void c_app::initialize() {
    logger = spdlog::stdout_color_mt("vluastudio");
    spdlog::set_default_logger(logger);

    spdlog::info("Initializing app");

    render = std::make_shared<render::c_render>();
    window = std::make_shared<os::c_window>(this->app_name, WINDOW_SIZE, WINDOW_POSITION);
    input_system = std::make_shared<input_system::c_input_system>();
    gui = std::make_shared<gui::c_gui>();
	
    spdlog::info("App was initialized!");
}

void c_app::shutdown() {
    this->notify("program_exit", 0);
    delete c_app::instance_; //delete main instance and call deconstructors of all
}

void c_app::run() {
    this->notify("context_initialization", 0);
    this->notify("initialization", 0);

    while (!window->should_close()) {
        this->notify("frame_start", 0);
        this->notify("think", 0);
        this->notify("frame_end", 0);
    }

    return shutdown();
}
