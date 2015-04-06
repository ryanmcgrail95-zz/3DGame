// Tree.h


#ifndef TREE_H
#define TREE_H

#include "Branch.h"
#include "Environmental.h"
#include "../Graphics/GraphicsOGL.h"
#include "../Data/SortedList.h"

class Tree : public Environmental {
	public:
		Tree(float,float,float);
		virtual void update(GraphicsOGL*, float);
		virtual void draw(GraphicsOGL*, float);
		void destroy();
		void damage(float);

		static SortedList<Tree*> treeList;

		float getSize();

	protected:
		Branch* root;
		float size;
		float toSize;

		bool isGrowing;
		float growWobble;

		float fallXYDir;
		float fallZDir;
		float fallZVel;

		float damageShakeTimer;
};

#endif
