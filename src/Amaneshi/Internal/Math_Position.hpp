#pragma once

namespace amaneshi
{
	namespace math
	{
		
		class Point
		{
		public:
			float x;
			float y;
			float z;
			Point() : x(0), y(0), z(0) {};
			Point(float x, float y) : x(x), y(y), z(0) {};
			Point(float x, float y, float z) : x(x), y(y), z(z) {};
		};

		// funcs
	}
}