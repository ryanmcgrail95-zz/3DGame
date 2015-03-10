// GraphicsOGL.h

#ifndef GRAPHICSOGL_H
#define GRAPHICSOGL_H

#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/glext.h>
#include "Texture.h"
#include "Font.h"
#include "../IO/InputController.h"
#include "ShaderController.h"
#include "TextureController.h"
#include "FontController.h"
#include "Camera.h"
#include "../Environment/Heightmap.h"
#include "../Environment/Terrain.h"


class Camera;
class Heightmap;
class GraphicsOGL {
	public:
		GraphicsOGL(int, char* []);
		~GraphicsOGL();


		bool gluInvertMatrix(const float [16], float [16]);
		void idle();
		void display();

		InputController* getInputController();
		TextureController* getTextureController();

		//ACCESSOR
			int getScreenWidth();
			int getScreenHeight();
			

		//CAMERA
			float getCamDir();
			void setProjectionPrep(float,float,float,float,float,float);
		
		//DRAWING
			void setColor(int,int,int);
			void drawPoint(float,float);
			void drawLine(float,float,float,float);
			void drawRect(float,float,float,float);
			void fillRect(float,float,float,float);
			void drawCircle(float,float,float,int);
			void fillCircle(float,float,float,int);
			void drawPolygon(float,float,float,int,float);
			void fillPolygon(float,float,float,int,float);

		//3D DRAWING

			void draw3DWall(float,float,float,float,float,float, Texture*);
			void draw3DFloor(float,float,float,float,float, Texture*);
			void draw3DLine(float,float,float,float,float,float);

			void drawTexture(float, float, Texture*);
			void drawTextureScaled(float, float, float, float, Texture*);
			float drawChar(float, float, char);
			float drawCharScaled(float, float, float, float, char);
			void drawString(float, float, string);
			void drawStringScaled(float, float, float, float, string);

		//SHADERS
			void disableShaders();
			void enableShader(GLuint);
			void enableShader(string);
			void enableWaterShader();
			void enableSkyShader();
			void setCurrentTextureSize(int,int);

		//FONT
			void setFont(string);

		//HEIGHTMAP
			Heightmap* getHeightmap();

		//PROJECTION
			void setOrtho();
			void setPerspective();

		//TIME
			unsigned long getTime();

	private:
		void initialize3D(int, char* []);

		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;

		//FPS Variables
			unsigned long fpsStart, fpsEnd;
			unsigned long drawStart, drawEnd;
			int fps;

		//Heightmap Variables
			Terrain* terrain;
			InputController* inputController;
			TextureController* textureController;
			ShaderController* shaderController;
			FontController* fontController;

		//Shader Variables
			GLuint curProgram;
			float* resolution;
			float globalTime;

		//Font Variables
			Font2D* curFont;

		Camera* glCamera;
};

#endif
