#pragma once

class Triangle {
public:
    Triangle();
    ~Triangle();

    void draw() const; 

private:
    unsigned int VAO, VBO;
};