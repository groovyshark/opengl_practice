#include "Rectangle.hpp"

Rectangle::Rectangle() {
    float vertices[] = {
        // позиции      // цвета
         0.5f,  0.5f,   1.0f, 0.0f, 0.0f, // верхний правый (красный)
         0.5f, -0.5f,   0.0f, 1.0f, 0.0f, // нижний правый (зелёный)
        -0.5f, -0.5f,   0.0f, 0.0f, 1.0f, // нижний левый (синий)
        -0.5f,  0.5f,   1.0f, 1.0f, 0.0f  // верхний левый (жёлтый)
    };

    unsigned int indices[] = {
        0, 1, 3,  // первый треугольник
        1, 2, 3   // второй треугольник
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    // VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Позиции
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Цвета
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

Rectangle::~Rectangle() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Rectangle::draw() const {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}