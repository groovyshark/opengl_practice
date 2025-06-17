#pragma once

#include <glad/glad.h>

class Rectangle {
public:
    Rectangle();
    ~Rectangle();
    
    void draw() const;

private:
    unsigned int VAO, VBO, EBO;
};