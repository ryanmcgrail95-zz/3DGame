// Font.cpp


#include <iostream>
#include <cctype>
#include <string>
#include <map>
#include "Texture.h"
#include "Font.h"
using namespace std;


Font :: Font(string fontName, bool ca) {
	isCaseEnabled = ca;

	fontDir = "Resources/Fonts/" + fontName + "/";
	char c;

	if(!isCaseEnabled) {
		for(int i = 0; i < 26; i++)
			addChar('a' + i);
		for(int i = 0; i < 10; i++)
			addChar('0' + i);

		addChar(',');
		addChar('!');
		addChar('.');
		addChar(';');
		addChar(':');
		addChar('-');
	}
}

Texture* Font :: getChar(char c) {
	if(isalpha(c)) {
		if(!isCaseEnabled)
			return fontMap[tolower(c)];
		else
			return fontMap[c];
	}
	else// if(isdigit(c))
		return fontMap[c];

	//return NULL;
}

void Font :: addChar(char c) {
	addChar(c, (fontDir + c) + ".png");
}

void Font :: addChar(char c, string fileName) {
	Texture* t = new Texture(fileName);
	t->loadFont();

	fontMap[c] = t;
}
