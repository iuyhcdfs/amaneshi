#pragma once

#include <Amaneshi/Internal/Type_Updatable.hpp>
#include <string>
namespace amaneshi
{
	namespace game
	{
		class Component : public amaneshi::type::Updatable
		{
		public:
			std::string Name;
			amaneshi::game::Object * Owner;
		};
	}
}