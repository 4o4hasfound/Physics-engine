#ifndef PULSAR_VECTOR_ALL_INCLUDED
#define PULSAR_VECTOR_ALL_INCLUDED

#include "setup.hpp"
#include "Math/Vector1.inl"
#include "Math/Vector2.inl"
#include "Math/Vector3.inl"
#include "Math/Vector4.inl"
#include "Math/Functions.hpp"

namespace Pulsar {
	using vec1 = vec<1, Decimal>;
	using vec2 = vec<2, Decimal>;
	using vec3 = vec<3, Decimal>;
	using vec4 = vec<4, Decimal>;
	using fvec1 = vec<1, float>;
	using fvec2 = vec<2, float>;
	using fvec3 = vec<3, float>;
	using fvec4 = vec<4, float>;
	using dvec1 = vec<1, double>;
	using dvec2 = vec<2, double>;
	using dvec3 = vec<3, double>;
	using dvec4 = vec<4, double>;
	using bvec1 = vec<1, bool>;
	using bvec2 = vec<2, bool>;
	using bvec3 = vec<3, bool>;
	using bvec4 = vec<4, bool>;
	using svec1 = vec<1, int16_t>;
	using svec2 = vec<2, int16_t>;
	using svec3 = vec<3, int16_t>;
	using svec4 = vec<4, int16_t>;
	using ivec1 = vec<1, int32_t>;
	using ivec2 = vec<2, int32_t>;
	using ivec3 = vec<3, int32_t>;
	using ivec4 = vec<4, int32_t>;
	using llvec1 = vec<1, int64_t>;
	using llvec2 = vec<2, int64_t>;
	using llvec3 = vec<3, int64_t>;
	using llvec4 = vec<4, int64_t>;
}


#endif