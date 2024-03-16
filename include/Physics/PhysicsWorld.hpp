#ifndef PULSAR_PHYSICS_WORLD_INCLUDED
#define PULSAR_PHYSICS_WORLD_INCLUDED

#include "setup.hpp"
#include "Physics/Constraint.hpp"
#include "Physics/Body.hpp"
#include "Physics/Collider.hpp"
#include "Container/FreeList.inl"
#include "Debug/Print.hpp"

#include <chrono>
#include <vector>
#include <algorithm>

namespace Pulsar {
	struct BodyDef;

	struct CollisionPointID {
		std::pair<int, int> ID;
		CollisionPoint collisionPoint;
	};
	
	class PhysicsWorld {
	public:
		PhysicsWorld() PULSAR_DEFAULT;

		PhysicsWorld(vec2 const& gravity);

		Body* CreateBody(BodyDef* bodyDef);

		void AddConstraint(Constraint* constraint);
		void AddConstraint(UniversalConstraint* constraint);

		void Step(Decimal dt);

		void Freeze() { m_freezed = true; }
		void UnFreeze() { m_freezed = false; }
		PULSAR_CONSTEXPR const bool getFreezed() const { return m_freezed; }
		
	private:
		friend class Body;
		bool m_freezed = false;
		FreeList<Body*> m_bodies;
		FreeList<Constraint*> m_constraints;
		FreeList<UniversalConstraint*> m_universalConstraints;

		vec2 m_gravity;

		void ApplyGravity(Decimal dt);
		void ApplyConstraints(Decimal dt);
		void ResolveCollision();
		void Update(Decimal dt);
	};
}

#endif