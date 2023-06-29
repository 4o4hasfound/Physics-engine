#include "Math/Vector1.hpp"

namespace Pulsar {

	template<typename T>
	PULSAR_CONSTEXPR T& vec<1, T>::operator[] (length_t i) {
		assert(i >= 0 && i < this->length());
		return x;
	}
	template<typename T>
	PULSAR_CONSTEXPR T const& vec<1, T>::operator[] (length_t i) const {
		assert(i >= 0 && i < this->length());
		return x;
	}

	// -- Implicit basic constructors --
	
#	if PULSAR_CONFIG_USE_DEFAULT_FUNCTION == PULSAR_DISABLE
		template<typename T>
		PULSAR_CONSTEXPR vec<1, T>::vec() : x(0) {

		}

		template<typename T>
		PULSAR_CONSTEXPR vec<1, T>::vec(vec<1, T> const& v) : x(v.x) {

		}
#	endif

	// -- Explicit basic constructors --

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T>::vec(T x) : x(x) {

	}

	// -- Conversion scalar constructors --

	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>::vec(vec<1, U> const& v) : x(static_cast<T>(v.x)) {

	}

	// -- Explicit conversions --
	template<typename T> template<typename X>
	PULSAR_CONSTEXPR vec<1, T>::vec(X _x) : x(static_cast<T>(_x)) {

	}

	// -- Unary arithmetic operators --

#	if PULSAR_CONFIG_USE_DEFAULT_FUNCTION == PULSAR_DISABLE
	template<typename T>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator=(vec<1, T> const& v) {
		this->x = v.x;
		return *this;
	}
#	endif

	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator=(vec<1, U> const& v) {
		this->x = static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator+=(U scalar) {
		this->x += static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator+=(vec<1, U> const& v) {
		this->x += static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator-=(U scalar) {
		this->x -= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator-=(vec<1, U> const& v) {
		this->x -= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator*=(U scalar) {
		this->x *= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator*=(vec<1, U> const& v) {
		this->x *= static_cast<T>(v.x);
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator/=(U scalar) {
		this->x /= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator/=(vec<1, U> const& v) {
		this->x /= static_cast<T>(v.x);
		return *this;
	}

	// -- Increment and decrement operators --

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator++() {
		++this->x;
		return *this;
	}
	template<typename T>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator--() {
		--this->x;
		return *this;
	}
	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> vec<1, T>::operator++(int) {
		vec<1, T> Result(*this);
		++* this;
		return Result;
	}
	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> vec<1, T>::operator--(int) {
		vec<1, T> Result(*this);
		--* this;
		return Result;
	}

	// -- Unary bit operators --

	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator%=(U scalar) {
		this->x %= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator%=(vec<1, U> const& v) {
		this->x %= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator&=(U scalar) {
		this->x &= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator&=(vec<1, U> const& v) {
		this->x &= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator|=(U scalar) {
		this->x |= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator|=(vec<1, U> const& v) {
		this->x |= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator^=(U scalar) {
		this->x ^= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator^=(vec<1, U> const& v) {
		this->x ^= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator<<=(U scalar) {
		this->x <<= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator<<=(vec<1, U> const& v) {
		this->x <<= static_cast<T>(v.x);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator>>=(U scalar) {
		this->x >>= static_cast<T>(scalar);
		return *this;
	}
	template<typename T> template<typename U>
	PULSAR_CONSTEXPR vec<1, T>& vec<1, T>::operator>>=(vec<1, U> const& v) {
		this->x >>= static_cast<T>(v.x);
		return *this;
	}

	// -- Unary operators --

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator+(vec<1, T> const& v) {
		return v;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator-(vec<1, T> const& v) {
		return vec<1, T>(0) -= v;
	}

	// -- Binary operators --

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator+(vec<1, T> const& v, U const& scalar) {
		return vec<1, T>(v) += scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator+(vec<1, T> const& v1, vec<1, U> const& v2) {
		return vec<1, T>(v1) += v2;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator+(T scalar, vec<1, U> const& v) {
		return vec<1, T>(v) += scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator-(vec<1, T> const& v, U const& scalar) {
		return vec<1, T>(v) -= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator-(vec<1, T> const& v1, vec<1, U> const& v2) {
		return vec<1, T>(v1) -= v2;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator-(T scalar, vec<1, U> const& v) {
		return vec<1, T>(v) -= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator*(vec<1, T> const& v, U const& scalar) {
		return vec<1, T>(v) *= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator*(vec<1, T> const& v1, vec<1, U> const& v2) {
		return vec<1, T>(v1) *= v2;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator*(T scalar, vec<1, U> const& v) {
		return vec<1, T>(v) *= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator/(vec<1, T> const& v, U const& scalar) {
		return vec<1, T>(v) /= scalar;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator/(vec<1, T> const& v1, vec<1, U> const& v2) {
		return vec<1, T>(v1) /= v2;
	}

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator/(T scalar, vec<1, U> const& v) {
		return vec<1, T>(v) /= scalar;
	}

	// -- Binary bit operators --

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator%(vec<1, T> const& v, T scalar) {
		return vec<1, T>(v) %= scalar;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator%(T scalar, vec<1, T> const& v) {
		return vec<1, T>(v) %= scalar;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator%(vec<1, T> const& v1, vec<1, T> const& v2) {
		return vec<1, T>(v1) %= v2;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator&(vec<1, T> const& v, T scalar) {
		return vec<1, T>(v) &= scalar;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator&(T scalar, vec<1, T> const& v) {
		return vec<1, T>(v) &= scalar;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator&(vec<1, T> const& v1, vec<1, T> const& v2) {
		return vec<1, T>(v1) &= v2;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator|(vec<1, T> const& v, T scalar) {
		return vec<1, T>(v) |= scalar;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator|(T scalar, vec<1, T> const& v) {
		return vec<1, T>(v) |= scalar;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator|(vec<1, T> const& v1, vec<1, T> const& v2) {
		return vec<1, T>(v1) |= v2;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator^(vec<1, T> const& v, T scalar) {
		return vec<1, T>(v) %= scalar;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator^(T scalar, vec<1, T> const& v) {
		return vec<1, T>(v) %= scalar;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator^(vec<1, T> const& v1, vec<1, T> const& v2) {
		return vec<1, T>(v1) %= v2;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator<<(vec<1, T> const& v, T scalar) {
		return vec<1, T>(v) <<= scalar;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator<<(T scalar, vec<1, T> const& v) {
		return vec<1, T>(v) <<= scalar;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator<<(vec<1, T> const& v1, vec<1, T> const& v2) {
		return vec<1, T>(v1) <<= v2;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator>>(vec<1, T> const& v, T scalar) {
		return vec<1, T>(v) >>= scalar;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator>>(T scalar, vec<1, T> const& v) {
		return vec<1, T>(v) >>= scalar;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator>>(vec<1, T> const& v1, vec<1, T> const& v2) {
		return vec<1, T>(v1) >>= v2;
	}

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator~(vec<1, T> const& v) {
		v.x = ~v.x;
		return v;
	}

	// -- Boolean operators --

	template<typename T>
	PULSAR_CONSTEXPR bool operator>(vec<1, T> const& v1, vec<1, T> const& v2) {
		return v1.x > v2.x;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator<(vec<1, T> const& v1, vec<1, T> const& v2) {
		return v1.x < v2.x;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator>=(vec<1, T> const& v1, vec<1, T> const& v2) {
		return v1.x >= v2.x;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator<=(vec<1, T> const& v1, vec<1, T> const& v2) {
		return this->x <= v2.x;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator==(vec<1, T> const& v1, vec<1, T> const& v2) {
		return v1.x == v2.x;
	}

	template<typename T>
	PULSAR_CONSTEXPR bool operator!=(vec<1, T> const& v1, vec<1, T> const& v2) {
		return v1.x != v2.x;
	}

	PULSAR_CONSTEXPR vec<1, bool> operator&&(vec<1, bool> const& v1, vec<1, bool> const& v2) {
		return vec<1, bool>(v1.x && v2.x);
	}

	PULSAR_CONSTEXPR vec<1, bool> operator||(vec<1, bool> const& v1, vec<1, bool> const& v2) {
		return vec<1, bool>(v1.x || v2.x);
	}


}