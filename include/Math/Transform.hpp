#ifndef	PULSAR_TRANSFORM_INCLUDED
#define PULSAR_TRANSFORM_INCLUDED

#include "setup.hpp"
#include "Math/Vector.hpp"

namespace Pulsar {
	struct Transform {
		Transform() :position(0.0), scale(0.0), rotation(0.0) {

		}
		Transform(vec2 const& _position, Decimal _scale, Decimal _rotation)
			: position(_position), scale(_scale), rotation(_rotation) {

		}
		vec2 position;
		Decimal scale;
		Decimal rotation;
	};
}


#endif