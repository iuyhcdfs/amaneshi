#pragma once

// reaching out to opengl via a single thread

namespace amaneshi
{
	namespace thread
	{
		// CULLING should occur in camera/world. 

		// just a special dedicated producer consumer queue+thread
		// waits on physics round, cv is simplest
	}
}