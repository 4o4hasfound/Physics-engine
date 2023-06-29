#ifndef PULSAR_VEC_CONFIG_INCLUDED
#define PULSAR_VEC_CONFIG_INCLUDED

#include "setup.hpp"

namespace Pulsar {
	template<length_t L, typename T> class vec;

	// Template Aliases
#	if PULSAR_HAS_TEMPLATE_ALIASES
		template<typename T> using tvec1 = vec<1, T>;
		template<typename T> using tvec2 = vec<2, T>;
		template<typename T> using tvec3 = vec<3, T>;
#	endif
}

#endif