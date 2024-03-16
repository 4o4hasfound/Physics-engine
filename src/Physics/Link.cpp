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
		if (Obj1->getType() != RigidBody) {
			Obj2->setPosition(Obj2->getPosition() - normal * delta);
		}
		else if (Obj2->getType() != RigidBody) {
			Obj1->setPosition(Obj1->getPosition() + normal * delta);
		}
		else {
			Obj1->setPosition(Obj1->getPosition() + normal * delta * ToDecimal(0.5));
			Obj2->setPosition(Obj2->getPosition() - normal * delta * ToDecimal(0.5));
		}
	}
	void Link::draw(sf::RenderWindow& window) const {
		sf::VertexArray lines(sf::Lines, 2);
		lines[0].position = { Obj1->getPosition().x, Obj1->getPosition().y };
		lines[0].color = {
			static_cast<std::uint8_t>(Obj1->getBodyData().color.r),
			static_cast<std::uint8_t>(Obj1->getBodyData().color.g),
			static_cast<std::uint8_t>(Obj1->getBodyData().color.b)
		};
		lines[1].position = { Obj2->getPosition().x, Obj2->getPosition().y };
		lines[1].color = sf::Color{
			static_cast<std::uint8_t>(Obj2->getBodyData().color.r),
			static_cast<std::uint8_t>(Obj2->getBodyData().color.g),
			static_cast<std::uint8_t>(Obj2->getBodyData().color.b)
		};
		window.draw(lines);
	}
}