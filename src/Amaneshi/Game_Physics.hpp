#pragma once

namespace amaneshi
{
	namespace game
	{
		// define physics component

		// whatever is common between all of them

		// how much of the "world" is handled here and how much is handled in Game_World?
		// game world probably more a proper container of everything, also allows culling to make nicer calcs

		// things arent dependent on the "world" code
		// everything just has coordinates. its math.
		// the world code is just to organise it
		// but the only way we'll know if we hit something else is by looking at the world

		// so then you'll need to either... have world notice and handle all collisions in its own thing
		// while we just update and contain physical properties

		// or you could have us access the world
		// nah its better to be a subobject in the world

	}
}