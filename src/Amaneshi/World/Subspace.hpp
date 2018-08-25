#pragma once

#include <Amaneshi/Internal/Math_Position.hpp>
#include <Amaneshi/Game_Object.hpp>
#include <vector>
//#include <unordered_map>
#include <unordered_set>
namespace amaneshi
{
	namespace world
	{ 
		// subspace just stores the general area of many objects
		enum AxisEnum
		{
			x, y, z,
			AxisEnumSize
		};
		
		// track part of the world as defined
		template <class BucketT>
		class Subspace
		{
		protected:
			AxisEnum Axis;
			std::vector< BucketT > Buckets;
		public:
			float BucketSpan;
			
			Subspace(AxisEnum axis, bool bucketIndexIsPositive, float bucketSpan)
			{ 
				Buckets = std::vector< std::vector<amaneshi::game::Object> >(1); 
				Axis = axis;
				BucketIndexIsPositive = bucketIndexIsPositive;
				BucketSpan = bucketSpan;
			}

			BucketT operator[](int i)
			{
				if (i < 0)
				{
					return nullptr;
				}
				return Buckets[i];
			}
			BucketT BucketFromFloat(float position)
			{
				int i = position;
			}
		};

		class Bucket
		{
		public:
			//std::unordered_set<amaneshi::game::Object> Objects;
			
			/*
			actually we can make a set
			have the set insertions sort the position for each dimension
			
			then we can actually use that property when dealing with collisions?

			wait, 
			once an object moves this is invalid.
			nevermind.
			*/

		};

		// track infinite space, slower than subspace
		/*class Subnet
		{

		};*/
	}
}