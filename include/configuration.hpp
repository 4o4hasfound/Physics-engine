#ifndef PULSAR_CONFIGURATION_INCLUDED
#define PULSAR_CONFIGURATION_INCLUDED

#include "setup.hpp"
#include "Math/Vector.hpp"

namespace Pulsar {

	// Edit this to have custom variable in your bodies
	struct BodyData {
		union {
			// SphereCollider
			Decimal Radius;
		};
		union {
			vec3 color = vec3(0.0);
		};
	};


	// Edit this to have custom variable in your colliders
	struct ColliderData {
		union {
			// SphereCollider
			Decimal Radius;
		};
	};

	// Edit this to add custom shapes
	enum Shapes {
		Sphere=0
	};
}


#endif