#ifndef PULSAR_VECTOR3_INCLUDED
#define PULSAR_VECTOR3_INCLUDED

#include "setup.hpp"
#include "Math/vec_config.hpp"

#include <assert.h>

namespace Pulsar {
	template<typename T>
	class vec<3, T> {
	public:
		/// Type traits
		using value_type = T;
		using type = vec<3, T>;
		using bool_type = vec<3, bool>;

		// Data
		union { T x, r, s; };
		union { T y, g, t; };
		union { T z, b, p; };

		// -- Component Access --

		// Component count
		static PULSAR_CONSTEXPR length_t length() { return 3; }

		PULSAR_CONSTEXPR T& operator[](length_t i);
		PULSAR_CONSTEXPR T const& operator[](length_t i) const;

		// -- Implicit basic constructors --

		PULSAR_CONSTEXPR vec() PULSAR_DEFAULT;
		PULSAR_CONSTEXPR vec(vec<3, T> const& v) PULSAR_DEFAULT;

		// -- Explicit basic constructors --

		PULSAR_CONSTEXPR explicit vec(T scalar);
		PULSAR_CONSTEXPR vec(T a, T b, T c);

		// -- Conversion scalar constructors --

		template<typename U>
		PULSAR_CONSTEXPR explicit vec(vec<1, U> const& v);

		/// Explicit conversions
		template<typename X, typename Y, typename Z>
		PULSAR_CONSTEXPR vec(X x, Y y, Z z);
		template<typename X, typename Y, typename Z>
		PULSAR_CONSTEXPR vec(vec<1, X> const& _x, Y _y, Z _z);
		template<typename X, typename Y, typename Z>
		PULSAR_CONSTEXPR vec(X _x, vec<1, Y> const& _y, Z _z);
		template<typename X, typename Y, typename Z>
		PULSAR_CONSTEXPR vec(vec<1, X> const& _x, vec<1, Y> const& _y, Z _z);
		template<typename X, typename Y, typename Z>
		PULSAR_CONSTEXPR vec(X _x, Y _y, vec<1, Z> const& _z);
		template<typename X, typename Y, typename Z>
		PULSAR_CONSTEXPR vec(vec<1, X> const& _x, Y _y, vec<1, Z> const& _z);
		template<typename X, typename Y, typename Z>
		PULSAR_CONSTEXPR vec(X _x, vec<1, Y> const& _y, vec<1, Z> const& _z);
		template<typename X, typename Y, typename Z>
		PULSAR_CONSTEXPR vec(vec<1, X> const& _x, vec<1, Y> const& _y, vec<1, Z> const& _z);

		// -- Conversion vector constructors --

		template<typename A, typename B>
		PULSAR_CONSTEXPR vec(vec<2, A> const& _xy, B _z);
		template<typename A, typename B>
		PULSAR_CONSTEXPR vec(vec<2, A> const& _xy, vec<1, B> const& _z);
		template<typename A, typename B>
		PULSAR_CONSTEXPR vec(A _x, vec<2, B> const& _yz);
		template<typename A, typename B>
		PULSAR_CONSTEXPR vec(vec<1, A> const& _x, vec<2, B> const& _yz);
		template<typename U>
		PULSAR_CONSTEXPR PULSAR_EXPLICIT vec(vec<4, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR PULSAR_EXPLICIT vec(vec<3, U> const& v);

		// -- Unary arithmetic operators --

		PULSAR_CONSTEXPR vec<3, T>& operator=(vec<3, T> const& v) PULSAR_DEFAULT;

		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator=(vec<3, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator+=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator+=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator+=(vec<3, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator-=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator-=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator-=(vec<3, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator*=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator*=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator*=(vec<3, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator/=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator/=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator/=(vec<3, U> const& v);

		// -- Increment and decrement operators --

		PULSAR_CONSTEXPR vec<3, T>& operator++();
		PULSAR_CONSTEXPR vec<3, T>& operator--();
		PULSAR_CONSTEXPR vec<3, T> operator++(int);
		PULSAR_CONSTEXPR vec<3, T> operator--(int);

		// -- Unary bit operators --

		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator%=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator%=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator%=(vec<3, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator&=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator&=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator&=(vec<3, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator|=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator|=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator|=(vec<3, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator^=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator^=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator^=(vec<3, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator<<=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator<<=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator<<=(vec<3, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator>>=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator>>=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<3, T>& operator>>=(vec<3, U> const& v);
	};

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v);

	// -- Binary operators --

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v, U scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v, vec<1, U> const& scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator+(U scalar, vec<3, T> const& v);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator+(vec<1, U> const& v1, vec<3, T> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator+(vec<3, T> const& v1, vec<3, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v, U scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v, vec<1, U> const& scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator-(U scalar, vec<3, T> const& v);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator-(vec<1, U> const& v1, vec<3, T> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator-(vec<3, T> const& v1, vec<3, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v, U scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v, vec<1, U> const& scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator*(U scalar, vec<3, T> const& v);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator*(vec<1, U> const& v1, vec<3, T> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator*(vec<3, T> const& v1, vec<3, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v, U scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v, vec<1, U> const& scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator/(U scalar, vec<3, T> const& v);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator/(vec<1, U> const& v1, vec<3, T> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<3, T> operator/(vec<3, T> const& v1, vec<3, U> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator%(vec<3, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator%(vec<3, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator%(T scalar, vec<3, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator%(vec<1, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator%(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator&(vec<3, T> const& v1, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator&(vec<3, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator&(T scalar, vec<3, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator&(vec<1, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator&(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator|(vec<3, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator|(vec<3, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator|(T scalar, vec<3, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator|(vec<1, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator|(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator^(vec<3, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator^(vec<3, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator^(T scalar, vec<3, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator^(vec<1, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator^(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator<<(vec<3, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator<<(vec<3, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator<<(T scalar, vec<3, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator<<(vec<1, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator<<(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator>>(vec<3, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator>>(vec<3, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator>>(T scalar, vec<3, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator>>(vec<1, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator>>(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<3, T> operator~(vec<3, T> const& v);

	// -- Boolean operators --

	template<typename T>
	PULSAR_CONSTEXPR bool operator>(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator<(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator>=(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator<=(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator==(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator!=(vec<3, T> const& v1, vec<3, T> const& v2);

	PULSAR_CONSTEXPR vec<3, bool> operator&&(vec<3, bool> const& v1, vec<3, bool> const& v2);

	PULSAR_CONSTEXPR vec<3, bool> operator||(vec<3, bool> const& v1, vec<3, bool> const& v2);
}

#endif