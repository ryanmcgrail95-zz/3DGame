// Piece.h

#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "../Environmental.h"
#include "../../Primitives/Physical.h"
#include "../../Functions/mat4.h"

class Piece : public Environmental {
	
	public:
		Piece(int);
		Piece(int, float,float,float);
		~Piece();
		virtual void update(GraphicsOGL*, float);
		void draw(GraphicsOGL*, float, mat4);
		void draw(GraphicsOGL*, float);
		virtual bool collide(Physical*);
		virtual float calcFloorZ();
		Piece* clone();
		Piece* instantiate();
		Piece* instantiate(bool);
		bool checkOnScreen(GraphicsOGL* gl);
		void transformTranslation(float,float,float);
		void transformScale(float);
		void transformScale(float,float,float);
		void transformRotationX(float);
		void transformRotationY(float);
		void transformRotationZ(float);
		void damage(float);
		Piece* addPiece(Piece*,float,float,float);
		Piece* addPiece(Piece*,float,float,float,float,float,float);
		Piece* add3DWall(float,float,float,float,float,float);
		Piece* add3DFloor(float,float,float,float,float);
		Piece* add3DBlock(float,float,float,float,float,float);

		static int P_WALL;
		static int P_ELLIPSOID;
		static int P_BLOCK;
		static int P_FRUSTEM;
		static int P_GROUP;
		static vector<Piece*> pieceList;

	protected:
		
		Piece(bool,float, float, float);
		bool collide(Physical*,mat4);
		Piece* addPiece(Piece*);

		vector<Piece*> subpieces;	

		bool isInstance;
		mat4 modelMat;
		int type;
		float w, h;
};

#endif
