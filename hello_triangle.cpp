#include "hello_triangle.hpp"

void HelloTriangle::run()
{
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void HelloTriangle::initWindow()
{
    // GLFW is a library that takes care of the heavy lifting when it comes to creating a window, dealing with inputs,
    // etc., etc. There are other alternatives, like SDL2.
    glfwInit();

    // A GLFW window encapsulates both a window and a context (what we work on). When writing Vulkan, we need to tell
    // GLFW not to create an OpenGL context (default)
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    //Resizing requires some special handling and will be implemented later
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(kDefWidth, kDefHeight, "Kristian", nullptr, nullptr);
}

void HelloTriangle::initVulkan()
{
}

void HelloTriangle::mainLoop()
{
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void HelloTriangle::cleanup()
{
    //Destroy window + context
    glfwDestroyWindow(window);

    // Destory all remaining windows, free resources, etc., etc.
    glfwTerminate();
}