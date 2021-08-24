cmake_minimum_required(VERSION 3.20)
project(vvengine)

#globals
set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_STATIC_LIBS ON)

#packages
find_package(spdlog CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

#creating executable
file(GLOB_RECURSE MAIN_FILES "src/*.cpp" "src/*.h" "src/*.hpp")
add_executable(vvengine ${MAIN_FILES})

#library`s
target_include_directories(vvengine PRIVATE ${SIGSLOT_INCLUDE_DIRS})

#linking
target_link_libraries(vvengine PRIVATE spdlog::spdlog_header_only glfw GLEW::GLEW opengl32)

#output
set_target_properties(vvengine PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/current")
if (CMAKE_BUILD_TYPE MATCHES Release)
    set_target_properties(vvengine PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/publish")
endif ()