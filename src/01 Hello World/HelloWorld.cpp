#include <iostream>
#include <Amaneshi/Engine_Temp.hpp>

#include <Choose_Game.h>

#ifdef HELLO_WORLD

#include <iostream>
int main() 
{
	// this isn't how you use the engine this is just testing components
	amaneshi::TempSetup();
	while (true) 
	{
		amaneshi::TempUpdate();
	}
}
#endif
