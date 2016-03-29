#ifndef TYPEACTION_H
#define TYPEACTION_H

#include "Action.h"
#include <string>

using namespace std;

class TypeAction : public Action {
private:
	string text;
public:
	TypeAction(string text, string triggerEvent);
	void execute() override;
};
#endif