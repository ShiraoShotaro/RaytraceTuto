#ifndef WLIB_COLOR_HPP
#define WLIB_COLOR_HPP

#include "Vector.hpp"

namespace wlib {
class Color : private Vector {
private:
	float alpha_;
public:
	explicit Color(void) noexcept : Vector(0, 0, 0), alpha_(1.0f) {}
	explicit Color(const float r, const float g, const float b, const float a = 1.0f) noexcept : Vector(r, g, b), alpha_(a) {}
	Color(const Color & color) noexcept : Vector(color), alpha_(color.alpha_) {}

	const Color & setLinearRed(const float red);
	const Color & setLinearGreen(const float green);
	const Color & setLinearBlue(const float blue);
	const Color & setAlpha(const float alpha);

	const float getLinearRed(void) const;
	const float getLinearGreen(void) const;
	const float getLinearBlue(void) const;
	const float getAlpha(void) const;

	const unsigned char getGammaRed8(void) const;
	const unsigned char getGammaGreen8(void) const;
	const unsigned char getGammaBlue8(void) const;
	const unsigned char getAlpha8(void) const;

};
}

#endif