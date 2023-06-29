#ifndef PULSAR_RECT_COLLIDER_INCLUDED
#define PULSAR_RECT_COLLIDER_INCLUDED

#include "setup.hpp"
#include "configuration.hpp"
#include "Physics/Collider.hpp"
#include "Physics/Body.hpp"
#include "Math/Vector.hpp"
#include "Math/Functions.hpp"
#include "Math/Functions.hpp"

namespace Pulsar {
	class RectCollider : public Collider {
	public:
		RectCollider() PULSAR_DEFAULT;
		RectCollider(vec2 const& tl, vec2 const& tr, vec2 const& bl, vec2 const& br, const Transform& transform = Transform(vec2(0.0), 1.0, 0.0));
		virtual CollisionPoint TestCollision(Body* a, Body* b, const Collider* collider) const override;
		CollisionPoint RectToRectCollision(Body* a, Body* b, const Collider* collider) const;
		CollisionPoint RectToSphereCollision(Body* a, Body* b, const Collider* collider) const;

		PULSAR_CONSTEXPR Decimal getWidth() const { return m_width; }
		PULSAR_CONSTEXPR Decimal getHeight() const { return m_height; }

	protected:
		Decimal m_width, m_height;
		vec2 m_tl, m_tr, m_bl, m_br;
	};
}


#endif