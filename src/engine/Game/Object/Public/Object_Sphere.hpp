#pragma once

#include <Amaneshi/Game_Object.hpp>
#include <Amaneshi/Internal/Math_Position.hpp>

// The prototype for what will eventually be the physics location and rendering component

namespace amaneshi
{
	namespace object
	{

		class Sphere : public amaneshi::game::Object
		{
		protected:
			float Radius;
			amaneshi::math::Vector3 Velocity;
		public:
			Sphere() {
				this->Name = "sphere";
			};

			void SphereRebound(Sphere other); // does not need a plane in calcs due to sphere only

		};

	} //namespace object
} //namespace amaneshi