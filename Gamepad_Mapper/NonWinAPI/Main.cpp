#pragma comment(lib, "Winmm.lib")

#include <iostream>
#include <Windows.h>
#include <string>
#include "Robot.h"
#include "tinyxml2.h"

using namespace std;

int main() {
	Robot robot0(0);
	robot0.process();

	int i = 1000;
	while (1) {
		if (i >= 1000) {
			//system("cls");
			robot0.process();

			i = 0;
		}
		i++;
	}
	getchar();

	return 0;
}