#ifndef PULSAR_SPHERE_COLLIDER_INCLUDED
#define PULSAR_SPHERE_COLLIDER_INCLUDED

#include "setup.hpp"
#include "configuration.hpp"
#include "Physics/Collider.hpp"
#include "Physics/Body.hpp"
#include "Math/Vector.hpp"
#include "Math/Functions.hpp"

namespace Pulsar {
	class SphereCollider : public Collider {
	public:
		SphereCollider() PULSAR_DEFAULT;
		SphereCollider(Decimal radius, const Transform& transform = Transform(vec2(0.0), 1.0, 0.0));
		~SphereCollider();
		virtual CollisionPoint TestCollision(Body* a, Body* b, const Collider* collider) const override;
		CollisionPoint SphereToSphereCollision(Body* a, Body* b, const Collider* collider) const;
		PULSAR_CONSTEXPR Decimal getRadius() { return m_radius; }
	protected:
		Decimal m_radius;
	};
}


#endif