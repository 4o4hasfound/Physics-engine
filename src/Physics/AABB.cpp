#include "Physics/AABB.hpp"

namespace Pulsar {
	AABB::AABB(const vec4& rect) 
		: _aabb(rect.x, rect.y, rect.z, rect.w) {

	}

	AABB::AABB(const vec2& a, const vec2& b)
		: _aabb(std::min(a.x, b.x), std::min(a.y, b.y), std::abs(a.x - b.x), std::abs(a.y - b.y)) {

	}

	AABB::AABB(const vec2& a, const vec2& b, const vec2& c, const vec2& d) {
		const vec2		tl		= vec2(std::min({ a.x, b.x, c.x, d.x }), std::min({ a.y, b.y, c.y, d.x }));
		const vec2		br		= vec2(std::max({ a.x, b.x, c.x, d.x }), std::max({ a.y, b.y, c.y, d.x }));
		const Decimal	width	= br.x - tl.x;
		const Decimal	height	= br.y - tl.y;
		_aabb = vec4(tl, width, height);
	}

	bool AABB::intersect(const AABB& other) const {
		return getMaxX() > other.getMinX() && other.getMaxX() > getMinX() &&
			getMaxY() > other.getMinY() && other.getMaxY() > getMinY();
	}

	AABB AABB::merge(const AABB& other) const {
		if (!this->getWidth() || !this->getHeight()) {
			return other;
		}
		const vec2 tl = std::min(this->getTL(), other.getTL());
		const vec2 br = std::max(this->getBR(), other.getBR());
		return AABB(tl, br);
	}

	void AABB::Clear() {
		_aabb = vec4(0.0);
	}

	vec2 AABB::getPoint(const int32_t& a) const {
		switch (a) {
		case 0:
			return getTL();
		case 1:
			return getTR();
		case 2:	
			return getBL();
		case 3:
			return getBR();
		}
	}

	vec2 AABB::getPointAfterSplit(const int32_t& a) const {
		switch (a) {
		case 0:
			return getTL();
		case 1:
			return vec2(getMinX() + getWidth() / 2, getMinY());
		case 2:
			return vec2(getMinX(), getMinY() + getHeight() / 2);
		case 3:
			return vec2(getMinX() + getWidth() / 2, getMinY() + getHeight() / 2);
		}
	}

}