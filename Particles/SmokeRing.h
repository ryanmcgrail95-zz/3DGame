// SmokeRing.h

#ifndef SMOKERING_H
#define SMOKERING_H

#include "../Graphics/GraphicsOGL.h"
#include "Particle.h"

class SmokeRing : public Particle {
	public:
		SmokeRing(float,float,float,float,float,int);
		void update(GraphicsOGL*, float);
		void draw(GraphicsOGL*, float);

	private:
		float startSize;
		float endSize;
		float curSize;
		float addAmt;
		int numSteps;
		int totSteps;
};

#endif
