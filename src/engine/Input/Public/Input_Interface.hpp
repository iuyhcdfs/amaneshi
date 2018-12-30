#pragma once
#include <vector>
#include <string>
#include <functional>
namespace amaneshi 
{
	namespace input	
	{
		enum KeyEnum 
		{
			Mouse0, Mouse1, Mouse2,
			A, B, C, D, E, F, G, H, I, J, K, L, M,
			N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
			Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num0,
			Esc, Tab, CapsLock, Shift, CtrlL, CtrlR, AltL, AltR, Space,
			Enter, Backspace, Home, End, Insert, Delete, PageUp, PageDown,
			Up, Down, Left, Right,
			F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
			Invalid,

			KeyEnumSize // must be last
		};

		struct Buffer
		{
			bool Current;
			// bool Previous;
			// bool Switched;
		};

		struct MouseStruct
		{
			double x;
			double y;
			// double z;???!? just kidding
		};

		extern std::string Library;
		extern MouseStruct Mouse;

		// static in it's cpp file
		//extern std::vector<Buffer> KeyBuffer;
		//extern std::vector<std::function<void(void)>> KeyCallback;
		//extern std::vector<std::function<void(void)>> KeyReleaseCallback;

		void PollInput();
		void UpdateKeyState(KeyEnum key, bool state);
		bool IsKeyOn(KeyEnum key);
		bool HasKeySwitched(KeyEnum key);

		// void AddKeyListener(stuff, callback);
		//MouseStruct FpsMouseReset();

	}
}

/*

in case you accidentally edit and too far to fix with git
enum Key
{
Mouse0, Mouse1, Mouse2,
A, B, C, D, E, F, G, H, I, J, K, L, M,
N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num0,
Esc, Tab, CapsLock, Shift, CtrlL, CtrlR, AltL, AltR, Space,
Enter, Backspace, Home, End, Insert, Delete, PageUp, PageDown,
Up, Down, Left, Right,
F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
Invalid,

KeyEnumSize // must be last to represent the size
};

*/