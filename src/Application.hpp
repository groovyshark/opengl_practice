#pragma once

#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct GLFWWindowDeleter {
    void operator()(GLFWwindow* window) const {
        glfwDestroyWindow(window);
    }
};

class Shader;
class Triangle;

class Application {
public:
    Application(int width, int height, const std::string& title);
    ~Application();

    void run();

private:
    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
    bool initGLFW(int width, int height, const char* title);
    bool initGLAD();


private:
    std::unique_ptr<GLFWwindow, GLFWWindowDeleter> _window;
    std::unique_ptr<Shader> _shader;
    std::unique_ptr<Triangle> _triangle;
};