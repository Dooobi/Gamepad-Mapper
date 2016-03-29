#include "Robot.h"
#include <iostream>

using namespace std;

Robot::Robot(int gamepadNumber) {
	this->gamepad = Gamepad(gamepadNumber);

	// Initialize typeOnPress
	tinyxml2::XMLDocument configDoc;
	configDoc.LoadFile("config.xml");
	tinyxml2::XMLElement* actionElement = configDoc.FirstChildElement("root")->FirstChildElement("action");
	
	while (actionElement != NULL) {	// <<action button="X" keyCode="1" triggerEvent="onPressed">
		int keyCode = stoi(actionElement->Attribute("keyCode"));
		string triggerEvent = actionElement->Attribute("triggerEvent");

		tinyxml2::XMLElement* actionTypeElement = actionElement->FirstChildElement();
		while (actionTypeElement != NULL) {		// <type delay="500">x</type>
			addAction(keyCode, makeAction(actionTypeElement, triggerEvent));
			actionTypeElement = actionTypeElement->NextSiblingElement();
		}

		actionElement = actionElement->NextSiblingElement();
	}
}

unique_ptr<Action> Robot::makeAction(tinyxml2::XMLElement* actionTypeElement, string triggerEvent) {
	string type = actionTypeElement->Value();

	if (type == "keyType") {
		string text = actionTypeElement->FirstChild()->ToText()->Value();
		return unique_ptr<Action>(new KeyAction(text, triggerEvent, KeyAction::keyType));
	}
	else if (type == "keyDown") {
		string text = actionTypeElement->FirstChild()->ToText()->Value();
		return unique_ptr<Action>(new KeyAction(text, triggerEvent, KeyAction::keyDown));
	}
	else if (type == "keyUp") {
		string text = actionTypeElement->FirstChild()->ToText()->Value();
		return unique_ptr<Action>(new KeyAction(text, triggerEvent, KeyAction::keyUp));
	}

	return NULL;	// This will lead to errors
}

void Robot::process() {
	gamepad.update();
	
	for (map<int, vector<unique_ptr<Action>>>::iterator it = actionMap.begin(); it != actionMap.end(); it++) {
		if (gamepad.isPressed(it->first)) {
			triggerActions(it->second, "onPressed");
		}
		if (gamepad.isReleased(it->first)) {
			triggerActions(it->second, "onReleased");
		}
		if (gamepad.isDown(it->first)) {
			triggerActions(it->second, "onDown");
		}
	}
	
//	gamepad.printState();
}

void Robot::triggerActions(vector<unique_ptr<Action>>& actions, string triggerEvent) {
	for (int i = 0; i < actions.size(); i++) {
		if (actions[i]->getTriggerEvent() == triggerEvent) {
			actions[i]->execute();
		}
	}
}

void Robot::addAction(int keyCode, unique_ptr<Action> action) {
	if (actionMap.count(keyCode) == 0) {		// No Action(s) for this keyCode exist
		actionMap.insert(pair<int, vector<unique_ptr<Action>>>(keyCode, vector<unique_ptr<Action>>()));
	}

	actionMap[keyCode].push_back(move(action));
}