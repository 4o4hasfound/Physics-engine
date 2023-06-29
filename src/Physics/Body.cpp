#include "Physics/Body.hpp"

namespace Pulsar {
	Body::Body(const BodyDef* bodyDef, PhysicsWorld* world)
		: m_world(world), m_type(bodyDef->type), m_shape(bodyDef->shape)
		, m_bodyData(bodyDef->bodyData)
		, m_position(bodyDef->position), m_oldpos(bodyDef->position), m_acceleration(bodyDef->acceleration)
		, m_callback([](Body*){}) {

	}

	void Body::SolveCollision(Body* body) {
		for (Collider* a : this->m_colliders) {
			for (Collider* b : body->m_colliders) {
				const CollisionPoint result = a->TestCollision(this, body, b);
				if (result.hasCollide) {
					if (this->getType() != RidigBody && body->getType() == RidigBody) {
						body->m_position -= ToDecimal(result.Delta) * result.Normal;
					}
					else if (this->getType() == RidigBody && body->getType() != RidigBody) {
						this->m_position += ToDecimal(result.Delta) * result.Normal;
					}
					else if (this->getType() == RidigBody && body->getType() == RidigBody) {
						this->m_position += ToDecimal(0.5 * result.Delta) * result.Normal;
						body->m_position -= ToDecimal(0.5 * result.Delta) * result.Normal;
					}
					this->m_callback(body);
				}
			}
		}
	}

	void Body::UpdateAABB() {
		m_aabb.Clear();
		for (Collider* collider : m_colliders) {
			//print(m_position.x, m_position.y);
			//print(collider->getAABB().getMinX(), collider->getAABB().getMinY(), collider->getAABB().getMaxX(), collider->getAABB().getMaxY(), collider->getAABB().getWidth(), collider->getAABB().getHeight());
			m_aabb = m_aabb.merge(
				AABB(collider->getAABB().getTL() + m_position, collider->getAABB().getBR() + m_position)
			);
			//print(m_aabb.getMinX(), m_aabb.getMinY(), m_aabb.getMaxX(), m_aabb.getMaxY(), m_aabb.getWidth(), m_aabb.getHeight());
		}
	}

	int Body::addCollider(Collider* _collider) {
		m_colliders.push_back(_collider);

		m_aabb = m_aabb.merge(
			AABB(_collider->getAABB().getTL() + m_position, _collider->getAABB().getBR() + m_position)
		);

		return m_colliders.size() - 1;
	}

	Collider* Body::getCollider(int index) {
		return m_colliders[index];
	}

	void Body::removeCollider(int index) {
		m_colliders.erase(m_colliders.begin() + index);
	}

	void Body::addCallbcak(std::function<void(Body*)> callback) {
		m_callback = callback;
	}

	void Body::Accelerate(vec2 const& acceleration) {
		m_acceleration += acceleration;
	}

	void Body::Update(Decimal dt) {
		const vec2 velocity = m_position - m_oldpos;
		m_oldpos = m_position;
		m_position += velocity + m_acceleration * dt * dt;
		m_acceleration = vec2(0.0, 0.0);
	}
	
}
