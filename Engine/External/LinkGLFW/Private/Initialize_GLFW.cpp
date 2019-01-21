#include <External_Libraries.hpp>
#include <iostream>
namespace amaneshi
{
    namespace glfw
    {
        bool GLFWActivated = false;
        static void InitializeWindow(const amaneshi::graphics::WindowStruct &window);
        
        bool TryInitializeGLFW(){
            if(GLFWActivated) {
                return true;
            } else {
                if (!glfwInit())
                {
                    std::cerr << "ERROR: glfwInit failed" << std::endl;
                    return;
                } else {
                    std::cout << "GLFW Initalized" << std::endl;
                }
            }
        }
        // the window's characteristics can be changed later
        static void InitializeWindow(const amaneshi::graphics::WindowStruct &window) {
            if(Window) 
            {
                return;
            }

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            
            Window = glfwCreateWindow(window.width, window.height, window.title.c_str(), NULL, NULL);
            if (!Window) 
            {
                std::cerr << "ERROR: could not open window with GLFW3" << std::endl;
                glfwTerminate();
                return;
            }
            glfwMakeContextCurrent(Window);

            SetAmaneshiInput();

            glewExperimental = GL_TRUE;
            GLenum err = glewInit();
            if (GLEW_OK != err) 
            {
                std::cerr << "ERROR: could not initalise GLEW" << std::endl;
                glfwTerminate();
                return;
            }

            PrintOpenGLVersion();

            // tell GL to only draw onto a pixel if the shape is closer to the viewer
            glEnable(GL_DEPTH_TEST); // enable depth-testing
            glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"

        }
    }
}