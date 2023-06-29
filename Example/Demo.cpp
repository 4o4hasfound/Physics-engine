#include "Physics/PhysicsWorld.hpp"
#include "Physics/Body.hpp"
#include "Physics/SphereCollider.hpp"
#include "Physics/Constraint.hpp"
#include "Physics/Link.hpp"

#include "Math/Vector.hpp"

#include "Debug/Print.hpp"

#include "setup.hpp"

#include <SFML/Graphics.hpp>

#include "imgui/imgui.h"

#include <vector>
#include <random>

using namespace Pulsar;

sf::RenderWindow window(sf::VideoMode(1000, 1000), "Physics engine");
sf::Clock deltaClock;
bool rpressed = false;
bool lpressed = false;
bool spacePressed = false;
bool escPressed = false;

PhysicsWorld world(vec2(0.0, 9.8));

std::vector<Body*> bodies; // Where the program stores all the bodies.

BodyDef settings(Sphere); // Uses only one BodyDef for all the bodies, because why not

void SetupWorld();
void HandleEvent();
void GenerateSphere();

int main() {
	srand(NULL);
	window.setFramerateLimit(60);

	// Add bodies and stuff
	SetupWorld();

	// A counter that keep track of the speed to generate the ball when hold right click
	int GenerateCount = 0; 

	const int subStep = 16;

	while (window.isOpen()) {
		HandleEvent();
		if (rpressed) {
			if (!GenerateCount) {
				GenerateCount = 2; // Reset the counter
				GenerateSphere();
			}
			else {
				--GenerateCount;
			}
		}
		if (lpressed) {
			if (world.getFreezed()) {
				world.UnFreeze();
				world.Step(0.001);
				world.Freeze();
			}
		}

		// -------------------- Start simulating steps --------------------
		window.clear(sf::Color::White);
		sf::Time dt = deltaClock.restart();
		Decimal dtSec = dt.asSeconds();
		dtSec /= subStep;
		for (int k = 0; k < subStep; ++k) {
			world.Step(dtSec);
		}

		// -------------------- Start rendering --------------------
		sf::CircleShape c;
		c.setFillColor(sf::Color::Black);
		for (auto& e : bodies) {
			c.setRadius(e->getBodyData().Radius);
			c.setPosition(e->getPosition().x - e->getBodyData().Radius, e->getPosition().y - e->getBodyData().Radius);
			window.draw(c);
		}

		window.setTitle(std::to_string(bodies.size()) + ": " + std::to_string(1.0 / (dtSec * subStep)));
		window.display();
	}

	return 0;
}

void SetupWorld() {
	// -------------------- Start constructing first line --------------------

	// Create a new static body for the origin point for the line.
	settings.type = StaticBody;
	settings.bodyData.Radius = 10.0;
	settings.position = vec2(100, 750);

	{
		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		bodies.push_back(body);
	}

	settings.type = RidigBody;

	for (int i = 0, len = 40; i < len; ++i) {
		if (i == len - 1)
			settings.type = StaticBody; // End point of the line, thus making it static

		Decimal radius = 10;
		settings.bodyData.Radius = radius;
		settings.position = vec2(100 + 20 * (i + 1), 750);

		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(radius);
		body->addCollider(collider);

		// Create a Link with the previous body
		world.AddConstraint(new Link(bodies.back(), body, radius + bodies.back()->getBodyData().Radius));

		bodies.push_back(body);
	}

	// -------------------- Start constructing second line --------------------

	{
		settings.type = StaticBody;
		settings.bodyData.Radius = 10.0;
		settings.position = vec2(400, 450);

		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		bodies.push_back(body);

		settings.type = RidigBody;
	}

	for (int i = 0, len = 21; i < len; ++i) {
		if (i == len - 1)
			settings.type = StaticBody; // End point of the line, thus making it static

		Decimal radius = 10;
		settings.bodyData.Radius = radius;
		settings.position = vec2(400 + 20 * (i + 1), 450);

		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(radius);
		body->addCollider(collider);

		// Create a Link with the previous body
		world.AddConstraint(new Link(bodies.back(), body, radius + bodies.back()->getBodyData().Radius));
		bodies.push_back(body);
	}

	settings.type = RidigBody;
	settings.acceleration = vec2(0.0, 1000000.0);
}

void HandleEvent() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Right) {
				rpressed = true;
			}
			if (event.mouseButton.button == sf::Mouse::Left) {
				lpressed = true;
			}
		}
		if (event.type == sf::Event::MouseButtonReleased) {
			if (event.mouseButton.button == sf::Mouse::Right) {
				rpressed = false;
			}
			if (event.mouseButton.button == sf::Mouse::Left) {
				lpressed = false;
			}
		}


		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Space) {
				if (!spacePressed) {
					spacePressed = true;
					if (world.getFreezed()) {
						world.UnFreeze();
						world.Step(0.01);
						world.Freeze();
					}
				}
			}

			if (event.key.code == sf::Keyboard::Escape) {
				if (!escPressed) {
					deltaClock.restart();
					escPressed = true;
					if (!world.getFreezed())
						world.Freeze();
					else
						world.UnFreeze();
				}
			}
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Space) {
				spacePressed = false;
			}
			if (event.key.code == sf::Keyboard::Escape) {
				escPressed = false;
			}
		}
	}
}

void GenerateSphere() {
	sf::Vector2i pos = sf::Mouse::getPosition(window);

	// Random position offset
	pos.x += rand() % 10;
	pos.y += rand() % 10;

	// Random radius
	Decimal radius = rand() % 20 + 5;

	settings.bodyData.Radius = radius;
	settings.position = vec2(pos.x, pos.y);

	Body* body = world.CreateBody(&settings);
	Collider* collider = new SphereCollider(radius);
	body->addCollider(collider);
	bodies.push_back(body);
}