#ifndef ACTION_H
#define ACTION_H

#include <string>

using namespace std;

class Action {
private:
	string triggerEvent;
	int delay;
public:
	virtual void execute() = 0;
	int getDelay();
	string getTriggerEvent();
	void setTriggerEvent(string triggerEvent);
};
#endif