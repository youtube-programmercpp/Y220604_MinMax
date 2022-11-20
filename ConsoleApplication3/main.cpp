// サンプルプログラム選択用 main 関数 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#undef main
#include <Windows.h>
#include <iostream>
#include <stdexcept>
#include "ExportedFunction.h"
#include "RedirectStdinToFile.h"

bool 入力リダイレクト確認(_In_z_ char const* _FileName)
{
	std::cout << _FileName << "から読み込みますか？\n"
		"1. 読み込む\n"
		"2. 読み込まない\n"
		;
	for (int n;;) {
		std::cout << "> ";
		if (std::cin >> n) {
			switch (n) {
			case 1:
				return true;
			case 2:
				return false;
			default:
				std::cerr << "範囲外の値が入力されました。\n";
				continue;
			}
		}
		else
			throw std::runtime_error("入力エラーが発生しました。");
	}
}
int (*プログラム選択(const std::vector<ExportedFunction>& programs))()
{
	std::cout << "--------------\n"
		<< "実行するプログラムの番号を選んでください。\n"
		;
	for (const auto & r : programs)
		std::cout << &r - &programs.front() + 1 << ". " << (r.IsCpp() ? "C++" : "C  ") << ' ' << r.Name() << '\n';
	std::cout << "0. 終了\n";
	for (unsigned n;;) {
		std::cout << "> ";
		if (std::cin >> n) {
			if (n == 0)
				return nullptr;
			else if (1 <= n && n <= programs.size())
				return programs[n - 1].Address();
			else {
				std::cerr << "範囲外の値が入力されました。\n"; 
				continue;
			}
		}
		else
			throw std::runtime_error("入力エラーが発生しました。");
	}
}
extern "C" extern IMAGE_DOS_HEADER __ImageBase;
int main()
{
	try {
		const auto programs = ExportedFunction::MakeVector(__ImageBase);
		if (auto pfnMain = プログラム選択(programs)) {
			static const char q10271260785_stdin_txt[] = "q10271260785_stdin.txt";
			if (入力リダイレクト確認(q10271260785_stdin_txt))
				RedirectStdinToFile(q10271260785_stdin_txt);
			(void)(*pfnMain)();
			for (;;) {
				RedirectStdinToFile("con");
				std::cin.clear();
				if ((pfnMain = プログラム選択(programs)) == nullptr)
					break;
				else if (入力リダイレクト確認(q10271260785_stdin_txt))
					RedirectStdinToFile(q10271260785_stdin_txt);
				(void)(*pfnMain)();
			}
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
