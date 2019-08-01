#include "Color.hpp"
#include <cmath>

namespace {
constexpr float kGamma = 2.2;
}

const wlib::Color & wlib::Color::setLinearRed(const float red)
{
	this->setX(red); return *this;
}


const wlib::Color & wlib::Color::setLinearGreen(const float green)
{
	this->setY(green); return *this;
}

const wlib::Color & wlib::Color::setLinearBlue(const float blue)
{
	this->setZ(blue); return *this;
}

const wlib::Color & wlib::Color::setAlpha(const float alpha)
{
	this->alpha_ = alpha; return *this;
}

const float wlib::Color::getLinearRed(void) const
{
	return this->getX();
}

const float wlib::Color::getLinearGreen(void) const
{
	return this->getY();
}

const float wlib::Color::getLinearBlue(void) const
{
	return this->getZ();
}

const float wlib::Color::getAlpha(void) const
{
	return this->alpha_;
}

const unsigned char wlib::Color::getGammaRed8(void) const
{
	return std::pow(std::fminf(std::fmaxf(this->getLinearRed(), 1.0f), 0.0f), 1 / kGamma) * 255.99f;
}

const unsigned char wlib::Color::getGammaGreen8(void) const
{
	return std::pow(std::fminf(std::fmaxf(this->getLinearGreen(), 1.0f), 0.0f), 1 / kGamma) * 255.99f;
}

const unsigned char wlib::Color::getGammaBlue8(void) const
{
	return std::pow(std::fminf(std::fmaxf(this->getLinearBlue(), 1.0f), 0.0f), 1 / kGamma) * 255.99f;
}

const unsigned char wlib::Color::getAlpha8(void) const
{
	return std::fminf(std::fmaxf(this->getAlpha(), 1.0f), 0.0f) * 255.99f;
}