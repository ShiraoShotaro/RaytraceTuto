#include "Vector.hpp"
#include <cmath>
#include "Ray.hpp"

wlib::Ray::Ray(void) noexcept : emit_(0, 0, 0), dir_(0, 0, 1) {}

wlib::Ray::Ray(const Vector emit, const Vector dir) noexcept : emit_(emit), dir_(dir) {}

wlib::Ray::Ray(const Ray & ray) noexcept : emit_(ray.emit_), dir_(ray.dir_) {}

const wlib::Vector & wlib::Ray::getEmitPosition(void) const
{ return this->emit_; }

const wlib::Vector & wlib::Ray::getDirection(void) const
{ return this->dir_; }

const wlib::Ray & wlib::Ray::setEmitPosition(const Vector & emit)
{ this->emit_ = emit; return *this; }

const wlib::Ray & wlib::Ray::setDirection(const Vector & dir)
{ this->dir_ = dir; this->dir_.normalized(); return *this; }
