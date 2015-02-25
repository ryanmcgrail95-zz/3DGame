// Heightmap.cpp


#include <iostream>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/glext.h>
#include "../Graphics/GraphicsOGL.h"
#include "../Primitives/Drawable.h"
#include <cmath>
#include "Heightmap.h"
using namespace std;

Heightmap :: Heightmap(float xS, float yS, float resolution) {
	xSize = xS;
	ySize = yS;

	scale = 1/resolution;

	xNum = xS*resolution, yNum = yS*resolution;

	heightGrid = new float*[yNum];

	for(int i = 0; i < yNum; i++) {
		heightGrid[i] = new float[xNum];

		for(int j = 0; j < xNum; j++)
			setHeight(i,j,i*j);
	}
}

//		Heightmap(float, float, int**);
//		Heightmap(float, float, float**);

float Heightmap :: getHeightIJ(int i, int j) {
	if(i < 0 || j < 0 || i >= yNum || j >= xNum)
		return -1;
	else
		return heightGrid[i][j];
}

float Heightmap :: getHeightXY(float x, float y) {

	//if(x <= 0 || y <= 0 || x > xSize-1 || y > ySize-1)
	//	return -1;
	

	float h1, h2, h3, h4;
	int jC, jF, iC, iF;


	//Get (i,j) Coordinates of (x,y) point
	float jP, iP;
	jP = x/scale;
	iP = y/scale;

	//Get (i,j) Coordinates of Corners
	jC = ceil(jP);
	jF = jC-1;
	iC = ceil(iP);
	iF = iC-1;

	//Get Distance Into Square from Left Corner
	float xP, yP;
	xP = (jP - jF);
	yP = (iP - iF);	


	// Get Heights at Four Corners
	h1 = getHeightIJ(iF,jF);
	h2 = getHeightIJ(iF,jC);
	h3 = getHeightIJ(iC,jF);
	h4 = getHeightIJ(iC,jC);


	// Return Weighted Average of Points
	return (1-xP)*(1-yP)*h1 + (xP)*(1-yP)*h2 + (1-xP)*(yP)*h3 + (xP)*(yP)*h4;
}

//void getNormal(float, float, float*);
//bool isFloor(float, float);
//bool isWall(float, float);
		
void Heightmap :: draw(GraphicsOGL* gl, float deltaTime) {
	Drawable :: draw(gl, deltaTime);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


	// Draw Heightmap as Triangle Strips
	for(float i = 0; i < yNum-1; i++) {
		glBegin(GL_TRIANGLE_STRIP);

		for(float j = 0; j < xNum; j++) {
			glTexCoord2d(j/xNum,i/yNum);
				glVertex3d(j*scale, i*scale, getHeightIJ(i,j));
			glTexCoord2d(j/xNum, (i+1)/yNum);
				glVertex3d(j*scale, (i+1)*scale, getHeightIJ(i+1,j));
		}

		glEnd();
	}
}

void Heightmap :: setHeight(int i, int j, float height) {
	heightGrid[i][j] = height;
}

//		void load(string);