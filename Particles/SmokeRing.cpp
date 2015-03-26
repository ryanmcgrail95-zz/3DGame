// SmokeRing.cpp


#include <iostream>
#include "../Graphics/GraphicsOGL.h"
#include "SmokeRing.h"
#include "Particle.h"
using namespace std;

SmokeRing :: SmokeRing(float nX,float nY,float nZ,float startS,float endS,int nTotSteps) : Particle(nX,nY,nZ) {
	startSize = curSize = startS;
	endSize = endS;

	numSteps = 0;
	totSteps = nTotSteps;

	addAmt = (endS-startS)/nTotSteps;

	cout << "SMOKERING" << endl;
}

void SmokeRing :: update(GraphicsOGL* gl, float deltaTime) {
	curSize += addAmt;
	numSteps++;

	if(curSize > endSize)
		destroy();
}
		
void SmokeRing :: draw(GraphicsOGL* gl, float deltaTime) {
	gl->draw3DCircle(x,y,z,curSize,10);
}
