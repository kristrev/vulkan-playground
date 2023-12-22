#ifndef HELLO_TRIANGLE_HPP
#define HELLO_TRIANGLE_HPP

#include <cstdint>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// Class containing the logic for the Vulkan Hello Triangle application
class HelloTriangle
{
public:
    HelloTriangle() = default;
    ~HelloTriangle() = default;

    // Called from main after object has been initialized, runs the event loop
    void run();

private:
    // Initialize the window we are going to use to display our fancy triangle
    void initWindow();

    // Initiates the various Vulkan objects
    void initVulkan();

    // Runs our event loop (iterate until window is closed)
    void mainLoop();

    // Deallocates the resources we have used
    void cleanup();

private:
    // Pointer to our window + context
    GLFWwindow *window;

private:
    static constexpr const uint16_t kDefWidth = 800;
    static constexpr const uint16_t kDefHeight = 600;
};

#endif