#pragma once

namespace amaneshi
{
    namespace glfw
    {
        GLFWwindow * GetWindowPointer();
        bool TryInitializeGLFW();
        void UpdateWindow();
        void PollInput();
    }
}