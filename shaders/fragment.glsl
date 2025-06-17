#version 330 core

in vec3 ourColor;

out vec4 FragColor;

uniform float time;

void main() {
    float pulse = abs(sin(time));
    FragColor = vec4(ourColor * pulse, 1.0);
}