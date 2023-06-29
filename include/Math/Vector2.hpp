#ifndef PULSAR_VECTOR2_INCLUDED
#define PULSAR_VECTOR2_INCLUDED

#include "setup.hpp"
#include "Math/vec_config.hpp"

#include <assert.h>

namespace Pulsar {
	template<typename T>
	class vec<2, T> {
	public:
		/// Type traits
		using value_type = T;
		using type = vec<2, T>;
		using bool_type = vec<2, bool>;

		// Data
		union { T x, r, s; };
		union { T y, g, t; };

		// -- Component Access --

		// Component count
		static PULSAR_CONSTEXPR length_t length() { return 2; }

		PULSAR_CONSTEXPR T& operator[](length_t i);
		PULSAR_CONSTEXPR T const& operator[](length_t i) const;

		// -- Implicit basic constructors --

		PULSAR_CONSTEXPR vec() PULSAR_DEFAULT;
		PULSAR_CONSTEXPR vec(vec<2, T> const& v) PULSAR_DEFAULT;

		// -- Explicit basic constructors --

		PULSAR_CONSTEXPR PULSAR_EXPLICIT vec(T scalar);
		PULSAR_CONSTEXPR vec(T x, T y);

		// -- Conversion constructors --

		template<typename U>
		PULSAR_CONSTEXPR PULSAR_EXPLICIT vec(vec<1, U> const& v);

		// Explicit conversions
		template<typename A, typename B>
		PULSAR_CONSTEXPR vec(A x, B y);
		template<typename A, typename B>
		PULSAR_CONSTEXPR vec(vec<1, A> const& x, B y);
		template<typename A, typename B>
		PULSAR_CONSTEXPR vec(A x, vec<1, B> const& y);
		template<typename A, typename B>
		PULSAR_CONSTEXPR vec(vec<1, A> const& x, vec<1, B> const& y);

		// -- Conversion vector constructors --

		// Explicit conversions
		template<typename U>
		PULSAR_CONSTEXPR PULSAR_EXPLICIT vec(vec<3, U> const& v);
		// Explicit conversions
		template<typename U>
		PULSAR_CONSTEXPR PULSAR_EXPLICIT vec(vec<4, U> const& v);

		// Explicit conversions
		template<typename U>
		PULSAR_CONSTEXPR PULSAR_EXPLICIT vec(vec<2, U> const& v);

		// -- Unary arithmetic operators --

		PULSAR_CONSTEXPR vec<2, T>& operator=(vec<2, T> const& v) PULSAR_DEFAULT;

		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator=(vec<2, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator+=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator+=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator+=(vec<2, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator-=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator-=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator-=(vec<2, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator*=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator*=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator*=(vec<2, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator/=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator/=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator/=(vec<2, U> const& v);

		// -- Increment and decrement operators --

		PULSAR_CONSTEXPR vec<2, T>& operator++();
		PULSAR_CONSTEXPR vec<2, T>& operator--();
		PULSAR_CONSTEXPR vec<2, T> operator++(int);
		PULSAR_CONSTEXPR vec<2, T> operator--(int);

		// -- Unary bit operators --

		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator%=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator%=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator%=(vec<2, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator&=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator&=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator&=(vec<2, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator|=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator|=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator|=(vec<2, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator^=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator^=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator^=(vec<2, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator<<=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator<<=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator<<=(vec<2, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator>>=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator>>=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<2, T>& operator>>=(vec<2, U> const& v);
	};

	// -- Unary operators --

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v);

	// -- Binary operators --

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v, U scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v1, vec<1, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator+(U scalar, vec<2, T> const& v);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator+(vec<1, U> const& v1, vec<2, T> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator+(vec<2, T> const& v1, vec<2, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v, U scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v1, vec<1, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator-(U scalar, vec<2, T> const& v);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator-(vec<1, U> const& v1, vec<2, T> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator-(vec<2, T> const& v1, vec<2, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator*(vec<2, T> const& v, U scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator*(vec<2, T> const& v1, vec<1, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator*(U scalar, vec<2, T> const& v);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator*(vec<1, U> const& v1, vec<2, T> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator*(vec<2, T> const& v1, vec<2, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator/(vec<2, T> const& v, U scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator/(vec<2, T> const& v1, vec<1, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator/(U scalar, vec<2, T> const& v);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator/(vec<1, U> const& v1, vec<2, T> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<2, T> operator/(vec<2, T> const& v1, vec<2, U> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator%(vec<2, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator%(vec<2, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator%(T scalar, vec<2, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator%(vec<1, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator%(vec<2, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator&(vec<2, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator&(vec<2, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator&(T scalar, vec<2, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator&(vec<1, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator&(vec<2, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator|(vec<2, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator|(vec<2, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator|(T scalar, vec<2, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator|(vec<1, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator|(vec<2, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator^(vec<2, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator^(vec<2, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator^(T scalar, vec<2, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator^(vec<1, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator^(vec<2, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator<<(vec<2, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator<<(vec<2, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator<<(T scalar, vec<2, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator<<(vec<1, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator<<(vec<2, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator>>(vec<2, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator>>(vec<2, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator>>(T scalar, vec<2, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator>>(vec<1, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator>>(vec<2, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<2, T> operator~(vec<2, T> const& v);

	// -- Boolean operators --

	template<typename T>
	PULSAR_CONSTEXPR bool operator==(vec<2, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator!=(vec<2, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator>(vec<2, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator<(vec<2, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator>=(vec<2, T> const& v1, vec<2, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator<=(vec<2, T> const& v1, vec<2, T> const& v2);

	PULSAR_CONSTEXPR vec<2, bool> operator&&(vec<2, bool> const& v1, vec<2, bool> const& v2);

	PULSAR_CONSTEXPR vec<2, bool> operator||(vec<2, bool> const& v1, vec<2, bool> const& v2);

}
#endif