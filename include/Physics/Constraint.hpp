#ifndef PULSAR_CONSTRAINT_INCLUDED
#define PULSAR_CONSTRAINT_INCLUDED

#include "setup.hpp"

namespace Pulsar {
	class Constraint {
	public:
		virtual void Apply() = 0;
	};
}


#endif