#ifndef HELLO_TRIANGLE_HPP
#define HELLO_TRIANGLE_HPP

// Class containing the logic for the Vulkan Hello Triangle application
class HelloTriangle
{
public:
    HelloTriangle() = default;
    ~HelloTriangle() = default;

    //Called from main after object has been initialized, runs the event loop
    void run();

private:
    //Initiates the various Vulkan objects
    void initVulkan();

    //Runs our event loop (iterate until window is closed)
    void mainLoop();

    //Deallocates the resources we have used
    void cleanup();
};

#endif