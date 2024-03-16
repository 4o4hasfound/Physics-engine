#include "Physics/SphereCollider.hpp"

namespace Pulsar {
	SphereCollider::SphereCollider(Decimal radius, const Transform& transform) {
		m_transform = transform;
		m_data.Radius = radius;
		m_radius = radius;
		m_aabb = AABB(vec2(-radius * m_transform.scale + m_transform.position), vec2(radius * m_transform.scale + m_transform.position));
	}

	SphereCollider::~SphereCollider()
	{
	}

	CollisionPoint SphereCollider::TestCollision(Body* a, Body* b, const Collider* collider) const {
		switch (b->getShape()) {
		case Sphere:
			return this->SphereToSphereCollision(a, b, collider);
		default:
			return collider->TestCollision(b, a, this);
		}
	}

	CollisionPoint SphereCollider::SphereToSphereCollision(Body* a, Body* b, const Collider* collider) const {
		const vec2		posA	=	a->getPosition() + this->getTransform().position;
		const vec2		posB	=	b->getPosition() + collider->getTransform().position;
		const Decimal	radA	=	this->getData().Radius * this->getTransform().scale;
		const Decimal	radB	=	collider->getData().Radius * collider->getTransform().scale;
		const vec2		normal	=	posA - posB;
		
		const Decimal dist = distance(posA, posB);
		const vec2 Normal = length(normal) ? normalize(normal) : normal;
		return CollisionPoint{ posA + Normal * radA, posB - Normal * radB, Normal, dist, radA + radB - dist, dist < radA + radB};
	}
}