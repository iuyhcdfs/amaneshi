#pragma once
#include <Amaneshi/Internal/Math_Position.hpp>
#include <Amaneshi/Internal/Math_Rotation.hpp>
namespace amaneshi
{
	namespace graphics
	{	
		class Camera
		{
		protected:
			struct Rectangle
			{
				float Width;
				float Height;
				float Distance;
			};
			Rectangle Near;
			Rectangle Far;
		public:
			amaneshi::math::Point Position;
			amaneshi::math::Point Direction;
			// quaternions later
			float FieldOfViewDegrees = 60;
			float Distance = 100;
			void SetIsometric();
			void SetPerspective();
		};
	}
}