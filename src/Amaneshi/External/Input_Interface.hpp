#pragma once
#include <vector>
#include <string>
#include <functional>
namespace amaneshi 
{
	namespace input	
	{
		enum class Key {
			Mouse0, Mouse1, Mouse2,
			A, B, C, D, E, F, G, H, I, J, K, L, M,
			N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
			Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num0,
			Esc, Tab, CapsLock, Shift, CtrlL, CtrlR, AltL, AltR, Space,
			Enter, Backspace, Home, End, Insert, Delete, PageUp, PageDown,
			Up, Down, Left, Right,
			F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
		};

		struct MouseStruct
		{
			double x;
			double y;
		};
		extern MouseStruct Mouse;
		
		void AddKeyListener(Key key, std::function<void> callback);

		// detect key pressed, held, released?
		
	}
}

/*

in case you accidentally edit and too far to fix with git

enum class Key {
Mouse0, Mouse1, Mouse2,
A, B, C, D, E, F, G, H, I, J, K, L, M,
N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num0,
Esc, Tab, CapsLock, Shift, CtrlL, CtrlR, AltL, AltR, Space,
Enter, Backspace, Home, End, Insert, Delete, PageUp, PageDown,
Up, Down, Left, Right,
F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
};

*/