#include "Math/Vector2.hpp"

namespace Pulsar {
	template<typename T>
	PULSAR_CONSTEXPR T& vec<2, T>::operator[](length_t i) {
		assert(i >= 0 && i < this->length());
		switch (i) {
		case 0:
			return x;
		case 1:
			return y;
		}
	}
	template<typename T>
	PULSAR_CONSTEXPR T const& vec<2, T>::operator[](length_t i) const {
		assert(i >= 0 && i < this->length());
		switch (i) {
		case 0:
			return x;
		case 1:
			return y;
		}
	}

	// -- Implicit basic constructors --

#	if PULSAR_CONFIG_USE_DEFAULT_FUNCTION == PULSAR_DISABLE
		template<typename T>
		PULSAR_CONSTEXPR vec<2, T>::vec() : x(0), y(0) {

		}
		template<typename T>
		PULSAR_CONSTEXPR vec<2, T>::vec(vec<2, T> const& v) : x(v.x), y(v.y) {

		}
#	endif

	// -- Explicit basic constructors --

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T>::vec(T scalar) : x(scalar), y(scalar) {

	}
	template<typename T>
	PULSAR_CONSTEXPR vec<2, T>::vec(T _x, T _y) : x(_x), y(_y) {

	}

	// -- Conversion constructors --

	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>::vec(vec<1, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.x)) {

	}

	// Explicit conversions
	template<typename T> template<typename A, typename B>
	PULSAR_CONSTEXPR vec<2, T>::vec(A _x, B _y)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_y)) {

	}
	template<typename T> template<typename A, typename B>
	PULSAR_CONSTEXPR vec<2, T>::vec(vec<1, A> const& _x, B _y)
		: x(static_cast<T>(_x.x))
		, y(static_cast<T>(y)) {

	}
	template<typename T> template<typename A, typename B>
	PULSAR_CONSTEXPR vec<2, T>::vec(A _x, vec<1, B> const& _y)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_y.x)) {

	}
	template<typename T> template<typename A, typename B>
	PULSAR_CONSTEXPR vec<2, T>::vec(vec<1, A> const& _x, vec<1, B> const& _y)
		: x(static_cast<T>(_x.x))
		, y(static_cast<T>(_y.x)) {

	}

	// -- Conversion vector constructors --

	// Explicit conversions
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR  vec<2, T>::vec(vec<3, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y)) {

	}
	// Explicit conversions
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR  vec<2, T>::vec(vec<4, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y)) {

	}

	// Explicit conversions
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>::vec(vec<2, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y)) {

	}

	// -- Unary arithmetic operators --

#	if PULSAR_CONFIG_USE_DEFAULT_FUNCTION == PULSAR_DISABLE
		template<typename T>
		PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator=(vec const& v) {
			this->x = v.x;
			this->y = v.y;
			return *this;
		}
#	endif

	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator=(vec<2, U> const& v) {
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator+=(U scalar) {
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator+=(vec<1, U> const& v) {
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator+=(vec<2, U> const& v) {
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator-=(U scalar) {
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator-=(vec<1, U> const& v) {
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator-=(vec<2, U> const& v) {
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator*=(U scalar) {
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator*=(vec<1, U> const& v) {
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator*=(vec<2, U> const& v) {
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator/=(U scalar) {
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator/=(vec<1, U> const& v) {
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator/=(vec<2, U> const& v) {
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		return *this;
	}

	// -- Increment and decrement operators --

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator++() {
		++this->x;
		++this->y;
		return *this;
	}
	template<typename T>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator--() {
		--this->x;
		--this->y;
	}
	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> vec<2, T>::operator++(int) {
		vec<2, T> Result(*this);
		++* this;
		return Result;
	}
	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> vec<2, T>::operator--(int) {
		vec<2, T> Result(*this);
		--* this;
		return Result;
	}

	// -- Unary bit operators --

	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator%=(U scalar) {
		this->x %= static_cast<T>(scalar);
		this->y %= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator%=(vec<1, U> const& v) {
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator%=(vec<2, U> const& v) {
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.y);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator&=(U scalar) {
		this->x &= static_cast<T>(scalar);
		this->y &= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator&=(vec<1, U> const& v) {
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator&=(vec<2, U> const& v) {
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.y);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator|=(U scalar) {
		this->x |= static_cast<T>(scalar);
		this->y |= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator|=(vec<1, U> const& v) {
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator|=(vec<2, U> const& v) {
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.y);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator^=(U scalar) {
		this->x ^= static_cast<T>(scalar);
		this->y ^= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator^=(vec<1, U> const& v) {
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator^=(vec<2, U> const& v) {
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.y);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator<<=(U scalar) {
		this->x <<= static_cast<T>(scalar);
		this->y <<= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator<<=(vec<1, U> const& v) {
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator<<=(vec<2, U> const& v) {
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.y);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator>>=(U scalar) {
		this->x >>= static_cast<T>(scalar);
		this->y >>= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator>>=(vec<1, U> const& v) {
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<2, T>& vec<2, T>::operator>>=(vec<2, U> const& v) {
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.y);
		return *this;
	}

	// -- Unary operators --

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v) {
		return v;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v) {
		return vec<2, T>(-v.x, -v.y);
	}

	// -- Binary operators --

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v, U scalar) {
		return vec<2, T>(v) += scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v1, vec<1, U> const& v2) {
		return vec<2, T>(v1) += v2;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator+(U scalar, vec<2, T> const& v) {
		return vec<2, T>(v) += scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator+(vec<1, U> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v2) += v1;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v1, vec<2, U> const& v2) {
		return vec<2, T>(v1) += v2;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v, U scalar) {
		return vec<2, T>(v) -= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v1, vec<1, U> const& v2) {
		return vec<2, T>(v1) -= v2;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator-(U scalar, vec<2, T> const& v) {
		return vec<2, T>(v) -= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator-(vec<1, U> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v2) -= v1;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v1, vec<2, U> const& v2) {
		return vec<2, T>(v1) -= v2;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator*(vec<2, T> const& v, U scalar) {
		return vec<2, T>(v) *= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator*(vec<2, T> const& v1, vec<1, U> const& v2) {
		return vec<2, T>(v1) *= v2;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator*(U scalar, vec<2, T> const& v) {
		return vec<2, T>(v) *= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator*(vec<1, U> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v2) *= v1;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator*(vec<2, T> const& v1, vec<2, U> const& v2) {
		return vec<2, T>(v1) *= v2;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator/(vec<2, T> const& v, U scalar) {
		return vec<2, T>(v) /= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator/(vec<2, T> const& v1, vec<1, U> const& v2) {
		return vec<2, T>(v1) /= v2;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator/(U scalar, vec<2, T> const& v) {
		return vec<2, T>(v) /= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator/(vec<1, U> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v2) /= v1;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator/(vec<2, T> const& v1, vec<2, U> const& v2) {
		return vec<2, T>(v1) /= v2;
	}
	
	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator%(vec<2, T> const& v, T scalar) {
		return vec<2, T>(v.x % scalar, v.y % scalar);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator%(vec<2, T> const& v1, vec<1, T> const& v2) {
		return vec<2, T>(v1.x % v2.x, v1.y % v2.x);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator%(T scalar, vec<2, T> const& v) {
		return vec<2, T>(scalar % v.x, scalar % v.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator%(vec<1, T> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v1.x % v2.x, v1.x % v2.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator%(vec<2, T> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v1.x % v2.x, v1.y % v2.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator&(vec<2, T> const& v, T scalar) {
		return vec<2, T>(v.x & scalar, v.y & scalar);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator&(vec<2, T> const& v1, vec<1, T> const& v2) {
		return vec<2, T>(v1.x & v2.x, v1.y & v2.x);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator&(T scalar, vec<2, T> const& v) {
		return vec<2, T>(scalar & v.x, scalar & v.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator&(vec<1, T> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v1.x & v2.x, v1.x & v2.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator&(vec<2, T> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v1.x & v2.x, v1.y & v2.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator|(vec<2, T> const& v, T scalar) {
		return vec<2, T>(v.x | scalar, v.y | scalar);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator|(vec<2, T> const& v1, vec<1, T> const& v2) {
		return vec<2, T>(v1.x | v2.x, v1.y | v2.x);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator|(T scalar, vec<2, T> const& v) {
		return vec<2, T>(scalar | v.x, scalar | v.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator|(vec<1, T> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v1.x | v2.x, v1.x | v2.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator|(vec<2, T> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v1.x | v2.x, v1.y | v2.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator^(vec<2, T> const& v, T scalar) {
		return vec<2, T>(v.x ^ scalar, v.y ^ scalar);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator^(vec<2, T> const& v1, vec<1, T> const& v2) {
		return vec<2, T>(v1.x ^ v2.x, v1.y ^ v2.x);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator^(T scalar, vec<2, T> const& v) {
		return vec<2, T>(scalar ^ v.x, scalar ^ v.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator^(vec<1, T> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v1.x ^ v2.x, v1.x ^ v2.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator^(vec<2, T> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v1.x ^ v2.x, v1.y ^ v2.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator<<(vec<2, T> const& v, T scalar) {
		return vec<2, T>(v.x << scalar, v.y << scalar);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator<<(vec<2, T> const& v1, vec<1, T> const& v2) {
		return vec<2, T>(v1.x << v2.x, v1.y << v2.x);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator<<(T scalar, vec<2, T> const& v) {
		return vec<2, T>(scalar << v.x, scalar << v.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator<<(vec<1, T> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v1.x << v2.x, v1.x << v2.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator<<(vec<2, T> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v1.x << v2.x, v1.y << v2.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator>>(vec<2, T> const& v, T scalar) {
		return vec<2, T>(v.x >> scalar, v.y >> scalar);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator>>(vec<2, T> const& v1, vec<1, T> const& v2) {
		return vec<2, T>(v1.x >> v2.x, v1.y >> v2.x);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator>>(T scalar, vec<2, T> const& v) {
		return vec<2, T>(scalar >> v.x, scalar >> v.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator>>(vec<1, T> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v1.x >> v2.x, v1.x >> v2.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator>>(vec<2, T> const& v1, vec<2, T> const& v2) {
		return vec<2, T>(v1.x >> v2.x, v1.y >> v2.y);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator~(vec<2, T> const& v) {
		return vec<2, T>(~v.x, ~v.y);
	}

	// -- Boolean operators --

	template<typename T>
	PULSAR_CONSTEXPR bool operator>(vec<2, T> const& v1, vec<2, T> const& v2) {
		return v1.x == v2.x ? v1.y > v2.y: v1.x > v2.x;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator<(vec<2, T> const& v1, vec<2, T> const& v2) {
		return v1.x == v2.x ? v1.y < v2.y : v1.x < v2.x;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator>=(vec<2, T> const& v1, vec<2, T> const& v2) {
		return v1.x == v2.x ? v1.y >= v2.y : v1.x >= v2.x;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator<=(vec<2, T> const& v1, vec<2, T> const& v2) {
		return v1.x == v2.x ? v1.y <= v2.y : v1.x <= v2.x;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator==(vec<2, T> const& v1, vec<2, T> const& v2) {
		return v1.x == v2.x
			&& v1.y == v2.y;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator!=(vec<2, T> const& v1, vec<2, T> const& v2) {
		return v1.x != v2.x
			|| v1.y != v2.y;
	}

	PULSAR_CONSTEXPR vec<2, bool> operator&&(vec<2, bool> const& v1, vec<2, bool> const& v2) {
		return vec<2, bool>(v1.x && v2.x, v1.y && v2.y);
	}

	PULSAR_CONSTEXPR vec<2, bool> operator||(vec<2, bool> const& v1, vec<2, bool> const& v2) {
		return vec<2, bool>(v1.x || v2.x, v1.y || v2.y);
	}
}