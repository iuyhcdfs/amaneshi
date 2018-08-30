#include "Math_Position.hpp"
#include <cmath>
namespace amaneshi
{
	namespace math
	{
		Point::Point()
		{
			this->x = 0;
			this->y = 0;
			this->z = 0;
		};
		Point::Point(float x, float y)
		{
			this->x = x;
			this->y = y;
			this->z = 0;
		}; 
		Point::Point(float x, float y, float z) 
		{
			this->x = x;
			this->y = y;
			this->z = z;
		};

		float DistanceSquared(const Point &start, const Point &finish)
		{
			float result = 0;
			result += start.x*start.x + finish.x*finish.x;
			result += start.y*start.y + finish.y*finish.y;
			result += start.z*start.z + finish.z*finish.z;
			return result;
		}
		float Distance(const Point &start, const Point &finish)
		{
			float result = DistanceSquared(start, finish);
			result = sqrt(result);
			return result;
		}
	}
}
