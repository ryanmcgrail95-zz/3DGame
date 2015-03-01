// FontController.cpp


#include <map>
#include <string>
#include "Font.h"
#include "FontController.h"
using namespace std;

FontController :: FontController(int argc, char** argv) {
	initialize(argc, argv);
}

Font2D* FontController :: getFont(string name) {
	return fontMap[name];
}		

void FontController :: initialize(int argc, char** argv) {
	addFont("8bit",false, argc, argv);
}

void FontController :: addFont(string name, bool hasCaps, int argc, char** argv) {
	fontMap[name] = new Font2D(name, hasCaps, argc, argv);
}
