#include "SphereCollider.hpp"

amaneshi::component::SphereCollider::SphereCollider()
{

}

bool amaneshi::component::SphereCollider::TestPoint(amaneshi::math::Point point)
{
	if (amaneshi::math::DistanceSquared(this->Position, point)
		< Radius * Radius)
	{
		return true;
	}
	return false;
	
}
