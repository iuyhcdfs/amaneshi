#pragma once

namespace amaneshi
{
	namespace time
	{
		float TargetFps;
		
		// fps: just check the clock alot right?
		// last time vs now, do math and display fps
		
		// old fpscounter
		//class FpsCounter {
		//public:
		//	float frameCounter;
		//	double lastSecond;
		//	FpsCounter() {
		//		frameCounter = 0;
		//		lastSecond = 0;
		//	}
		//	void Update() {
		//		frameCounter++;
		//		// XXX not expecting game freeze past 1 second
		//		if (glfwGetTime() > lastSecond + 1) {
		//			lastSecond++;
		//			std::cout << "FPS: " << frameCounter << std::endl;
		//			frameCounter = 0;
		//		}
		//	}

		//};


		// LIMITING fps: kind of want to make frames tick consistently
		// not have hyperfast computer churn 60 frames suddenly
		// only to freeze for most of a second
	}
}