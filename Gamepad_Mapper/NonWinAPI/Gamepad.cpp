#include "Gamepad.h"
#include <iostream>

using namespace std;

Gamepad::Gamepad(int number) {
	this->number = number;
}

void Gamepad::update() {
	stateOld = stateNew;
	joyGetPosEx(number, &stateNew);
}

void Gamepad::printState() {
	cout << "dwButtonNumber: " << stateNew.dwButtonNumber << endl;
	cout << "dwButtons: " << stateNew.dwButtons << endl;
	cout << "dwFlags: " << stateNew.dwFlags << endl;
	cout << "dwPOV: " << stateNew.dwPOV << endl;
	cout << "dwRpos: " << stateNew.dwRpos << endl;
	cout << "dwUpos: " << stateNew.dwUpos << endl;
	cout << "dwVpos: " << stateNew.dwVpos << endl;
	cout << "dwXpos: " << stateNew.dwXpos << endl;
	cout << "dwYpos: " << stateNew.dwYpos << endl;
	cout << "dwZpos: " << stateNew.dwZpos << endl;
}

bool Gamepad::isDown(int keyCode) {
	if (stateNew.dwButtons == keyCode)
		return true;
	return false;
}

bool Gamepad::isPressed(int keyCode) {
	if (stateOld.dwButtons != keyCode && stateNew.dwButtons == keyCode)
		return true;
	return false;
}

bool Gamepad::isReleased(int keyCode) {
	if (stateOld.dwButtons == keyCode && stateNew.dwButtons != keyCode)
		return true;
	return false;
}