#pragma once

#include <Amaneshi/Internal/Math_Position.hpp>
#include <Amaneshi/Internal/Math_Rotation.hpp>
#include <Amaneshi/Game_Component.hpp>
#include <vector>
#include <string>
namespace amaneshi 
{
	namespace game
	{
		// World ->contains-> Object ->contains-> Component
		// Objects DONT UPDATE.
		
		class Object {
		protected:
		public:
			std::string Name;
			amaneshi::math::Point WorldPosition;
			amaneshi::math::Point RelativePosition;
			//amaneshi::math::Quaternion WorldQuaternion;
			//amaneshi::math::Quaternion RelativeQuaternion;
			Object * Parent;
			std::vector<Object> Children;
			std::vector<Component> Components;
		};
	}
}