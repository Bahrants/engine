
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

//the fucntion to the opengl
bool initialize() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return false;
    }

    //the window and opengl context
    GLFWwindow* window = glfwCreateWindow(800, 600, "My Game Engine", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return false;
    }

    // making the window context current
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);  // Enable vsync

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW!" << std::endl;
        return false;
    }

    return true;
}

// Basic game loop:c
void gameLoop(GLFWwindow* window) {
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Simple rendering logic
        glClearColor(0.0f, 0.5f, 0.8f, 1.0f); // Background color

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main() {
    if (!initialize()) {
        return -1;
    }

    GLFWwindow* window = glfwGetCurrentContext();
    gameLoop(window);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
