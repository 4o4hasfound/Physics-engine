#ifndef PULSAR_FUNCTIONS_INCLUDED
#define PULSAR_FUNCTIONS_INCLUDED

#include "setup.hpp"
#include "Math/vec_config.hpp"

#include <limits>
#include <assert.h>
#include <cmath>
#include <algorithm>

namespace Pulsar {

	// Dot product

	template<typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE T dot(T a, T b) {
		static_assert(std::numeric_limits<T>::is_iec559, "'dot' accepts only floating-point inputs");

		return a * b;
	}

	template<typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE T dot(vec<1, T> const& v1, vec<1, T> const& v2) {
		static_assert(std::numeric_limits<T>::is_iec559, "'dot' accepts only floating-point inputs");

		vec<1, T> tmp(v1 * v2);
		return tmp.x;
	}
	template<typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE T dot(vec<2, T> const& v1, vec<2, T> const& v2) {
		static_assert(std::numeric_limits<T>::is_iec559, "'dot' accepts only floating-point inputs");

		vec<2, T> tmp(v1 * v2);
		return tmp.x + tmp.y;
	}
	template<typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE T dot(vec<3, T> const& v1, vec<3, T> const& v2) {
		static_assert(std::numeric_limits<T>::is_iec559, "'dot' accepts only floating-point inputs");

		vec<3, T> tmp(v1 * v2);
		return tmp.x + tmp.y + tmp.z;
	}

	// Cross product

	template<typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE vec<3, T> cross(vec<3, T> const& v1, vec<3, T> const& v2) {
		static_assert(std::numeric_limits<T>::is_iec559, "'cross' accepts only floating-point inputs");

		return vec<3, T>(
			v1.y * v2.z - v2.y * v1.z,
			v1.z * v2.x - v2.z * v1.x,
			v1.x * v2.y - v2.x * v1.y);
	}
	// Length
	template<typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE T length(T x) {
		static_assert(std::numeric_limits<T>::is_iec559, "'length' accepts only floating-point inputs");

		return std::abs(x);
	}

	template<length_t L, typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE T length(vec<L, T> const& v) {
		static_assert(std::numeric_limits<T>::is_iec559, "'length' accepts only floating-point inputs");

		return std::sqrt(dot(v, v));
	}

	// Distance
	
	template<typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE T distance(T a, T b) {
		static_assert(std::numeric_limits<T>::is_iec559, "'distance' accepts only floating-point inputs");

		return length(a - b);
	}

	template<length_t L, typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE T distance(vec<L, T> const& v1, vec<L, T> const& v2) {
		static_assert(std::numeric_limits<T>::is_iec559, "'distance' accepts only floating-point inputs");

		return length(v1 - v2);
	}

	// Normalize

	template<length_t L, typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE vec<L, T> normalize(vec<L, T> const& v) {
		static_assert(std::numeric_limits<T>::is_iec559, "'normalize' accepts only floating-point inputs");

		return v * (static_cast<T>(1.0) / std::sqrt(dot(v, v)));
	}

	// Faceforward

	template<length_t L, typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE vec<L, T> faceforward(vec<L, T> const& N, vec<L, T> const& I, vec<L, T> const& Nref) {
		static_assert(std::numeric_limits<T>::is_iec559, "'faceforward' accepts only floating-point inputs");

		return dot(Nref, I) < static_cast<T>(0) ? N : -N;
	}

	// Reflect

	template<length_t L, typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE vec<L, T> reflect(vec<L, T> const& I, vec<L, T> const& N) {
		return I - N * dot(N, I) * static_cast<T>(2);
	}

	// Refract

	template<length_t L, typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE vec<L, T> refract(vec<L, T> const& I, vec<L, T> const& N, T eta) {
		T const dotVal(dot(N, I));
		T const k(static_cast<T>(1) - eta * eta * (static_cast<T>(1) - dotVal * dotVal));
		vec<L, T> const Result =
			(k >= static_cast<T>(0)) ? (eta * I - (eta * dotVal + std::sqrt(k)) * N) : vec<L, T>(0);
		return Result;
	}

	PULSAR_CONSTEXPR PULSAR_INLINE int gcd(int a, int b) {
		while (b > 0) {
			int t = a % b;
			a = b;
			b = t;
		}
		return a;
	}

	// radians
	template<typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE T radians(T degrees) {
		static_assert(std::numeric_limits<T>::is_iec559, "'radians' only accept floating-point input");
		return degrees * DEG_TO_RAD;
	}

	// degrees
	template<typename T>
	PULSAR_CONSTEXPR PULSAR_INLINE T degrees(T radians) {
		static_assert(std::numeric_limits<T>::is_iec559, "'degrees' only accept floating-point input");
		return radians * RAD_TO_DEG;
	}

	// Rotate
	template<typename T, typename U>
	PULSAR_INLINE vec<2, T> rotate(vec<2, T> v, vec<2, T> const& center, U radian) {
		U s = std::sin(radian);
		U c = std::cos(radian);

		v.x -= center.x;
		v.y -= center.y;

		U xnew = v.x * c - v.y * s;
		U ynew = v.x * s + v.y * c;

		v.x = xnew + center.x;
		v.y = ynew + center.y;

		return v;
	}

	// Min and Max funnction

	template<typename ... T>
	PULSAR_CONSTEXPR PULSAR_INLINE auto& min(const T& ... args) {
		return std::min({ std::ref(args)..., }).get();
	}
}


#endif