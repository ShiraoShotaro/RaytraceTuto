#include <cmath>
#include "XorShift.hpp"

wlib::XorShift::XorShift(const unsigned int initial_seed) noexcept
{
	unsigned int s = initial_seed;
	for (std::size_t i = 0; i < this->seed_.size(); ++i) {
		s = 1812433253U * (s ^ (s >> 30)) + (i + 1);
		this->seed_.at(i) = s;
	}
}

unsigned int wlib::XorShift::next(void)
{
	const unsigned int t = this->seed_.at(0) ^ (this->seed_.at(0) << 11);
	this->seed_.at(0) = this->seed_.at(1);
	this->seed_.at(1) = this->seed_.at(2);
	this->seed_.at(2) = this->seed_.at(3);
	return this->seed_.at(3) = this->seed_.at(3) ^ (this->seed_.at(3) >> 19) ^ (t ^ (t >> 8));
}

double wlib::XorShift::nextNormalized(void)
{
	return static_cast<double>(this->next()) / UINT_MAX;
}
