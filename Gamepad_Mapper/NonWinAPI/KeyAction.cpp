#include "KeyAction.h"
#include <Windows.h>
#include <iostream>

using namespace std;

KeyAction::KeyAction(string text, string triggerEvent, int typeMode = KeyAction::keyType) {
	this->text = text;
	this->typeMode = typeMode;
	setTriggerEvent(triggerEvent);
}

void KeyAction::execute() {
	switch (typeMode) {
	case KeyAction::keyType:
		cout << "Execute KeyAction: " << "keyType '" << text << "' " << getTriggerEvent() << endl;
		keybd_event(0x57, 0x11, KEYEVENTF_EXTENDEDKEY, 0);
		keybd_event(0x57, 0x11, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
		break;
	case KeyAction::keyDown:
		cout << "Execute KeyAction: " << "keyDown '" << text << "' " << getTriggerEvent() << endl;
		keybd_event(0x57, 0x11, KEYEVENTF_EXTENDEDKEY, 0);
		break;
	case KeyAction::keyUp:
		cout << "Execute KeyAction: " << "keyUp '" << text << "' " << getTriggerEvent() << endl;
		keybd_event(0x57, 0x11, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
		break;
	}
	
}