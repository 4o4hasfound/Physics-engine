#ifndef PULSAR_CONSTRAINT_INCLUDED
#define PULSAR_CONSTRAINT_INCLUDED

#include "setup.hpp"

namespace Pulsar {
	class Body;

	class Constraint {
	public:
		virtual void Apply() = 0;
	};
	class UniversalConstraint {
	public:
		virtual void Apply(Body* body) = 0;
	};
}


#endif