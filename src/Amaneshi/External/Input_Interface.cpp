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
		std::vector<Buffer> KeyBuffer;
		std::vector<std::function<void(void)>> KeyCallback(KeyEnumSize); //= std::vector<std::function<void(void)>>(KeyEnumSize);
		std::vector<std::function<void(void)>> KeyReleaseCallback(KeyEnumSize);

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
				KeyBuffer[key].Current = true;
				if (KeyCallback[key])
				{
					KeyCallback[key];
				}
			}
			else if (state == false)
			{
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