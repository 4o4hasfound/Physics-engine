#ifndef PULSAR_SCREEN_BOARDER_INCLUDED
#define PULSAR_SCREEN_BOARDER_INCLUDED

#include "setup.hpp"
#include "Physics/Constraint.hpp"
#include "Physics/Body.hpp"

namespace Pulsar {
	class ScreenBoarder : public UniversalConstraint {
	public:
		ScreenBoarder() = delete;
		ScreenBoarder(int width, int height);

		virtual void Apply(Body* body) override;
	private:
		int m_width, m_height;
	};
}

#endif