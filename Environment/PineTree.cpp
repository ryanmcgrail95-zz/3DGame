// PineTree.cpp

#include <ctime>
#include <stdlib.h>
#include "../Graphics/GraphicsOGL.h"
#include "PineTree.h"
#include "Tree.h"
#include "../Graphics/Texture.h"
#include <chrono>
using namespace std::chrono;


unsigned long getTime() {

	nanoseconds ms = duration_cast< nanoseconds >(
 		high_resolution_clock::now().time_since_epoch()
	);

	return ms.count();
}


PineTree :: PineTree(float nX, float nY, float size, float colR, float colG, float colB) : Tree(nX,nY,size) {

	colRed = colR;
	colGreen = colG;
	colBlue = colB;
}

void PineTree :: update(GraphicsOGL* gl, float deltaT) {
	Tree :: update(gl, deltaT);
}

void PineTree :: draw(GraphicsOGL* gl, float deltaT) {

	int fidelity = 6;
	float R = 20, G = 255, B = 50;
	float r = 15, dZ, h = 30, uR, uDZ, uH;


	//DRAW SHADOW
	float xyDis, nX, nY, nZ, xRot, yRot, setupRot, xyRot;

	/*	gl->getHeightmap()->getFloorRotations(x,y,setupRot,xyRot);
	float grndZ = z;

	gl->setCulling(true);
	gl->setDepthTest(false);
		gl->transformTranslation(x,y,grndZ);
		gl->transformRotationZ(setupRot);
		gl->transformRotationX(xyRot);	

		gl->transformScale(size);	

		float s = 32;
		gl->draw3DFloor(-s,-s,s,s,0,gl->getTextureController()->getTexture("Shadow"));

		gl->transformClear();
	gl->setCulling(false);
	gl->setDepthTest(true);*/


	float aX = 0, aY = 0;
	if(damageShakeTimer > -1) {
		aX = 2.*(((getTime()*rand())%100)/100. - .5);
		aY = 2.*(((getTime()*rand())%100)/100. - .5);
	}
	

	gl->transformClear();
	gl->transformTranslation(x+aX,y+aY,z-5);
		gl->transformRotationZ(fallXYDir);
		gl->transformRotationY(fallZDir);
		gl->transformRotationZ(-fallXYDir);
	gl->transformScale(size);

	Texture* branchTex = gl->getTextureController()->getTexture("pineBranch");
	Texture* barkTex = gl->getTextureController()->getTexture("bark");

	
	/*float bR, bG, bB;
		bR = 255*(colGreen);
		bG = 255*(1-colGreen);
		bB = 255*(1-colGreen);

	gl->setColor(bR,bG,bB);*/

	gl->enableShader("pineBark");
	gl->draw3DPrism(0,0,0,4,30, fidelity, barkTex);
	gl->draw3DCone(0,0,0,5,30, fidelity, barkTex);

	gl->enableShader("pineBranch");

	if(damageShakeTimer > -1)
		gl->setColor(255*colRed, .2*255*colGreen, .2*255*colBlue);
	else
		gl->setColor(255*colRed, 255*colGreen, 255*colBlue);

	for (int i = 0; i < 3; i++) {
		r -= 2*i;
		dZ += 13+i;
		h -= 2*i;

		uR = r;
		uDZ = dZ;
		uH = h;
		for (int j = 0; j < 2; j++) {
			uDZ += 3;

			//float aR, aG, aB;
			//aR = rand();

			//gl->setColor(R+aR,G+aG,B+aB);
			
			gl->setShaderVariable("iDark", pow((3.-i)/3.,2.));

			gl->draw3DCone(0,0,uDZ,uR,uH, fidelity, branchTex);
			gl->draw3DCone(0,0,uDZ,uR*1.1,uH*.8, fidelity, branchTex);
		}
	}

	gl->setColor(255,255,255);
	gl->disableShaders();

	gl->transformClear();
}
