// サンプルプログラム選択用 main 関数 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#undef main
#include "Dialog_Programs.h"
#include <CommCtrl.h>
#pragma comment(lib, "comctl32")

int main()
{
	InitCommonControls();
	Dialog_Programs{}.DialogBoxParamW(nullptr);
	return EXIT_SUCCESS;
}
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
