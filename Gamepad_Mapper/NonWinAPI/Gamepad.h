#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <Windows.h>

class Gamepad {
private:
	int number;
	JOYINFOEX stateOld;
	JOYINFOEX stateNew;
public:
	Gamepad(int number = 0);
	void update();
	void printState();
	bool isDown(int keyCode);
	bool isPressed(int keyCode);
	bool isReleased(int keyCode);

	static const int KeyCodeA;
	static const int KeyCodeB;
	static const int KeyCodeX;
	static const int KeyCodeY;
	static const int KeyCodeZ;
	static const int KeyCodeL;
	static const int KeyCodeR;
	static const int KeyCodeStart;

	static const int KeyCodeUp;
	static const int KeyCodeDown;
	static const int KeyCodeLeft;
	static const int KeyCodeRight;
	static const int KeyCodeUpRight;
	static const int KeyCodeUpLeft;
	static const int KeyCodeDownRight;
	static const int KeyCodeDownLeft;
};
#endif