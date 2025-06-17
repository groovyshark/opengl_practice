#include <iostream>
#include <cmath>

#include "Application.hpp"

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

int main() {
    Application app(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL OOP");
    app.run();

    return 0;
}
