#include "Sphere.hpp"
#include "Constant.hpp"

wlib::Sphere::Sphere(const Translate position, const Scale & scaling, const float r, const Materials & materials) noexcept
	: Geometry(position, Quaternion(), scaling, materials), r_(r)
{}

bool wlib::Sphere::intersect(const Ray & ray, HitPoint & hitpoint) const
{
	const Vector ray_to_this = this->getTranslate() - ray.getEmitPosition();
	const float B = ray_to_this.dot(ray.getDirection());
	const float D = B * B - ray_to_this.dot(ray_to_this) + this->r_ * this->r_;

	if (D > constant::kEps) {
		const float sqrtD = std::sqrt(D);
		const float t1 = B - sqrtD, t2 = B + sqrtD;
		if (t1 > constant::kEps) {
			hitpoint.setDistance(t1);
		}else if(t2 > constant::kEps) {
			hitpoint.setDistance(t2);
		}

		hitpoint.point() = ray.getEmitPosition() + ray.getDirection() * hitpoint.getDistance();
		hitpoint.normal() = (hitpoint.point() - this->getTranslate()).normalize();
	}

	return false;
}
