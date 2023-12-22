cmake_minimum_required(VERSION 3.0.0)
project(vulkan_test VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(vulkan_test main.cpp)

include_directories(
    /opt/homebrew/Cellar/glfw/3.3.9/include
    /opt/homebrew/Cellar/glm/0.9.9.8/include
    /Users/kristrev/VulkanSDK/1.3.268.1/macOS/include
)

# find_library + PATHS seems to be the recomended way of finding the path of a library, rather than using something
# like link_directories + name
find_library(GLFW_LIB glfw PATHS /opt/homebrew/Cellar/glfw/3.3.9/lib)
find_library(VULKAN_LIB vulkan PATHS /Users/kristrev/VulkanSDK/1.3.268.1/macOS/lib)

target_link_libraries(vulkan_test ${GLFW_LIB})
target_link_libraries(vulkan_test ${VULKAN_LIB})

set(ENV{VK_ICD_FILENAMES} /Users/kristrev/VulkanSDK/1.3.268.1/macOS/share/vulkan/icd.d/MoltenVK_icd.json)
set(ENV{VK_LAYER_PATH} /Users/kristrev/VulkanSDK/1.3.268.1/macOS/share/vulkan/explicit_layer.d)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
