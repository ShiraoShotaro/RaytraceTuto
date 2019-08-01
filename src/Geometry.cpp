#include "Geometry.hpp"

wlib::Geometry::Geometry(const Translate & position, const Quaternion & rotation, const Scale & scaling, Materials && materials) noexcept
	: position_(position), rotation_(rotation), scale_(scaling), materials_(std::move(materials))
{}

wlib::Geometry::Geometry(const Translate & position, const Quaternion & rotation, const Scale & scaling, const Materials & materials) noexcept
	: position_(position), rotation_(rotation), scale_(scaling), materials_(materials)
{}
