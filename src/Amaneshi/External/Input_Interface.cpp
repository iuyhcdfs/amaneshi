#include <vector>
#include <iostream>
#include "Input_Interface.hpp"
#include "Setup_GLFW.hpp"
namespace amaneshi
{
	namespace input
	{
		std::string Library;
		MouseStruct Mouse;
		static std::vector<Buffer> KeyBuffer(KeyEnumSize);
		static std::vector<std::function<void(void)>> KeyCallback(KeyEnumSize); //= std::vector<std::function<void(void)>>(KeyEnumSize);
		static std::vector<std::function<void(void)>> KeyReleaseCallback(KeyEnumSize);

		void PollInput()
		{
			if (Library == "glfw")
			{
				glfwPollEvents();
			}
		}
		void UpdateKeyState(Key key, bool state)
		{
			if (state == true)
			{
				//std::cout << key << " pressed" << std::endl;
				KeyBuffer[key].Current = true;
				if (KeyCallback[key])
				{
					KeyCallback[key];
				}
			}
			else if (state == false)
			{
				//std::cout << key << " released" << std::endl;
				KeyBuffer[key].Current = false;
				if (KeyReleaseCallback[key])
				{
					KeyReleaseCallback[key];
				}
			}
		}

		bool IsKeyOn(Key key)
		{
			return KeyBuffer[key].Current;
		}

		bool HasKeySwitched(Key key)
		{
			return false; //KeyBuffer[key].Switched;
		}

	}
}