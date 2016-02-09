// Art.Stea1th (Stanislav Kuzmitch)
// Calculator IPv4, Mask, first-last IP, Broadcast etc.

#include "main.h"

// Entry point
int _tmain(int argc, _TCHAR *argv[], _TCHAR *envp[]) {
	
	while (true) {
		NetInfo netinfo;
		netinfo.show_to_console();

		netinfo.get_from_console();
		netinfo.calculate();
		netinfo.show_to_console();

		std::wcout << L"   ";
		system("pause");
	}
	return 0;
}