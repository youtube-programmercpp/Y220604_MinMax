// C言語サンプルプログラム選択用 main 関数 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#undef main
extern "C" int q13271091873_101_cui();
extern "C" int q13271091873_101_gui();
#include <iostream>
int main()
{
	std::cout << "実行したいプログラムを選んでください。\n"
		"1. q13271091873_101_cui\n"
		"2. q13271091873_101_gui\n"
		;
	int n;
	if (std::cin >> n) {
		switch (n) {
		case 1: (void)q13271091873_101_cui(); break;
		case 2: (void)q13271091873_101_gui(); break;
		}
	}
}
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
