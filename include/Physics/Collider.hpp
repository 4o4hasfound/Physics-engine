#ifndef PULSAR_COLLIDER_INCLUDED
#define PULSAR_COLLIDER_INCLUDED

#include "setup.hpp"
#include "configuration.hpp"
#include "Math/Vector.hpp"
#include "Math/Transform.hpp"
#include "Physics/AABB.hpp"

#include <functional>

namespace Pulsar {
	class Body;
	struct CollisionPoint {
		vec2 A;
		vec2 B;
		vec2 Normal;
		Decimal Depth;
		Decimal Delta;
		bool hasCollide;
	};

	class Collider {
	public:
		Collider(): m_aabb(vec4(0.0)) {

		};
		~Collider() {

		};

		PULSAR_CONSTEXPR const Transform& getTransform() const { return m_transform; }
		PULSAR_CONSTEXPR const AABB& getAABB() const { return m_aabb; }
		PULSAR_CONSTEXPR const ColliderData& getData() const { return m_data; }

		virtual CollisionPoint TestCollision(Body* a, Body* b, const Collider* collider) const = 0;
	protected:
		Transform m_transform;
		AABB m_aabb;

		ColliderData m_data;
	};
}


#endif