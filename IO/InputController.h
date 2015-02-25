//InputController.h

#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include <map>
using namespace std;

class InputController {

	public:
		InputController();
		void updateMouse(int,int,int,int);
		void updatePassiveMouse(int,int);
		void updateKeyboard(unsigned char, int, int);
		void updateKeyboardUp(unsigned char, int, int);
		void updateKeyboardSpecial(int, int, int);

		bool getShift();
		float getWASDDir();
		bool getWASD(char);
		void setWASD(char, bool);

		int getMouseX();
		int getMouseY();

	private:
		static InputController* mainInp;
		bool* leftMouse;
		bool* middleMouse;
		bool* rightMouse;

		bool* wasdArray;

		int mouseX;
		int mouseY;

		bool isShiftDown;
};

#endif