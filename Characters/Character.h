// Character.h


#ifndef CHARACTER_H
#define CHARACTER_H

#include <deque>
#include "../Graphics/GraphicsOGL.h"
#include "../Primitives/Physical.h"
#include "../Graphics/Texture.h"

class GraphicsOGL;
class Character : public Physical {
	public:
		Character(float, float, float);
		virtual void update(GraphicsOGL*, float);
		virtual void draw(GraphicsOGL*, float);


	protected:
		void hop();

	private:
		void updateHop(float);

		virtual void land();
		
		bool isMoving;
		float hopZ;
		float hopZVel;
		float hopSc;

		static Texture* shTex;
};

#endif
