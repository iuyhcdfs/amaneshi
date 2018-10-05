#include "Math_Vector.hpp"
#include <cmath>
namespace amaneshi
{
	namespace math
	{
		Vector3::Vector3()
		{
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}
		Vector3::Vector3(float x, float y)
		{
			this->x = x;
			this->y = y;
			this->z = 0;
		} 
		Vector3::Vector3(float x, float y, float z) 
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		Vector3::Vector3(const Vector3 &other)
		{
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
		}
		Vector3 & Vector3::operator=(Vector3 other)
		{
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			return *this;
		}

		float DistanceSquared(const Vector3 &start, const Vector3 &finish)
		{
			float result = 0;
			result += start.x*start.x + finish.x*finish.x;
			result += start.y*start.y + finish.y*finish.y;
			result += start.z*start.z + finish.z*finish.z;
			return result;
		}
		float Distance(const Vector3 &start, const Vector3 &finish)
		{
			return sqrt( DistanceSquared(start, finish) );
		}
		float DistanceSquared(const Vector3 &vector)
		{
			float result = 0;
			result += vector.x*vector.x;
			result += vector.y*vector.y;
			result += vector.z*vector.z;
			return result;
		}
		float Distance(const Vector3 &vector)
		{
			return sqrt( DistanceSquared(vector) );
		}

		/*
		// Not for use: should just make your own separate vector elsewhere
		Vector3 Normalize(const Vector3 &vector)
		{
			float distance = Distance(vector);
			Vector3 result = Vector3(vector);
			result.x /= distance;
			result.y /= distance;
			result.z /= distance;
		}
		*/
		void NormalizeVector(Vector3 * editableVector)
		{
			float distance = Distance(*editableVector);
			editableVector->x /= distance;
			editableVector->y /= distance;
			editableVector->z /= distance;
		}

		void ReflectVector(Vector3 * editableVector, const Vector3 &normal)
		{
			
		}
	}
}
