#include "Material.hpp"

wlib::Material wlib::Material::generateDiffuseMaterial(const Color color, const float smoothness)
{ return Material(ReflectionType::kDiffuse, color, smoothness, 1.0f); }

wlib::Material wlib::Material::generateGrassMaterial(void)
{ return Material(ReflectionType::kRefraction, Color(), 1.0f, 1.5f); }

wlib::Material wlib::Material::generateMetaricMaterial(const Color color, const float smoothness)
{ return Material(ReflectionType::kMetalic, color, smoothness, 1.0f); }
