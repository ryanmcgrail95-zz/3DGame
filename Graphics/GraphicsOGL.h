// GraphicsOGL.h

#ifndef GRAPHICSOGL_H
#define GRAPHICSOGL_H

#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/glext.h>
#include "Texture.h"
#include "Font.h"
#include "ShaderController.h"
#include "FontController.h"
#include "Camera.h"

class Camera;
class GraphicsOGL {
	public:
		GraphicsOGL(int, char* []);
		~GraphicsOGL();

		void idle();
		void display();

		//ACCESSOR
			int getScreenWidth();
			int getScreenHeight();
		
		//DRAWING
			void setColor(int,int,int);
			void drawPoint(float,float);
			void drawLine(float,float,float,float);
			void drawRect(float,float,float,float);
			void fillRect(float,float,float,float);
			void drawCircle(float,float,float,int);
			void fillCircle(float,float,float,int);

			void drawTexture(float, float, Texture*);
			void drawTextureScaled(float, float, float, float, Texture*);
			float drawChar(float, float, char);
			float drawCharScaled(float, float, float, float, char);
			void drawString(float, float, string);
			void drawStringScaled(float, float, float, float, string);

		//SHADERS
			void enableShader(GLuint);
			void enableShader(string);
			void setCurrentTextureSize(int,int);

		//FONT
			void setFont(string);

		//PROJECTION
			void setOrtho();
			void setPerspective();

	private:
		void initialize3D(int, char* []);

		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;

		//Shader Variables
			ShaderController* shaderController;
			GLuint curProgram;
			float* resolution;
			float globalTime;

		//Font Variables
			FontController* fontController;
			Font* curFont;

		Camera* glCamera;

		static Texture* tst;
};

#endif
