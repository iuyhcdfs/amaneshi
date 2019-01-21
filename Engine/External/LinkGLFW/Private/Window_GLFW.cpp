#include <External_GLFW.hpp>

namespace amaneshi
{
    namespace glfw
    {
        static GLFWwindow * Window;
        GLFWwindow * GetWindowPointer() {
            return Window;
        }
    }
}