#pragma once

/*
// belonged to amaneshi hpp
#include <Game_World.hpp>
#include <Window.hpp>

namespace amaneshi
{
    namespace engine
    {       
        graphics::WindowStruct MainWindow;
        game::World * MainWorld;

        void Initialize() 
        {
            window::StartGLFW();

            MainWindow.width = 1280;
            MainWindow.height = 800;
            MainWindow.title = "hello amaneshi";
            MainWindow.fullscreen = false;
            graphics::InitializeWindow(MainWindow);
        }

        void CreateWorld() {

        }

        void MainThreadUpdate()
        {
            graphics::UpdateWindow();
            input::PollInput();

            // thread::Sync();
            // time::FPS();
        }
    }
}
*/


/*
// belonged to engine 3d hpp

#include <Graphics_Window.hpp>
namespace amaneshi
{
    namespace engine
    {
        graphics::WindowStruct Window;

        void Initialize() 
        {
            Window.width = 1280;
            Window.height = 800;
            Window.title = "hello amaneshi";
            Window.fullscreen = false;
            graphics::InitializeWindow(Window);

            // shaders are already built into code
            // but could already split task to read shader files

            // establish a base game world perhaps?

            // menu stuff
        }

    }
}

*/