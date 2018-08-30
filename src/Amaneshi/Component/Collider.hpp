#pragma once


#include <Amaneshi/Game_Component.hpp>
#include <Amaneshi/Internal/Math_Position.hpp>
namespace amaneshi
{
	namespace component
	{
		class Collider : public amaneshi::game::Component;
		struct Collision;
		void DefaultCollision(Collision collision);
	}
}