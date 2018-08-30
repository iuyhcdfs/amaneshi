
#include <iostream>
#include <string>

#include "Messy_GLFW.hpp"
#include "Graphics_Window.hpp"
#include "Input_Interface.hpp"

namespace amaneshi {
	
	namespace glfw {

		static GLFWwindow * Window;

		static void PrintOpenGLVersion();
		static void SetAmaneshiGraphics();
		static void SetAmaneshiInput();
		static void CallbackMouseButton(GLFWwindow* window, int button, int action, int mods);
		static void CallbackMousePosition(GLFWwindow* window, double xpos, double ypos);
		static void CallbackKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods);

		void StartGLFW()
		{
			if (!glfwInit())
			{
				std::cerr << "ERROR: glfwInit failed" << std::endl;
				return;
			}
			SetAmaneshiGraphics();
			std::cout << "GLFW Initialized for Graphics_Window" << std::endl;
			std::cout << "GLFW Initialized for Input_Interface" << std::endl;
		}

		void InitializeWindow(const amaneshi::graphics::WindowStruct &window) {
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

		void UpdateWindow()
		{
			glfwSwapBuffers(Window);
		}

		void PollInput()
		{
			glfwPollEvents();
		}

		static void PrintOpenGLVersion() 
		{
			const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
			const GLubyte* version = glGetString(GL_VERSION); // version as a string
			printf("Renderer: %s\n", renderer);
			printf("OpenGL version supported %s\n", version);
		}

		static void SetAmaneshiGraphics()
		{
			amaneshi::graphics::Library = "glfw";
		}
		static void SetAmaneshiInput()
		{
			amaneshi::input::Library = "glfw";
			glfwSetKeyCallback(Window, amaneshi::glfw::CallbackKeyboard);
			glfwSetMouseButtonCallback(Window, &amaneshi::glfw::CallbackMouseButton);
			glfwSetCursorPosCallback(Window, &amaneshi::glfw::CallbackMousePosition);
		}

		static void CallbackMouseButton(GLFWwindow* window, int button, int action, int mods)
		{
			amaneshi::input::KeyEnum amaneshiKey;
			{
				using namespace amaneshi::input;
				switch (button)
				{
				case GLFW_MOUSE_BUTTON_1: amaneshiKey = Mouse0; break;
				case GLFW_MOUSE_BUTTON_2: amaneshiKey = Mouse1; break;
				case GLFW_MOUSE_BUTTON_3: amaneshiKey = Mouse2; break;
				default: amaneshiKey = Invalid; break;
				}
			}
			if (amaneshiKey != amaneshi::input::Invalid)
			{
				if (action == GLFW_PRESS)
				{
					amaneshi::input::UpdateKeyState(amaneshiKey, true);
				}
				else if (action == GLFW_RELEASE)
				{
					amaneshi::input::UpdateKeyState(amaneshiKey, false);
				}
			}
		}

		static void CallbackMousePosition(GLFWwindow* window, double xpos, double ypos)
		{
			amaneshi::input::Mouse.x = xpos;
			amaneshi::input::Mouse.y = ypos;
		}

		static void CallbackKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			amaneshi::input::KeyEnum amaneshiKey;
			{
				using namespace amaneshi::input;
				switch (key)
				{
				case GLFW_KEY_0: amaneshiKey = Num0; break;
				case GLFW_KEY_1: amaneshiKey = Num1; break;
				case GLFW_KEY_2: amaneshiKey = Num2; break;
				case GLFW_KEY_3: amaneshiKey = Num3; break;
				case GLFW_KEY_4: amaneshiKey = Num4; break;
				case GLFW_KEY_5: amaneshiKey = Num5; break;
				case GLFW_KEY_6: amaneshiKey = Num6; break;
				case GLFW_KEY_7: amaneshiKey = Num7; break;
				case GLFW_KEY_8: amaneshiKey = Num8; break;
				case GLFW_KEY_9: amaneshiKey = Num9; break;
				case GLFW_KEY_A: amaneshiKey = A; break;
				case GLFW_KEY_B: amaneshiKey = B; break;
				case GLFW_KEY_C: amaneshiKey = C; break;
				case GLFW_KEY_D: amaneshiKey = D; break;
				case GLFW_KEY_E: amaneshiKey = E; break;
				case GLFW_KEY_F: amaneshiKey = F; break;
				case GLFW_KEY_G: amaneshiKey = G; break;
				case GLFW_KEY_H: amaneshiKey = H; break;
				case GLFW_KEY_I: amaneshiKey = I; break;
				case GLFW_KEY_J: amaneshiKey = J; break;
				case GLFW_KEY_K: amaneshiKey = K; break;
				case GLFW_KEY_L: amaneshiKey = L; break;
				case GLFW_KEY_M: amaneshiKey = M; break;
				case GLFW_KEY_N: amaneshiKey = N; break;
				case GLFW_KEY_O: amaneshiKey = O; break;
				case GLFW_KEY_P: amaneshiKey = P; break;
				case GLFW_KEY_Q: amaneshiKey = Q; break;
				case GLFW_KEY_R: amaneshiKey = R; break;
				case GLFW_KEY_S: amaneshiKey = S; break;
				case GLFW_KEY_T: amaneshiKey = T; break;
				case GLFW_KEY_U: amaneshiKey = U; break;
				case GLFW_KEY_V: amaneshiKey = V; break;
				case GLFW_KEY_W: amaneshiKey = W; break;
				case GLFW_KEY_X: amaneshiKey = X; break;
				case GLFW_KEY_Y: amaneshiKey = Y; break;
				case GLFW_KEY_Z: amaneshiKey = Z; break;
				case GLFW_KEY_F1: amaneshiKey = F1; break;
				case GLFW_KEY_F2: amaneshiKey = F2; break;
				case GLFW_KEY_F3: amaneshiKey = F3; break;
				case GLFW_KEY_F4: amaneshiKey = F4; break;
				case GLFW_KEY_F5: amaneshiKey = F5; break;
				case GLFW_KEY_F6: amaneshiKey = F6; break;
				case GLFW_KEY_F7: amaneshiKey = F7; break;
				case GLFW_KEY_F8: amaneshiKey = F8; break;
				case GLFW_KEY_F9: amaneshiKey = F9; break;
				case GLFW_KEY_F10: amaneshiKey = F10; break;
				case GLFW_KEY_F11: amaneshiKey = F11; break;
				case GLFW_KEY_F12: amaneshiKey = F12; break;
				case GLFW_KEY_ESCAPE: amaneshiKey = Esc; break;
				case GLFW_KEY_TAB: amaneshiKey = Tab; break;
				case GLFW_KEY_CAPS_LOCK: amaneshiKey = CapsLock; break;
				case GLFW_KEY_LEFT_SHIFT: case GLFW_KEY_RIGHT_SHIFT: amaneshiKey = Shift; break;
				case GLFW_KEY_LEFT_CONTROL:	amaneshiKey = CtrlL; break;
				case GLFW_KEY_RIGHT_CONTROL: amaneshiKey = CtrlR; break;
				case GLFW_KEY_LEFT_ALT: amaneshiKey = AltL; break;
				case GLFW_KEY_RIGHT_ALT: amaneshiKey = AltR; break;
				case GLFW_KEY_SPACE: amaneshiKey = Space; break;
				case GLFW_KEY_ENTER: amaneshiKey = Enter; break;
				case GLFW_KEY_BACKSPACE: amaneshiKey = Backspace; break;
				case GLFW_KEY_HOME: amaneshiKey = Home; break;
				case GLFW_KEY_END: amaneshiKey = End; break;
				case GLFW_KEY_INSERT: amaneshiKey = Insert; break;
				case GLFW_KEY_DELETE:  amaneshiKey = Delete; break;
				case GLFW_KEY_PAGE_UP: amaneshiKey = PageUp; break;
				case GLFW_KEY_PAGE_DOWN: amaneshiKey = PageDown; break;
				case GLFW_KEY_UP: amaneshiKey = Up; break;
				case GLFW_KEY_DOWN: amaneshiKey = Down; break;
				case GLFW_KEY_LEFT: amaneshiKey = Left; break;
				case GLFW_KEY_RIGHT: amaneshiKey = Right; break;
				default: amaneshiKey = Invalid; break;
				}
			}
			if (amaneshiKey != amaneshi::input::Invalid)
			{
				if (action == GLFW_PRESS)
				{
					amaneshi::input::UpdateKeyState(amaneshiKey, true);
				}
				else if (action == GLFW_RELEASE)
				{
					amaneshi::input::UpdateKeyState(amaneshiKey, false);
				}
			}
		}
	}
}
