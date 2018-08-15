#include <iostream>
#include <Amaneshi/Engine_Temp.hpp>

#include <Choose_Game.h>

#ifdef HELLO_WORLD
int main() 
{
	// use the engine *improperly* but at least make sure it's subsystems work.

	amaneshi::TempSetup();
	while (true) 
	{
		amaneshi::TempUpdate();
	}
}
#endif
