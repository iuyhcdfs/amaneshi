#include <iostream>
#include <Amaneshi/Engine_Temp.hpp>

#include <iostream>
int main() 
{
	// render a static sphere.
	
	amaneshi::TempSetup();
	while (true) 
	{
		amaneshi::TempUpdate();
	}
}
