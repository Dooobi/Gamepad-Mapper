#pragma comment(lib, "Winmm.lib")

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance,        /* A handle to the current instance of the application. */
	HINSTANCE hPrevInstance,    /* A handle to the previous instance of the application. */
	LPSTR lpCmdLine,            /* The command line for the application, excluding the program name. */
	int nCmdShow)               /* Controls how the window is to be shown. */
{
		/* Call to the MessageBox function */
		MessageBox(NULL, "Hello, Windows API!", "Hello", MB_OK | MB_ICONINFORMATION);

		JOYINFOEX info;
		info.dwXpos = 0;

		joyGetPosEx(0, &info);

		cout << "X: " << info.dwXpos << endl;
		char string[10];
		sprintf_s(string, "%d", info.dwXpos);
		
		MessageBox(NULL, string, "X", MB_OK | MB_ICONINFORMATION);
		
		/*
		int i = 1000;
		while (1) {
			if (i >= 1000) {
				joyGetPosEx(0, &info);
				system("cls");
				cout << "X: " << info.dwXpos << endl;

				i = 0;
			}
			i++;
		}
		*/
		/* WinMain returns 0 if we exit before we enter message loop, more on that to come */
		return 0;
}
