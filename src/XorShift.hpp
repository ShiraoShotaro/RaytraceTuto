#ifndef WLIB_XORSHIFT_HPP
#define WLIB_XORSHIFT_HPP

#include <array>
#include <climits>

namespace wlib {
class XorShift {
public:
	explicit XorShift() = delete;
	explicit XorShift(const unsigned int initial_seed) noexcept;
	unsigned int next(void);
	double nextNormalized(void);

private:
	std::array<unsigned int, 4> seed_;
};

using Random = XorShift;

}

#endif