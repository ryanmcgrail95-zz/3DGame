// Texture.h


#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/glext.h>
#include "CImg.h"
#include "Image.h"
using namespace cimg_library;
using namespace std;

class Texture {
	public:
		Texture(const string&, bool, int, char**);
		
		int getWidth();
		int getHeight();

		void bind();
		void bind(GLenum);
		
	private:

		static int texNum;

		string fileName;

		GLuint m_textureObj;
		Image* image;
};

#endif
