#pragma once

#include <Amaneshi/Component/Collider.hpp>

namespace amaneshi
{
	namespace component
	{

		class SphereCollider : public Collider
		{
		protected:
		public:
			SphereCollider();
			amaneshi::math::Point Position;
			float Radius;
			bool TestPoint(amaneshi::math::Point point) override;
			

		};
	}
}