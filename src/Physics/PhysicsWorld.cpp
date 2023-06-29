#include "Physics/PhysicsWorld.hpp"

namespace Pulsar {
	PhysicsWorld::PhysicsWorld(vec2 const& gravity) 
		: m_gravity(gravity) {

	}
	Body* PhysicsWorld::CreateBody(BodyDef* bodyDef) {
		Body* body = new Body(bodyDef, this);
		m_bodies.insert(body);
		return body;
	}
	void PhysicsWorld::AddConstraint(Constraint* constraint) {
		m_constraints.insert(constraint);
	}

	void PhysicsWorld::Step(Decimal dt) {
		if (m_freezed) 
			return;
		ApplyGravity(dt);
		ResolveCollision();
		ApplyConstraints(dt);
		Update(dt);
	}

	void PhysicsWorld::ApplyGravity(Decimal dt) {
		PULSAR_CONSTEXPR Decimal GravityScale = 100000;
		for (Body* body : m_bodies) {
			if (body->getType() != RidigBody) continue;
			body->Accelerate(m_gravity * GravityScale * dt);
		}
	}

	void PhysicsWorld::ApplyConstraints(Decimal dt) {
		for (Constraint* constraint : m_constraints) {
			constraint->Apply();
		}
	}

	void PhysicsWorld::ResolveCollision() {
		std::vector<Body*> tmp(m_bodies.begin(), m_bodies.end());
		std::sort(tmp.begin(), tmp.end(), [](Body* a, Body* b) {
			return a->getAABB().getTL() < b->getAABB().getTL();
			});
		for (int i = 0; i < tmp.size(); i++) {
			Body* obj1 = tmp[i];
			for (int j = i + 1; j < tmp.size(); ++j) {
				Body* obj2 = tmp[j];
				if (obj2->m_aabb.getMinX() >= obj1->m_aabb.getMaxX() && obj2->m_aabb.getMinY() >= obj1->m_aabb.getMaxY()) break;
				if (obj2->m_aabb.getMinY() >= obj1->m_aabb.getMaxY()) continue;
				obj1->SolveCollision(obj2);
			}
		}
	}

	void PhysicsWorld::Update(Decimal dt) {
		for (Body* body : m_bodies) {
			body->Update(dt);
			body->UpdateAABB();
		}
	}
}
