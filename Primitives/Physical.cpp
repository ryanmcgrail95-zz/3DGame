// Physical.cpp


#include <deque>
#include "../Graphics/GraphicsOGL.h"
#include "Instantiable.h"
#include "Physical.h"
#include "../Functions/Math2D.h"
#include "../Environment/Heightmap.h"


Physical :: Physical(float myX, float myY, float myZ) : Instantiable() {
	xP = x = myX;
	yP = y = myY;
	zP = z = myZ;

	vel = 0;
	direction = 0;
}

void Physical :: update(GraphicsOGL* gl, float deltaTime) {
	Instantiable :: update(gl, deltaTime);

	updateMotion(deltaTime);
	collideHeightmap(gl->getHeightmap());
}
	
void Physical :: draw(GraphicsOGL* gl, float deltaTime) {
	Instantiable :: draw(gl, deltaTime);
}


//ACCESSOR/MUTATOR
	void Physical :: setZ(float newZ) {
		z = newZ;
	}

	float Physical :: getX() {
		return x;
	}
	float Physical :: getY() {
		return y;
	}
	float Physical :: getZ() {
		return z;
	}


bool Physical :: collideHeightmap(Heightmap* hm) {
	float h;
	h = hm->getHeightXY(x,y);

	if(h == -1)
		return false;
	else {
		z = h;
		return true;
	}
}

void Physical :: updateMotion(float deltaTime) {
	xP = x;
	yP = y;
	zP = z;
	
	x += deltaTime * calcLenX(vel, direction);
	y += deltaTime * calcLenY(vel, direction);
}
