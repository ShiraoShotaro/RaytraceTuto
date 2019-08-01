#ifndef WLIB_RAYTRACE_RAY
#define WLIB_RAYTRACE_RAY
#pragma once

#include "Vector.hpp"

namespace wlib {
	class Ray {
	public:
		explicit Ray(void) noexcept;
		explicit Ray(const Vector emit, const Vector dir) noexcept;
		Ray(const Ray & ray) noexcept;

		const Vector & getEmitPosition(void) const;
		const Vector & getDirection(void) const;
		const Ray & setEmitPosition(const Vector & emit);
		const Ray & setDirection(const Vector & dir);

	private:
		Vector emit_, dir_;
	};
}


#endif