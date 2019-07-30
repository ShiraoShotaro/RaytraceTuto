#include "Vector.hpp"
#include <cmath>

const float wlib::Vector::length(void) const{
	return std::sqrt(this->x_ * this->x_ + this->y_ * this->y_ + this->z_ * this->z_);
}