#pragma once

//#define GRAPHICS_?
#define GRAPHICS_OPENGL
//#define GRAPHICS_VULKAN

//#define WINDOW_?
#define WINDOW_GLFW
//#define INPUT_?
#define INPUT_GLFW

//#define AUDIO_?

//#define NETWORK_?

namespace amaneshi
{
    void Initialize()
    {
        #ifdef WINDOW_GLFW
        {
            
        }
        #endif

        #ifdef INPUT_GLFW
        {

        }
        #endif

        #ifdef GRAPHICS_OPENGL
        {
            
        }
        #endif

    }
}