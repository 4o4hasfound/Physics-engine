#include "Physics/RectCollider.hpp"

namespace Pulsar {
	RectCollider::RectCollider(vec2 const& tl, vec2 const& tr, vec2 const& bl, vec2 const& br, const Transform& transform)
		: m_tl(tl), m_tr(tr), m_bl(bl), m_br(br) {
		m_transform = transform;
		m_aabb = AABB(tl, tr, bl, br);
		m_data.TopLeft = tl;
		m_data.TopRight = tr;
		m_data.BottomLeft = bl;
		m_data.BottomRight = br;
	}
	CollisionPoint RectCollider::TestCollision(Body* a, Body* b, const Collider* collider) const {
		switch (b->getShape()) {
		case Sphere:
			return this->RectToSphereCollision(a, b, collider);
		case Rectangle:
			return this->RectToRectCollision(a, b, collider);
		default:
			return collider->TestCollision(b, a, this);
		}
	}
	CollisionPoint RectCollider::RectToRectCollision(Body* a, Body* b, const Collider* collider) const {
		// TODO: Implement Rect To Rect collision handling

		return CollisionPoint{};
	}
	CollisionPoint RectCollider::RectToSphereCollision(Body* a, Body* b, const Collider* collider) const {
		// TODO: Implement Rect To Sphere collision handling

		return CollisionPoint{};
	}
}