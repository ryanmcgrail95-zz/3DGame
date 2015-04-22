// Math2D.h


#ifndef MATH2D_H
#define MATH2D_H

#define PI 3.14159265


// BASIC
	float min(float,float);
	float max(float,float);
	float sqr(float);
	float sign(float);
	float contain(float, float, float);

// RANDOM
	float rnd();
	float rnd(float);
	float rnd(float,float);
	unsigned long getTime();


// GEOMETRIC
	float calcPtDis(float, float, float, float);
	float calcLineDis(float, float, float, float, float, float);


// TRIG
	float calcLenX(float, float);
	float calcLenY(float, float);
	float calcPtDir(float, float, float, float);
	float calcLineDir(float, float, float, float, float, float);
	float modf(float, float);


// MAGICAL!!
	float calcTurnToDir(float, float);
	float calcAngleDiff(float, float);

#endif
