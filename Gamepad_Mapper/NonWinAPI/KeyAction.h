#ifndef KEYACTION_H
#define KEYACTION_H

#include "Action.h"
#include <string>

using namespace std;

class KeyAction : public Action {
private:
	string text;
	int typeMode;
public:
	static const int keyType = 0;
	static const int keyDown = 1;
	static const int keyUp = 2;
	KeyAction(string text, string triggerEvent, int typeMode);
	void execute() override;
};
#endif