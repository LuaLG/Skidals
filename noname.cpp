// noname.cpp : Defines the entry point for the console application.
//
//source created by Settings!!!
//Anybody skidding off of this will be sent to hell!!!
#include "stdafx.h"
#include <string>
#include <vector>
#include <Windows.h>
#include <iostream>
#include "Scanner.h"
#include "CommandCentral.h"
#define _CRT_SECURE_NO_WARNINGS
void ConsoleHacks()
{
	DWORD nothing;
	VirtualProtect((PVOID)&FreeConsole, 1, PAGE_EXECUTE_READWRITE, &nothing);
	*(BYTE*)(&FreeConsole) = 0xC3;
}

void Console(const char* title) {
	AllocConsole();
	SetConsoleTitleA(title);
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
	HWND ConsoleHandle = GetConsoleWindow();
}
int main()
{
	std::string cmd;
	Console("Skidals - Revision");
	ConsoleHacks();
	std::cout << "Scanning!!!" << std::endl;
	scan();
	std::cout << "Scanning Completed!" << std::endl;
	std::cout << "Welcome to Skidals - Revision, Enjoy!" << std::endl;
	std::cout << ">" << std::endl;
	std::cout << robloxluastate << std::endl;
	while (true)
	{
		try {
			std::cin >> cmd;
			CommandCentral(cmd);
		}
		catch (std::exception) {
			std::cout << "ERROR!!!" << std::endl;
		}
	}
    return 0;
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)main, 0, 0, 0);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}