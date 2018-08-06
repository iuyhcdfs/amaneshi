#pragma once
#include <iostream>
#include <GLFW/glfw3.h>

// im depreciated. 

// i need to be in.. utility? ooh how about debug or testing

namespace amaneshi {

	/*
	* brainstorm
	* updating
	* time and state
	* active/inactive game object (bookkeeping?)
	* save/load
	*
	*/

	class Updatable {
	public:
		Updatable() {}
		void update() {}
	};

	class FpsCounter : public Updatable {

	public:
		float frameCounter;
		double lastSecond;
		FpsCounter() {
			frameCounter = 0;
			lastSecond = 0;
		}
		void Update() {
			frameCounter++;
			// XXX not expecting game freeze past 1 second
			if (glfwGetTime() > lastSecond + 1) {
				lastSecond++;
				std::cout << "FPS: " << frameCounter << std::endl;
				frameCounter = 0;
			}
		}

	};

} // namespace amaneshi