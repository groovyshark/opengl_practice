#include "Application.hpp"

#include <iostream>

#include "Shader.hpp"
#include "Triangle.hpp"

Application::Application(int width, int height, const std::string& title)
    : _window(nullptr), 
    _shader(nullptr), 
    _triangle(nullptr) 
{
    if (!initGLFW(width, height, title.c_str())) return;
    if (!initGLAD()) return;

    // создаём шейдер и треугольник
    _shader = std::make_unique<Shader>("../shaders/vertex.glsl", "../shaders/fragment.glsl");
    _triangle = std::make_unique<Triangle>();
}

Application::~Application() {
    glfwTerminate();
}

bool Application::initGLFW(int width, int height, const char* title) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = std::unique_ptr<GLFWwindow, GLFWWindowDeleter>(
        glfwCreateWindow(width, height, title, nullptr, nullptr)
    );
    if (!_window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(_window.get());
    glfwSetFramebufferSizeCallback(_window.get(), [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });
    return true;
}

bool Application::initGLAD() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return false;
    }
    return true;
}

void Application::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void Application::run() {
    while (!glfwWindowShouldClose(_window.get())) {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        _shader->use();
        _triangle->draw();

        glfwSwapBuffers(_window.get());
        glfwPollEvents();
    }
}