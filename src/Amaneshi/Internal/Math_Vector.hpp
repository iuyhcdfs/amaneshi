#pragma once

namespace amaneshi
{
	namespace math
	{
		class Vector3
		{
		protected:
			float Coordinates[4];
		public:
			float &x = Coordinates[0];
			float &y = Coordinates[1];
			float &z = Coordinates[2];
			float &w = Coordinates[3];
			
			Vector3();
			Vector3(float x, float y);
			Vector3(float x, float y, float z);
			Vector3(const Vector3 &other);
			
			Vector3& operator=(const Vector3 &other);
			Vector3 operator+(const Vector3 &other);
			Vector3 operator-(const Vector3 &other);
			Vector3& operator+=(const Vector3 &other);
			Vector3& operator-=(const Vector3 &other);

			Vector3& operator*=(const float &factor);
			Vector3& operator/=(const float &divisor);
		};

		// typedef Vector3 Vector4; LEARN MORE ABOUT w FIRST, THEN DECIDE WHETHER TO EXPAND OR MAKE A NEW CLASS

		const Vector3 Vector3Null = Vector3(0, 0, 0);
		const Vector3 Vector3Identity = Vector3(1, 1, 1);

		// ----------------------------------------------------------------------------
		float DistanceSquared(const Vector3 &start, const Vector3 &finish);
		float Distance(const Vector3 &start, const Vector3 &finish);
		float DistanceSquared(const Vector3 &vector);
		float Distance(const Vector3 &vector);
		
		// ----------------------------------------------------------------------------
		float Dot(const Vector3 &lhs, const Vector3 &rhs);
		Vector3 Cross(const Vector3 &lhs, const Vector3 &rhs);
		void NormalizeVector(Vector3 &editableVector);
		void ReflectVector(Vector3 &editableVector, const Vector3 &normal);
	}
}