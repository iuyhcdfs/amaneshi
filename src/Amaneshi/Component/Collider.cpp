#include "Collider.hpp"

#include <Amaneshi/Game_Component.hpp>
#include <Amaneshi/Internal/Math_Position.hpp>
#include <functional>
#include <iostream>
#include <string>

namespace amaneshi
{
	namespace component
	{

		struct Collision
		{
			Collider * This;
			Collider * Other;
		};

		void DefaultCollision(Collision collision)
		{
			std::cout
				<< "Collision between a " << collision.This->Name
				<< " and a " << collision.Other->Name
				<< std::endl;
		}

		class Collider : public amaneshi::game::Component
		{
		protected:
			Collider() { OnCollision = DefaultCollision; }
		public:
			virtual bool TestPoint(amaneshi::math::Point point) = 0;
			std::function<void(Collision collision)> OnCollision;
		};
	}
}