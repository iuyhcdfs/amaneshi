#include <Amaneshi/Engine_3D.hpp>
#include <Choose_Game.h>
#ifdef NOT_AIR_HOCKEY

int main() {
	
	amaneshi::engine::Initalize();
	
	// setup buttom callbacks:
	// move camera
	// spawn sphere with random velocity
	
	// setup game world
	// containing box with collider walls

	while (1)
	{
		amaneshi::engine::MainThreadUpdate();
	}

}


#endif // NOT_AIR_HOCKEY
