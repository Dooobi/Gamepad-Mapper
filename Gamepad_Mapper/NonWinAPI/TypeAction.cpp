#include "TypeAction.h"
#include <iostream>

using namespace std;

TypeAction::TypeAction(string text, string triggerEvent) {
	this->text = text;
	setTriggerEvent(triggerEvent);
}

void TypeAction::execute() {
	cout << "Execute TypeAction: " << "Type '" << text << "' " << getTriggerEvent() << endl;
}