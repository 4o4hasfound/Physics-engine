#ifndef PULSAR_AABB_INCLUDED
#define PULSAR_AABB_INCLUDED

#include "setup.hpp"
#include "Math/Vector.hpp"

#include "Debug/Print.hpp"

#include <algorithm>

namespace Pulsar {
	// Provides an AABB class
	class AABB {
	private:
	public:
		AABB(): _aabb(0.0) {

		}

		// Constructor with vec4.
		// x: X coordinate, y: Y coordinate, z: Width, w: Height
		AABB(const vec4& rect);

		// Constructor with 2 vec2, with the top left and the bottom right coordinate.
		AABB(const vec2& a, const vec2& b);

		// Constructor with 4 vec2, with the 4 points of a rectangle.
		AABB(const vec2& a, const vec2& b, const vec2& c, const vec2& d);

		// Compare operator
		bool operator==(const AABB& other) {
			return _aabb == other._aabb;
		}

		bool operator!=(const AABB& other) {
			return _aabb != other._aabb;
		}

		// Return if two AABB has intersected
		bool intersect(const AABB& other) const;

		// Return a new AABB that covers both this and other
		AABB merge(const AABB& other) const;

		// Clears an aabb.
		void Clear();

		// Return the width of the aabb.
		PULSAR_CONSTEXPR Decimal getWidth() const { return _aabb.z; }

		// Return the height of the aabb.
		PULSAR_CONSTEXPR Decimal getHeight() const { return _aabb.w; }

		// Return the Min X.
		PULSAR_CONSTEXPR Decimal getMinX() const { return _aabb.x; }

		// Return the Max X.
		PULSAR_CONSTEXPR Decimal getMaxX() const { return _aabb.x + getWidth(); }

		// Return the Min Y.
		PULSAR_CONSTEXPR Decimal getMinY() const { return _aabb.y; }

		// Return the Max Y.
		PULSAR_CONSTEXPR Decimal getMaxY() const { return _aabb.y + getHeight(); }

		// Return the Top Left coordinate of the aabb.
		PULSAR_CONSTEXPR vec2 getTL() const { return vec2(_aabb.x, _aabb.y); }

		// Return the Top Right coordinate of the aabb.
		PULSAR_CONSTEXPR vec2 getTR() const { return vec2(_aabb.x + _aabb.z, _aabb.y); }

		// Return the Bottom Left coordinate of the aabb.
		PULSAR_CONSTEXPR vec2 getBL() const { return vec2(_aabb.x, _aabb.y + _aabb.w); }

		// Return the Bottom Right coordinate of the aabb.
		PULSAR_CONSTEXPR vec2 getBR() const { return vec2(_aabb.x + _aabb.z, _aabb.y + _aabb.w); }

		// Return a point given an index (NODE_TL, NODE_TR, NODE_BL, NODE_BR).
		vec2 getPoint(const int32_t& a) const;

		// Return the point after split given an index (NODE_TL, NODE_TR, NODE_BL, NODE_BR).
		vec2 getPointAfterSplit(const int32_t& a) const;

	private:
		vec4 _aabb;
	};
}


#endif