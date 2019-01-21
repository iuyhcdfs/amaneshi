
namespace amaneshi
{
    namespace glfw
    {
        void UpdateWindow()
        {
            glfwSwapBuffers(Window);
        }

        void PollInput()
        {
            glfwPollEvents();
        }
    }
}