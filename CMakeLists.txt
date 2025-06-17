cmake_minimum_required(VERSION 3.10.0)
project(opengl_practice VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

# GLAD
include_directories(libs/glad/include)
set(GLAD_SRC libs/glad/src/glad.c)

# GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

# Sources
file(GLOB SRC_FILES src/*.cpp)
add_executable(OpenGLApp ${SRC_FILES} ${GLAD_SRC})

# Link libraries
target_include_directories(OpenGLApp PRIVATE ${GLFW_INCLUDE_DIRS})
target_link_libraries(OpenGLApp ${GLFW_LIBRARIES} dl)

