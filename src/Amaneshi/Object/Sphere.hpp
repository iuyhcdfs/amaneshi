#pragma once

#include <Amaneshi/Game_Object.hpp>
#include <Amaneshi/Internal/Math_Position.hpp>

namespace amaneshi
{
	namespace object
	{

		class Sphere : public amaneshi::game::Object
		{
		protected:
			float Radius;
		public:
			Sphere() {
				this->Name = "sphere";
			};
		};

	} //namespace object
} //namespace amaneshi