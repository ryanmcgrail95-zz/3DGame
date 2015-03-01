// Image.h


#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "CImg.h"
using namespace cimg_library;
using namespace std;

class Image {
	public:
		Image(string, int, char**);
		int getWidth();
		int getHeight();
		void* getData();
		void getPixelData();		

	private:
		CImg<unsigned char> image;
};

#endif


