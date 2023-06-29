#include "Physics/Link.hpp"

namespace Pulsar {
	Link::Link(Body* b1, Body* b2)
		: Obj1(b1), Obj2(b2), Distance(distance(b1->getPosition(), b2->getPosition())) {

	}
	Link::Link(Body* b1, Body* b2, Decimal dist) 
		: Obj1(b1), Obj2(b2), Distance(dist) {

	}

	void Link::Apply() {
		const vec2 axis = Obj1->getPosition() - Obj2->getPosition();
		const Decimal dist = length(axis);
		const vec2 normal = dist ? axis / dist: axis;
		const Decimal delta = Distance - dist;
		if (Obj1->getType() != RidigBody) {
			Obj2->setPosition(Obj2->getPosition() - normal * delta);
		}
		else if (Obj2->getType() != RidigBody) {
			Obj1->setPosition(Obj1->getPosition() + normal * delta);
		}
		else {
			Obj1->setPosition(Obj1->getPosition() + normal * delta * ToDecimal(0.5));
			Obj2->setPosition(Obj2->getPosition() - normal * delta * ToDecimal(0.5));
		}
	}
}