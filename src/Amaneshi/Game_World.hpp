#pragma once

namespace amaneshi
{
	namespace game
	{
		// is one whole world one layer basically? it could be!

		// thats all you have to decide for now. will class world{} represent layers or not

		// otherwise you'll implement layers inside. the question is do you want to duplicate everything
		// well one world could operate or render differently to the other one right?

		// SUPER IMPORTANT
		// hypothetically for a network->server syncing mechanism
		// you better be grouping up all the code for calculating the game state
		// dont make it messy or ad-hoc
		
		// for such a networked game youll need prediction states
		// and then server updates

		class World
		{
			// also... a derivative of this should be able to play nicely with saves and networking

			// so whats the interface anyway
		};
	}
}