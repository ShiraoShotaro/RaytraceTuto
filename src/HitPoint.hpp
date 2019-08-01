#ifndef WLIB_HITPOINT_HPP
#define WLIB_HITPOINT_HPP

#include "Vector.hpp"

namespace wlib {

class HitPoint {
private:
	Vector point_;
	Vector normal_;
	float distance_;

public:
	explicit HitPoint(void) noexcept {}
	explicit HitPoint(const Vector & point, const Vector & normal, const float distance) noexcept
		: point_(point), normal_(normal), distance_(distance) {}

	const Vector & point() const { return this->point_; }
	Vector & point() { return this->point_; }

	const Vector & normal() const { return this->normal_; }
	Vector & normal() { return this->normal_; }

	const float getDistance(void) const { return this->distance_; }
	const HitPoint & setDistance(const float distance) { this->distance_ = distance; return *this; }
};

}

#endif