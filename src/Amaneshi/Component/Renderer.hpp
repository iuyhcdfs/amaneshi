#pragma once

#include <iostream>
#include <Amaneshi/Internal/Game_Component.hpp>

namespace amaneshi
{
	namespace Component
	{
		// objects -> components -> anything that isnt "world"

		class Renderer : public amaneshi::game::Component
		{
		public:
			virtual void Render() {};
		};

		class TempRenderer : public Renderer
		{
		public:
			void Render() override
			{
				std::cout << "Render got called!" << std::endl;
			}
		};
	}
}