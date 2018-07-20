#include "Graphics_Interface.hpp"
#include <string>
namespace amaneshi {
	namespace graphics {
		WindowStruct Window;
		std::string Framework;
		void(*Initialize) (WindowStruct windowParams);
		void(*Terminate) ();
	}
}