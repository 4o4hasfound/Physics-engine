#include "Physics/ScreenBoarder.hpp"

Pulsar::ScreenBoarder::ScreenBoarder(int width, int height)
	: m_width(width), m_height(height) {
}

void Pulsar::ScreenBoarder::Apply(Body* body) {
	if (body->getPosition().x + body->getBodyData().Radius > m_width) {
		body->setPosition({
			m_width - body->getBodyData().Radius,
			body->getPosition().y
			});
	}
	else if (body->getPosition().x - body->getBodyData().Radius < 0) {
		body->setPosition({
			body->getBodyData().Radius,
			body->getPosition().y
			});
	}

	if (body->getPosition().y + body->getBodyData().Radius > m_height) {
		body->setPosition({
			body->getPosition().x,
			m_height - body->getBodyData().Radius
			});
	}
	else if (body->getPosition().y - body->getBodyData().Radius < 0) {
		body->setPosition({
			body->getPosition().x,
			body->getBodyData().Radius
			});
	}
}
