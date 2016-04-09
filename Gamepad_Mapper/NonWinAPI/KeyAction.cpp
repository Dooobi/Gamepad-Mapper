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
		KeyAction::typeStr(text.c_str());
		/*
		keybd_event(0x57, 0x11, KEYEVENTF_EXTENDEDKEY, 0);
		keybd_event(0x57, 0x11, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
		*/
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

void KeyAction::typeStr(const char *lpszString)
{
	char cChar;
	while ((cChar = *lpszString++)) // loops through chars
	{
		short vk = VkKeyScan(cChar); // keycode of char
		if ((vk >> 8) & 1){ keybd_event(VK_LSHIFT, 0, 0, 0); } // hold shift if necessary
		keybd_event((unsigned char)vk, 0, 0, 0); // key in
		keybd_event((unsigned char)vk, 0, KEYEVENTF_KEYUP, 0); // key out
		if ((vk >> 8) & 1){ keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); } // release shift if necessary
	}
}