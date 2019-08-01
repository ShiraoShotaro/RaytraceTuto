#ifndef WLIB_MATERIAL_HPP
#define WLIB_MATERIAL_HPP

#include "Color.hpp"

namespace wlib {
class Material {
public:
	enum ReflectionType {
		kDiffuse,
		kMetalic,
		kRefraction
	};

	explicit Material(const ReflectionType type, const Color & color, const float smoothness, const float ior) noexcept
		: type_(type), diffuseColor_(color), smoothness_(smoothness), ior_(ior) {}

	Material(const Material & material) noexcept 
		: type_(material.type_), diffuseColor_(material.diffuseColor_), smoothness_(material.smoothness_), ior_(material.ior_) {}

	ReflectionType getReflectionType(void) const { return type_; }
	Color getColor(void) const { return diffuseColor_; }
	float getIor(void) const { return ior_; }

	static Material generateDiffuseMaterial(const Color color, const float smoothness);
	static Material generateGrassMaterial(void);
	static Material generateMetaricMaterial(const Color color, const float smoothness);

private:
	float ior_;
	Color diffuseColor_;
	float smoothness_;
	ReflectionType type_;
};
}

#endif