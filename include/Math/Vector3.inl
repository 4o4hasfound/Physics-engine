#include "Vector3.hpp"

namespace Pulsar {
	template<typename T>
	PULSAR_CONSTEXPR T& vec<3, T>::operator[](length_t i) {
		assert(i >= 0 && i < this->length());
		switch (i) {
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		}
	}
	template<typename T>
	PULSAR_CONSTEXPR T const& vec<3, T>::operator[](length_t i) const {
		assert(i >= 0 && i < this->length());
		switch (i) {
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		}
	}

	// -- Implicit basic constructors --
#	if PULSAR_CONFIG_USE_DEFAULT_FUNCTION == PULSAR_DISABLE
		template<typename T>
		PULSAR_CONSTEXPR vec<3, T>::vec()
			: x(0), y(0), z(0) {

		}
		template<typename T>
		PULSAR_CONSTEXPR vec<3, T>::vec(vec const& v)
			x(v.x), y(v.y), z(v.z) {
			
		}
#	endif

	// -- Explicit basic constructors --

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T>::vec(T scalar)
		: x(scalar), y(scalar), z(scalar) {

	}
	template<typename T>
	PULSAR_CONSTEXPR vec<3, T>::vec(T a, T b, T c)
		: x(a), y(b), z(c) {

	}

	// -- Conversion scalar constructors --

	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>::vec(vec<1, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.x))
		, z(static_cast<T>(v.z)) {

	}

	/// Explicit conversions
	template<typename T> template<typename X, typename Y, typename Z>
	PULSAR_CONSTEXPR vec<3, T>::vec(X _x, Y _y, Z _z)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_y))
		, z(static_cast<T>(_z)) {

	}
	template<typename T> template<typename X, typename Y, typename Z>
	PULSAR_CONSTEXPR vec<3, T>::vec(vec<1, X> const& _x, Y _y, Z _z)
		: x(static_cast<T>(_x.x))
		, y(static_cast<T>(_y))
		, z(static_cast<T>(_z)) {

	}
	template<typename T> template<typename X, typename Y, typename Z>
	PULSAR_CONSTEXPR vec<3, T>::vec(X _x, vec<1, Y> const& _y, Z _z)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_y.x))
		, z(static_cast<T>(_z)) {

	}
	template<typename T> template<typename X, typename Y, typename Z>
	PULSAR_CONSTEXPR vec<3, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, Z _z)
		: x(static_cast<T>(_x.x))
		, y(static_cast<T>(_y.x))
		, z(static_cast<T>(_z)) {

	}
	template<typename T> template<typename X, typename Y, typename Z>
	PULSAR_CONSTEXPR vec<3, T>::vec(X _x, Y _y, vec<1, Z> const& _z)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_y))
		, z(static_cast<T>(_z.x)) {

	}
	template<typename T> template<typename X, typename Y, typename Z>
	PULSAR_CONSTEXPR vec<3, T>::vec(vec<1, X> const& _x, Y _y, vec<1, Z> const& _z)
		: x(static_cast<T>(_x.x))
		, y(static_cast<T>(_y))
		, z(static_cast<T>(_z.x)) {

	}
	template<typename T> template<typename X, typename Y, typename Z>
	PULSAR_CONSTEXPR vec<3, T>::vec(X _x, vec<1, Y> const& _y, vec<1, Z> const& _z)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_y.x))
		, z(static_cast<T>(_z.x)) {

	}
	template<typename T> template<typename X, typename Y, typename Z>
	PULSAR_CONSTEXPR vec<3, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, vec<1, Z> const& _z)
		: x(static_cast<T>(_x.x))
		, y(static_cast<T>(_y.x))
		, z(static_cast<T>(_z.x)) {

	}

	// -- Conversion vector constructors --

	template<typename T> template<typename A, typename B>
	PULSAR_CONSTEXPR vec<3, T>::vec(vec<2, A> const& _xy, B _z)
		: x(static_cast<T>(_xy.x))
		, y(static_cast<T>(_xy.y))
		, z(static_cast<T>(_z)) {

	}
	template<typename T> template<typename A, typename B>
	PULSAR_CONSTEXPR vec<3, T>::vec(vec<2, A> const& _xy, vec<1, B> const& _z)
		: x(static_cast<T>(_xy.x))
		, y(static_cast<T>(_xy.y))
		, z(static_cast<T>(_z.x)) {

	}
	template<typename T> template<typename A, typename B>
	PULSAR_CONSTEXPR vec<3, T>::vec(A _x, vec<2, B> const& _yz)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_yz.x))
		, z(static_cast<T>(_yz.y)) {

	}
	template<typename T> template<typename A, typename B>
	PULSAR_CONSTEXPR vec<3, T>::vec(vec<1, A> const& _x, vec<2, B> const& _yz)
		: x(static_cast<T>(_x.x))
		, y(static_cast<T>(_yz.x))
		, z(static_cast<T>(_yz.y)) {

	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>::vec(vec<4, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y))
		, z(static_cast<T>(v.z)) {

	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>::vec(vec<3, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y))
		, z(static_cast<T>(v.z)) {

	}

	// -- Unary arithmetic vec<3, T>::operators --

#	if PULSAR_CONFIG_USE_DEFAULT_FUNCTION == PULSAR_DISABLE
		template<typename T>
		PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator=(vec<3, T> const& v) {
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			return *this;
		}
#	endif
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator=(vec<3, U> const& v) {
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		this->z = static_cast<T>(v.z);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator+=(U scalar) {
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		this->z += static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator+=(vec<1, U> const& v) {
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.x);
		this->z += static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator+=(vec<3, U> const& v) {
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		this->z += static_cast<T>(v.z);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator-=(U scalar) {
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		this->z -= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator-=(vec<1, U> const& v) {
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.x);
		this->z -= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator-=(vec<3, U> const& v) {
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		this->z -= static_cast<T>(v.z);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator*=(U scalar) {
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		this->z *= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator*=(vec<1, U> const& v) {
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.x);
		this->z *= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator*=(vec<3, U> const& v) {
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		this->z *= static_cast<T>(v.z);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator/=(U scalar) {
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		this->z /= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator/=(vec<1, U> const& v) {
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.x);
		this->z /= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator/=(vec<3, U> const& v) {
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		this->z /= static_cast<T>(v.z);
		return *this;
	}

	// -- Increment and decrement vec<3, T>::operators --

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator++() {
		++this->x;
		++this->y;
		++this->z;
		return *this;
	}
	template<typename T>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator--() {
		--this->x;
		--this->y;
		--this->z;
		return *this;
	}
	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> vec<3, T>::operator++(int) {
		vec<3, T> Result(*this);
		++* this;
		return Result;
	}
	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> vec<3, T>::operator--(int) {
		vec<3, T> Result(*this);
		--* this;
		return Result;
	}

	// -- Unary bit vec<3, T>::operators --

	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator%=(U scalar) {
		this->x %= static_cast<T>(scalar);
		this->y %= static_cast<T>(scalar);
		this->z %= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator%=(vec<1, U> const& v) {
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.x);
		this->z %= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator%=(vec<3, U> const& v) {
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.y);
		this->z %= static_cast<T>(v.z);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator&=(U scalar) {
		this->x &= static_cast<T>(scalar);
		this->y &= static_cast<T>(scalar);
		this->z &= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator&=(vec<1, U> const& v) {
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.x);
		this->z &= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator&=(vec<3, U> const& v) {
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.y);
		this->z &= static_cast<T>(v.z);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator|=(U scalar) {
		this->x |= static_cast<T>(scalar);
		this->y |= static_cast<T>(scalar);
		this->z |= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator|=(vec<1, U> const& v) {
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.x);
		this->z |= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator|=(vec<3, U> const& v) {
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.y);
		this->z |= static_cast<T>(v.z);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator^=(U scalar) {
		this->x ^= static_cast<T>(scalar);
		this->y ^= static_cast<T>(scalar);
		this->z ^= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator^=(vec<1, U> const& v) {
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.x);
		this->z ^= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator^=(vec<3, U> const& v) {
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.y);
		this->z ^= static_cast<T>(v.z);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator>>=(U scalar) {
		this->x >>= static_cast<T>(scalar);
		this->y >>= static_cast<T>(scalar);
		this->z >>= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator>>=(vec<1, U> const& v) {
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.x);
		this->z >>= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator>>=(vec<3, U> const& v) {
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.y);
		this->z >>= static_cast<T>(v.z);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator<<=(U scalar) {
		this->x <<= static_cast<T>(scalar);
		this->y <<= static_cast<T>(scalar);
		this->z <<= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator<<=(vec<1, U> const& v) {
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.x);
		this->z <<= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<3, T>& vec<3, T>::operator<<=(vec<3, U> const& v) {
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.y);
		this->z <<= static_cast<T>(v.z);
		return *this;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v) {
		return v;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v) {
		return vec<3, T>(-v.x, -v.y, -v.z);
	}

	// -- Binary operators --

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v, U scalar) {
		return vec<3, T>(v) += scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v, vec<1, U> const& scalar) {
		return vec<3, T>(v) += scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator+(U scalar, vec<3, T> const& v) {
		return vec<3, T>(v) += scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator+(vec<1, U> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v2) += v1;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v1, vec<3, U> const& v2) {
		return vec<3, T>(v1) += v2;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v, U scalar) {
		return vec<3, T>(v) -= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v, vec<1, U> const& scalar) {
		return vec<3, T>(v) -= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator-(U scalar, vec<3, T> const& v) {
		return vec<3, T>(v) -= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator-(vec<1, U> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v2) -= v1;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v1, vec<3, U> const& v2) {
		return vec<3, T>(v1) -= v2;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v, U scalar) {
		return vec<3, T>(v) *= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v, vec<1, U> const& scalar) {
		return vec<3, T>(v) *= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator*(U scalar, vec<3, T> const& v) {
		return vec<3, T>(v) *= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator*(vec<1, U> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v2) *= v1;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v1, vec<3, U> const& v2) {
		return vec<3, T>(v1) *= v2;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v, U scalar) {
		return vec<3, T>(v) /= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v, vec<1, U> const& scalar) {
		return vec<3, T>(v) /= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator/(U scalar, vec<3, T> const& v) {
		return vec<3, T>(v) /= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator/(vec<1, U> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v2) /= v1;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v1, vec<3, U> const& v2) {
		return vec<3, T>(v1) /= v2;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator%(vec<3, T> const& v, T scalar) {
		return vec<3, T>(v.x % scalar, v.y % scalar, v.z % scalar);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator%(vec<3, T> const& v, vec<1, T> const& scalar) {
		return vec<3, T>(v.x % scalar.x, v.y % scalar.x, v.z % scalar.x);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator%(T scalar, vec<3, T> const& v) {
		return vec<3, T>(scalar % v.x, scalar % v.y, scalar % v.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator%(vec<1, T> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v1.x % v2.x, v1.x % v2.y, v1.x % v2.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator%(vec<3, T> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v1.x % v2.x, v1.y % v2.y, v1.z % v2.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator&(vec<3, T> const& v, T scalar) {
		return vec<3, T>(v.x & scalar, v.y & scalar, v.z & scalar);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator&(vec<3, T> const& v, vec<1, T> const& scalar) {
		return vec<3, T>(v.x & scalar.x, v.y & scalar.x, v.z & scalar.x);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator&(T scalar, vec<3, T> const& v) {
		return vec<3, T>(scalar & v.x, scalar & v.y, scalar & v.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator&(vec<1, T> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v1.x & v2.x, v1.x & v2.y, v1.x & v2.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator&(vec<3, T> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v1.x & v2.x, v1.y & v2.y, v1.z & v2.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator|(vec<3, T> const& v, T scalar) {
		return vec<3, T>(v.x | scalar, v.y | scalar, v.z | scalar);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator|(vec<3, T> const& v, vec<1, T> const& scalar) {
		return vec<3, T>(v.x | scalar.x, v.y | scalar.x, v.z | scalar.x);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator|(T scalar, vec<3, T> const& v) {
		return vec<3, T>(scalar | v.x, scalar | v.y, scalar | v.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator|(vec<1, T> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v1.x | v2.x, v1.x | v2.y, v1.x | v2.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator|(vec<3, T> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v1.x | v2.x, v1.y | v2.y, v1.z | v2.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator^(vec<3, T> const& v, T scalar) {
		return vec<3, T>(v.x ^ scalar, v.y ^ scalar, v.z ^ scalar);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator^(vec<3, T> const& v, vec<1, T> const& scalar) {
		return vec<3, T>(v.x ^ scalar.x, v.y ^ scalar.x, v.z ^ scalar.x);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator^(T scalar, vec<3, T> const& v) {
		return vec<3, T>(scalar ^ v.x, scalar ^ v.y, scalar ^ v.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator^(vec<1, T> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v1.x ^ v2.x, v1.x ^ v2.y, v1.x ^ v2.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator^(vec<3, T> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v1.x ^ v2.x, v1.y ^ v2.y, v1.z ^ v2.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator<<(vec<3, T> const& v, T scalar) {
		return vec<3, T>(v.x << scalar, v.y << scalar, v.z << scalar);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator<<(vec<3, T> const& v, vec<1, T> const& scalar) {
		return vec<3, T>(v.x << scalar.x, v.y << scalar.x, v.z << scalar.x);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator<<(T scalar, vec<3, T> const& v) {
		return vec<3, T>(scalar << v.x, scalar << v.y, scalar << v.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator<<(vec<1, T> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v1.x << v2.x, v1.x << v2.y, v1.x << v2.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator<<(vec<3, T> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v1.x << v2.x, v1.y << v2.y, v1.z << v2.z);
	}
	
	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator>>(vec<3, T> const& v, T scalar) {
		return vec<3, T>(v.x >> scalar, v.y >> scalar, v.z >> scalar);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator>>(vec<3, T> const& v, vec<1, T> const& scalar) {
		return vec<3, T>(v.x >> scalar.x, v.y >> scalar.x, v.z >> scalar.x);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator>>(T scalar, vec<3, T> const& v) {
		return vec<3, T>(scalar >> v.x, scalar >> v.y, scalar >> v.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator>>(vec<1, T> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v1.x >> v2.x, v1.x >> v2.y, v1.x >> v2.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator>>(vec<3, T> const& v1, vec<3, T> const& v2) {
		return vec<3, T>(v1.x >> v2.x, v1.y >> v2.y, v1.z >> v2.z);
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator~(vec<3, T> const& v) {
		return vec<3, T>(~v.x, ~v.y, ~v.z);
	}

	// -- Boolean operators --

	template<typename T>
	PULSAR_CONSTEXPR bool operator>(vec<3, T> const& v1, vec<3, T> const& v2) {
		return v1.x == v2.x ? (v1.y == v2.y ? v1.z > v2.z: v1.y > v2.y) : v1.x > v2.x;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator<(vec<3, T> const& v1, vec<3, T> const& v2) {
		return v1.x == v2.x ? (v1.y == v2.y ? v1.z < v2.z : v1.y < v2.y) : v1.x < v2.x;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator>=(vec<3, T> const& v1, vec<3, T> const& v2) {
		return v1.x == v2.x ? (v1.y == v2.y ? v1.z >= v2.z : v1.y >= v2.y) : v1.x >= v2.x;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator<=(vec<3, T> const& v1, vec<3, T> const& v2) {
		return v1.x == v2.x ? (v1.y == v2.y ? v1.z <= v2.z : v1.y <= v2.y) : v1.x <= v2.x;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator==(vec<3, T> const& v1, vec<3, T> const& v2) {
		return v1.x == v2.x
			&& v1.y == v2.y
			&& v1.z == v2.z;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator!=(vec<3, T> const& v1, vec<3, T> const& v2) {
		return v1.x != v2.x
			|| v1.y != v2.y
			|| v1.z != v2.z;
	}

	PULSAR_CONSTEXPR vec<3, bool> operator&&(vec<3, bool> const& v1, vec<3, bool> const& v2) {
		return vec<3, bool>(v1.x && v2.x, v1.y && v2.y, v1.z && v2.z);
	}

	PULSAR_CONSTEXPR vec<3, bool> operator||(vec<3, bool> const& v1, vec<3, bool> const& v2) {
		return vec<3, bool>(v1.x || v2.x, v1.y || v2.y, v1.z || v2.z);
	}
}