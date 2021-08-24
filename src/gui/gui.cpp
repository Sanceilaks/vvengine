//
// Created by Admin on 24.07.2021.
//

#include "gui.h"

#include <spdlog/spdlog.h>

#include "../app.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

gui::c_gui::c_gui() {
    spdlog::info("Initializing gui");
    this->notify("initialization", 0);

    app().add_listener("initialization", "gui_initialization", [](const std::any& data){
        ImGui::CreateContext();
    	
        ImGui_ImplGlfw_InitForOpenGL(window()->get_software_window(), false);
        ImGui_ImplOpenGL3_Init();
    });

    app().add_listener("think", "gui_think", [this](const std::any& data) {
        this->new_frame();
    });

    render()->add_listener("final_render", "gui_final_render", [this](const std::any& data) {
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    });
}

gui::c_gui::~c_gui() {
    this->notify("shutdown", 0);

    ImGui_ImplGlfw_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();
}

void gui::c_gui::new_frame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("SSS");

    ImGui::End();

    this->notify("new_frame", 0);

    ImGui::Render();
}