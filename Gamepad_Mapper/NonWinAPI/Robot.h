#ifndef ROBOT_H
#define ROBOT_H

#include "Gamepad.h"
#include "Action.h"
#include "TypeAction.h"
#include "tinyxml2.h"
#include <map>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Robot {
private:
	// config-data
	Gamepad gamepad;
	map<int, vector<unique_ptr<Action>>> actionMap;
	unique_ptr<Action> makeAction(tinyxml2::XMLElement* actionTypeElement, string triggerEvent);
	void addAction(int keyCode, unique_ptr<Action> action);
	void triggerActions(vector<unique_ptr<Action>>& actions, string triggerEvent);
public:
	Robot(int gamepadNumber = 0);
	void process();
};
#endif