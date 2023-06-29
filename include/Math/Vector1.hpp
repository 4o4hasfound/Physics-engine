#ifndef PULSAR_VECTOR1_INCLUDED
#define PULSAR_VECTOR1_INCLUDED

#include "setup.hpp"
#include "Math/vec_config.hpp"

#include <assert.h>

namespace Pulsar {
	template<typename T>
	class vec<1, T> {
	public:
		/// Type traits
		using value_type = T;
		using type = vec<1, T>;
		using bool_type = vec<1, bool>;

		// Data
		union { T x, r, s; };

		// -- Component Access --

		// Component count
		static PULSAR_CONSTEXPR length_t length() { return 1; }

		PULSAR_CONSTEXPR T& operator[] (length_t i);
		PULSAR_CONSTEXPR T const& operator[] (length_t i) const;

		// -- Implicit basic constructors --

		PULSAR_CONSTEXPR vec() PULSAR_DEFAULT;
		PULSAR_CONSTEXPR vec(vec<1, T> const& v) PULSAR_DEFAULT;

		// -- Explicit basic constructors --

		PULSAR_CONSTEXPR explicit vec(T x);

		// -- Conversion scalar constructors --

		template<typename U>
		PULSAR_CONSTEXPR vec(vec<1, U> const& v);

		// -- Explicit conversions --
		template<typename X>
		PULSAR_CONSTEXPR vec(X _x);

		// -- Unary arithmetic operators --

		PULSAR_CONSTEXPR vec<1, T>& operator=(vec<1, T> const& v) PULSAR_DEFAULT;

		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator+=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator+=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator-=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator-=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator*=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator*=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator/=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator/=(vec<1, U> const& v);

		// -- Increment and decrement operators --

		PULSAR_CONSTEXPR vec<1, T>& operator++();
		PULSAR_CONSTEXPR vec<1, T>& operator--();
		PULSAR_CONSTEXPR vec<1, T> operator++(int);
		PULSAR_CONSTEXPR vec<1, T> operator--(int);

		// -- Unary bit operators --

		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator%=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator%=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator&=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator&=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator|=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator|=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator^=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator^=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator<<=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator<<=(vec<1, U> const& v);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator>>=(U scalar);
		template<typename U>
		PULSAR_CONSTEXPR vec<1, T>& operator>>=(vec<1, U> const& v);
	};

	// -- Unary operators --

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator+(vec<1, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator-(vec<1, T> const& v);

	// -- Binary operators --

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator+(vec<1, T> const& v, U const& scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator+(vec<1, T> const& v1, vec<1, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator+(T scalar, vec<1, U> const& v);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator+(vec<1, T> const& v1, vec<1, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator-(vec<1, T> const& v, U const& scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator-(vec<1, T> const& v1, vec<1, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator-(T scalar, vec<1, U> const& v);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator-(vec<1, T> const& v1, vec<1, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator*(vec<1, T> const& v, U const& scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator*(vec<1, T> const& v1, vec<1, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator*(T scalar, vec<1, U> const& v);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator*(vec<1, T> const& v1, vec<1, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator/(vec<1, T> const& v, U const& scalar);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator/(vec<1, T> const& v1, vec<1, U> const& v2);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator/(T scalar, vec<1, U> const& v);

	template<typename T, typename U>
	PULSAR_CONSTEXPR vec<1, T> operator/(vec<1, T> const& v1, vec<1, U> const& v2);

	// -- Binary bit operators --

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator%(vec<1, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator%(vec<1, T> const& v, vec<1, T> const& scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator%(T scalar, vec<1, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator%(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator&(vec<1, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator&(vec<1, T> const& v, vec<1, T> const& scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator&(T scalar, vec<1, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator&(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator|(vec<1, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator|(vec<1, T> const& v, vec<1, T> const& scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator|(T scalar, vec<1, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator|(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator^(vec<1, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator^(vec<1, T> const& v, vec<1, T> const& scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator^(T scalar, vec<1, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator^(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator<<(vec<1, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator<<(vec<1, T> const& v, vec<1, T> const& scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator<<(T scalar, vec<1, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator<<(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator>>(vec<1, T> const& v, T scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator>>(vec<1, T> const& v, vec<1, T> const& scalar);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator>>(T scalar, vec<1, T> const& v);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator>>(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR vec<1, T> operator~(vec<1, T> const& v);

	// -- Boolean operators --

	template<typename T>
	PULSAR_CONSTEXPR bool operator>(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator<(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator>=(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator<=(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator==(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	PULSAR_CONSTEXPR bool operator!=(vec<1, T> const& v1, vec<1, T> const& v2);

	PULSAR_CONSTEXPR vec<1, bool> operator&&(vec<1, bool> const& v1, vec<1, bool> const& v2);

	PULSAR_CONSTEXPR vec<1, bool> operator||(vec<1, bool> const& v1, vec<1, bool> const& v2);

}
#endif