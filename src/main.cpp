#include <iostream>

#include "app.h"

int main() {
    try {
        c_app::instance().initialize();
        c_app::instance().run();
    } catch (std::exception& e) {
        spdlog::critical("Program error: {}", e.what());
        exit(-1);
    }
}
