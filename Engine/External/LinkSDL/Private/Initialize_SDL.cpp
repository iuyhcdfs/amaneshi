#include <External_Libraries.hpp>

namespace amaneshi
{
    namespace sdl
    {
        bool SDLActivated = false;
        bool TryInitializeSDL(){
            if(SDLActivated) {
                return true;
            } else {
                /*
                if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
                {
                    std::cerr << "ERROR: SDL_init failed" << std::endl;
                    return false;
                } else {
                    SDLActivated = true;
                    // other config?
                }
                */
            }
        }
    }
}