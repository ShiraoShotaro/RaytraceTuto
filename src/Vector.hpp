#ifndef WLIB_RAYTRACE_VECTOR
#define WLIB_RAYTRACE_VECTOR
#pragma once

namespace wlib {

	class Vector {
	protected:
		float x_, y_, z_, w_;
	public:
		explicit Vector(void) noexcept : x_(0.0f), y_(0.0f), z_(0.0f), w_(1.0f) {}
		explicit Vector(const float x, const float y, const float z, const float w = 1.0f) noexcept : x_(x), y_(y), z_(z), w_(w) {}
		Vector(const Vector & vector) noexcept : x_(vector.x_), y_(vector.y_), z_(vector.z_), w_(vector.w_) {}
		virtual ~Vector(void) noexcept {}

		inline const float getX(void) const;
		inline const float getY(void) const;
		inline const float getZ(void) const;
		inline const float getW(void) const;
		inline const Vector & setX(const float x);
		inline const Vector & setY(const float y);
		inline const Vector & setZ(const float z);
		inline const Vector & setW(const float w);

		inline const Vector operator+(const Vector & other) const;
		inline const Vector operator-(const Vector & other) const;
		inline const Vector operator*(const float scalar) const;
		
		inline void operator+=(const Vector & other);
		inline void operator-=(const Vector & other);
		inline void operator*=(const float scalar);

		inline const float dot(const Vector & other) const;
		inline const Vector cross(const Vector & other) const;

		const float length(void) const;
		inline const Vector normalize(void) const;
		inline const Vector & normalized(void);

	};

	inline const float Vector::getX(void) const
	{ return this->x_; }

	inline const float Vector::getY(void) const
	{ return this->y_; }

	inline const float Vector::getZ(void) const
	{ return this->z_; }

	inline const float Vector::getW(void) const
	{ return this->w_; }

	inline const Vector & Vector::setX(const float x)
	{ this->x_ = x; return *this; }

	inline const Vector & Vector::setY(const float y)
	{ this->y_ = y; return *this; }

	inline const Vector & Vector::setZ(const float z)
	{ this->z_ = z; return *this; }

	inline const Vector & Vector::setW(const float w)
	{ this->w_ = w; return *this; }

	inline const Vector wlib::Vector::operator+(const Vector & other) const
	{ return Vector(this->x_ + other.x_, this->y_ + other.y_, this->z_ + other.z_); }

	inline const Vector Vector::operator-(const Vector & other) const
	{ return Vector(this->x_ - other.x_, this->y_ - other.y_, this->z_ - other.z_);	}

	inline const Vector Vector::operator*(const float scalar) const
	{ return Vector(this->x_ * scalar, this->y_ * scalar, this->z_ * scalar); }

	inline void Vector::operator+=(const Vector & other)
	{ *this = *this + other; }

	inline void Vector::operator-=(const Vector & other)
	{ *this = *this - other; }

	inline void Vector::operator*=(const float scalar)
	{ *this = *this * scalar; }

	inline const float Vector::dot(const Vector & other) const 
	{ return this->x_ * other.x_ + this->y_ * other.y_ + this->z_ * other.z_; }

	inline const Vector Vector::cross(const Vector & other) const {
		return Vector(
			this->y_ * other.z_ - this->z_ * other.y_,
			this->z_ * other.x_ - this->x_ * other.z_,
			this->x_ * other.y_ - this->y_ * other.x_
		);
	}


	inline const Vector Vector::normalize(void) const
	{ return *this * (1.0f / this->length()); }

	inline const Vector & Vector::normalized(void)
	{ *this *= (1.0f / this->length()); return *this; }

}

#endif