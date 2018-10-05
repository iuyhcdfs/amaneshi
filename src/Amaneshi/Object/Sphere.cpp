#include "Sphere.hpp"

void amaneshi::object::Sphere::SphereRebound(Sphere other)
{
	amaneshi::math::Point norm;
	norm.x = other.WorldPosition.x - this->WorldPosition.x;
	norm.y = other.WorldPosition.y - this->WorldPosition.y;
	norm.z = other.WorldPosition.z - this->WorldPosition.z;
	
}
