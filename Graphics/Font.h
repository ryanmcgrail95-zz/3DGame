// Font.h

#ifndef FONT_H
#define FONT_H

#include <string>
#include <map>
#include "Texture.h"
using namespace std;

class Font2D {
	public:
		Font2D(string,bool,int,char**);
		Texture* getChar(char);

	private:
		void addChar(char,string,int,char**);
		void addChar(char,int,char**);

		map<char, Texture*> fontMap;
		bool isCaseEnabled;
		string fontDir;
};

#endif
