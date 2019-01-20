#include <Config_Core.hpp>
namespace amaneshi
{
    namespace glfw
    {
        bool Activated = false;
        void Activate(){
            if(Activated) {
                return;
            } else {

            }
        }
    }

    namespace external
    {
        #ifdef WINDOW_GLFW
        void InitializeWindow(){
            glfw::Activate();

        }
        #endif

        #ifdef INPUT_GLFW
        void InitializeInput(){
            glfw::Activate();
            
        }
        #endif
    }

}