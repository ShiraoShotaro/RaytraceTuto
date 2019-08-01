#ifndef WLIB_SPHERE_HPP
#define WLIB_SPHERE_HPP

#include "Geometry.hpp"

namespace wlib {
class Sphere : public Geometry{
private:
	float r_;

public:
	explicit Sphere(const Translate position, const Scale & scaling, const float r, const Materials & materials) noexcept;

	virtual bool intersect(const Ray & ray, HitPoint & hitpoint) const override;

};
}

#endif