#include "Action.h"
#include <iostream>

using namespace std;

int Action::getDelay() {
	return delay;
}

string Action::getTriggerEvent() {
	return triggerEvent;
}

void Action::setTriggerEvent(string triggerEvent) {
	this->triggerEvent = triggerEvent;
}

void Action::execute() {
	cout << "Execute Action" << endl;
}