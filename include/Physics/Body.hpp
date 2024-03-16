#ifndef PULSAR_BODY_INCLUDED
#define PULSAR_BODY_INCLUDED

#include "setup.hpp"
#include "configuration.hpp"
#include "Math/Transform.hpp"
#include "Math/Vector.hpp"
#include "Physics/Collider.hpp"
#include "Physics/AABB.hpp"
#include "Physics/PhysicsWorld.hpp"
#include "Debug/Print.hpp"
#include "Physics/Constraint.hpp"

#include <vector>
#include <algorithm>

namespace Pulsar {
	class PhysicsWorld;

	enum BodyType {
		StaticBody = 0,
		KinematicBody,
		RigidBody
	};

	struct BodyDef {
		BodyDef (Shapes _shape): shape(_shape) {
			position = vec2(0);
			rotation = vec2(0);
			scale = ToDecimal(0.0);
			mass = ToDecimal(1.0);
			acceleration = vec2(0);
			type = StaticBody;
		}

		BodyType type;
		Shapes shape;

		vec2 position;
		vec2 rotation;
		Decimal scale;

		vec2 acceleration;

		Decimal mass;

		BodyData bodyData;
	};

	class Body {
	public:
		int addCollider(Collider* _collider);
		Collider* getCollider(int index);
		void removeCollider(int index);

		void addCallbcak(std::function<void(Body*)> callback);

		void Accelerate(vec2 const& acceleration);
		void Update(Decimal dt);

		PULSAR_CONSTEXPR const AABB& getAABB() const {
			return m_aabb;
		}

		PULSAR_CONSTEXPR const BodyData getBodyData() const { 
			return m_bodyData; 
		}

		PULSAR_CONSTEXPR const Shapes getShape() const { 
			return m_shape; 
		}

		void setPosition(vec2 const& position) {
			m_position = position;
		}

		BodyData m_bodyData;
	private:
		friend class PhysicsWorld;
		friend class Collider;

		Body(const BodyDef* bodyDef, PhysicsWorld* world);
		~Body();

		void SolveCollision(Body* body);

		void UpdateAABB();

		PhysicsWorld* m_world;

		BodyType m_type;
		Shapes m_shape;

		vec2 m_position;
		vec2 m_oldpos;
		vec2 m_acceleration;

		bool m_awake;


		std::vector<Collider*> m_colliders;

		AABB m_aabb;

		std::function<void(Body*)> m_callback;
	public:
		PULSAR_CONSTEXPR BodyType getType() const {
			return m_type;
		}

		PULSAR_CONSTEXPR const vec2& getPosition() const {
			return m_position;
		}

		void setAwake(bool flag) {
			if (m_type == StaticBody) {
				return;
			}

			if (flag) {
				m_awake = true;
			}
			else {
				m_awake = false;
				m_acceleration = vec2(0.0);
			}
		}

		void setAcceleration(const vec2& v) {
			if (m_type == StaticBody) {
				return;
			}

			if (dot(v, v) > ToDecimal(0.0)) {
				setAwake(true);
			}

			m_acceleration = v;
		}

		PULSAR_CONSTEXPR const vec2& getAcceleration() const {
			return m_acceleration;
		}
	};
}



#endif