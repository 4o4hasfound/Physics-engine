#ifndef PULSAR_LINK_CONSTRAINT_INCLUDED
#define PULSAR_LINK_CONSTRAINT_INCLUDED
#include <SFML/Graphics.hpp>

#include "setup.hpp"
#include "Physics/Constraint.hpp"
#include "Physics/Body.hpp"

namespace Pulsar {
	class Link : public Constraint {
	public:
		Link() = delete;
		Link(Body* b1, Body* b2);
		Link(Body* b1, Body* b2, Decimal dist);

		virtual void Apply() override;

		void draw(sf::RenderWindow& window) const;
	private:
		Body *Obj1, *Obj2;
		Decimal Distance;
	};
}



#endif