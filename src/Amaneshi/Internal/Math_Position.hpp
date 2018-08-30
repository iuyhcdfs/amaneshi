#pragma once

namespace amaneshi
{
	namespace math
	{
		class Point
		{
		protected:
			float Coordinates[3];
		public:
			float &x = Coordinates[0];
			float &y = Coordinates[1];
			float &z = Coordinates[2];
			Point();
			Point(float x, float y);
			Point(float x, float y, float z);
		};

		float DistanceSquared(const Point &start, const Point &finish);
		float Distance(const Point &start, const Point &finish);
	}
}