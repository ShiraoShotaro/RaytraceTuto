#ifndef WLIB_GEOMETRY_HPP
#define WLIB_GEOMETRY_HPP

#include "Material.hpp"
#include "Vector.hpp"
#include "Ray.hpp"
#include "HitPoint.hpp"
#include <vector>

namespace wlib {

using Quaternion = Vector;
using Translate = Vector;
using Scale = Vector;
using Materials = std::vector<Material>;

class Geometry {
private:
	Materials materials_;
	Translate position_;
	Quaternion rotation_;
	Scale scale_;

public:

	Geometry() = delete;
	explicit Geometry(const Translate & position, const Quaternion & rotation, const Scale & scaling, Materials && materials) noexcept;
	explicit Geometry(const Translate & position, const Quaternion & rotation, const Scale & scaling, const Materials & materials) noexcept;
	virtual ~Geometry() {}

	const std::vector<Material> & getMaterials(void) const { return this->materials_; }
	const Translate & getTranslate(void) const { return this->position_; }
	const Quaternion & getQuaternion(void) const { return this->rotation_; }
	const Scale & getScale(void) const { return this->scale_; }

	virtual bool intersect(const Ray & ray, HitPoint & hitpoint) const = 0;

};
}

#endif