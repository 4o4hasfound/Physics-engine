#include "Physics/PhysicsWorld.hpp"
#include "Physics/Body.hpp"
#include "Physics/SphereCollider.hpp"
#include "Physics/Constraint.hpp"
#include "Physics/Link.hpp"
#include "Physics/ScreenBoarder.hpp"

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
std::vector<Link*> links;

BodyDef settings(Sphere); // Uses only one BodyDef for all the bodies, because why not

void SetupWorld();
void HandleEvent();
void GenerateSphere();
void createFirstLine();
void createSecondLine();
void createFirstRect();
void createSecondRect();
void createTriangle();

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
		for (const auto& link : links) {
			link->draw(window);
		}

		window.setTitle(std::to_string(bodies.size()) + ": " + std::to_string(1.0 / (dtSec * subStep)));
		window.display();
	}

	return 0;
}

void SetupWorld() {
	world.AddConstraint(new ScreenBoarder(1000, 1000));
	createFirstLine();
	createSecondLine();
	createFirstRect();
	createSecondRect();
	createTriangle();

	settings.type = RigidBody;
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
	Decimal radius = rand() % 10 + 5;

	settings.bodyData.Radius = radius;
	settings.position = vec2(pos.x, pos.y);

	Body* body = world.CreateBody(&settings);
	Collider* collider = new SphereCollider(radius);
	body->addCollider(collider);
	bodies.push_back(body);
}

void createFirstLine() {
	settings.type = StaticBody;
	settings.bodyData.Radius = 10.0;
	settings.position = vec2(100, 750);

	{
		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		bodies.push_back(body);
	}

	settings.type = RigidBody;

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
}

void createSecondLine() {
	{
		settings.type = StaticBody;
		settings.bodyData.Radius = 10.0;
		settings.position = vec2(400, 450);

		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		bodies.push_back(body);

		settings.type = RigidBody;
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
}

void createFirstRect() {
	settings.type = StaticBody;
	settings.bodyData.Radius = 20.0;
	settings.position = vec2(200, 300);

	{
		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(20.0);
		body->addCollider(collider);
		bodies.push_back(body);
	}
	settings.type = RigidBody;
	settings.bodyData.Radius = 10.0;

	Body* first;
	{
		settings.position = vec2(400, 400);
		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		links.push_back(new Link(body, bodies.back()));
		world.AddConstraint(links.back());
		bodies.push_back(body);
		first = body;
	}
	{
		settings.position = vec2(400, 500);
		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		links.push_back(new Link(body, bodies.back()));
		world.AddConstraint(links.back());
		bodies.push_back(body);
	}
	{
		settings.position = vec2(500, 500);
		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		links.push_back(new Link(body, bodies.back()));
		world.AddConstraint(links.back());
		links.push_back(new Link(body, first));
		world.AddConstraint(links.back());
		bodies.push_back(body);
	}
	{
		settings.position = vec2(500, 400);
		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		links.push_back(new Link(body, bodies.back()));
		world.AddConstraint(links.back());
		links.push_back(new Link(body, first));
		world.AddConstraint(links.back());
		bodies.push_back(body);
	}
}

void createSecondRect() {
	settings.type = RigidBody;
	settings.bodyData.Radius = 10.0;

	Body* first;
	{
		settings.position = vec2(600, 200);
		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		bodies.push_back(body);
		first = body;
	}
	{
		settings.position = vec2(700, 200);
		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		links.push_back(new Link(body, bodies.back()));
		world.AddConstraint(links.back());
		bodies.push_back(body);
	}
	{
		settings.position = vec2(700, 300);
		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		links.push_back(new Link(body, bodies.back()));
		world.AddConstraint(links.back());
		links.push_back(new Link(body, first));
		world.AddConstraint(links.back());
		bodies.push_back(body);
	}
	{
		settings.position = vec2(600, 300);
		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		links.push_back(new Link(body, bodies.back()));
		world.AddConstraint(links.back());
		links.push_back(new Link(body, first));
		world.AddConstraint(links.back());
		bodies.push_back(body);
	}
}

void createTriangle() {
	settings.type = RigidBody;
	settings.bodyData.Radius = 10.0;

	Body* first;
	{
		settings.position = vec2(200, 400);
		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		bodies.push_back(body);
		first = body;
	}
	{
		settings.position = vec2(150, 486.6);
		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		links.push_back(new Link(body, bodies.back()));
		world.AddConstraint(links.back());
		bodies.push_back(body);
	}
	{
		settings.position = vec2(250, 486.6);
		Body* body = world.CreateBody(&settings);
		Collider* collider = new SphereCollider(10.0);
		body->addCollider(collider);
		links.push_back(new Link(body, bodies.back()));
		world.AddConstraint(links.back());
		links.push_back(new Link(body, first));
		world.AddConstraint(links.back());
		bodies.push_back(body);
	}
}
