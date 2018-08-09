#include <iostream>
#include <Amaneshi/Engine_Temp.hpp>

#include <Choose_Game.h>

#ifdef HELLO_WORLD
int main() 
{
	amaneshi::TempSetup();
	while (true) 
	{
		amaneshi::TempUpdate();
	}
}
#endif
