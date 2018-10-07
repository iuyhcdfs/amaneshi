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
		Vector3 & Vector3::operator=(const Vector3 &other)
		{
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			return *this;
		}

		Vector3 Vector3::operator+(const Vector3 &other)
		{
			Vector3 result;
			result.x = this->x + other.x;
			result.y = this->y + other.y;
			result.z = this->z + other.z;
			return result;
		}

		Vector3 Vector3::operator-(const Vector3 &other)
		{
			Vector3 result;
			result.x = this->x - other.x;
			result.y = this->y - other.y;
			result.z = this->z - other.z;
			return result;
		}

		Vector3 & Vector3::operator+=(const Vector3 &other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;
		}

		Vector3 & Vector3::operator-=(const Vector3 &other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return *this;
		}


		Vector3 & Vector3::operator*=(const float &factor)
		{
			this->x *= factor;
			this->y *= factor;
			this->z *= factor;
			return *this;
		}

		Vector3 & Vector3::operator/=(const float &divisor)
		{
			this->x /= divisor;
			this->y /= divisor;
			this->z /= divisor;
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

		float Dot(const Vector3 & lhs, const Vector3 & rhs)
		{
			return (lhs.x * rhs.x + 
				    lhs.y * rhs.y + 
				    lhs.z * rhs.z);
		}

		Vector3 Cross(const Vector3 & lhs, const Vector3 & rhs)
		{
			return Vector3(lhs.y * rhs.z - lhs.z * rhs.y,
						   lhs.z * rhs.x - lhs.x * rhs.z,
						   lhs.x * rhs.y - lhs.y * rhs.x);
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
		void NormalizeVector(Vector3 &editableVector)
		{
			float distance = Distance(editableVector);
			editableVector.x /= distance;
			editableVector.y /= distance;
			editableVector.z /= distance;
			return;
		}
		void ReflectVector(Vector3 &editableVector, const Vector3 &normal)
		{
			Vector3 unitNormal = normal;
			NormalizeVector(unitNormal);
			float projection = Dot(editableVector, unitNormal);
			unitNormal *= projection * 2;
			editableVector += unitNormal;
			return;
		}
	}
}
