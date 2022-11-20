// C言語サンプルプログラム選択用 main 関数 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#undef main
extern "C" int q13271091873_101_cui();
extern "C" int q13271091873_101_gui();
extern "C" int q10271260785_101();
extern "C" int q10271260785_102_size_t();
           int q10271260785_103();
		   int q10271260785_104_algorithm();
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fcntl.h>
#include <io.h>
#include <assert.h>

void 入力リダイレクト実施(_In_z_ char const* _FileName)
{
	(void)_close(_fileno(stdin));
	int fd;
	const int e = /*_Check_return_wat_ _ACRTIMP errno_t __cdecl */_sopen_s
	( /*_Out_  int       * _FileHandle    */&fd
	, /*_In_z_ char const* _FileName      */_FileName
	, /*_In_   int         _OpenFlag      */_O_RDONLY | _O_TEXT
	, /*_In_   int         _ShareFlag     */_SH_DENYWR
	, /*_In_   int         _PermissionMode*/_S_IREAD
	);
	if (e)
		throw std::system_error(std::make_error_code(std::errc(e)), (std::ostringstream() << __FILE__ "(" _CRT_STRINGIZE(__LINE__) "): In " __FUNCTION__ ", _sopen_s(_FileName = '" << _FileName << "') failed").str());
	else {
		assert(fd == _fileno(stdin));
	}
}
bool 入力リダイレクト確認(_In_z_ char const* _FileName)
{
	std::cout << _FileName << "から読み込みますか？\n"
		"1. 読み込む\n"
		"2. 読み込まない\n"
		;
	int n;
	if (std::cin >> n) {
		switch (n) {
		case 1:
			return true;
		case 2:
			return false;
		default:
			throw std::range_error("範囲外の値が入力されました。");
		}
	}
	else
		throw std::runtime_error("入力エラーが発生しました。");
}
int main()
{
	try {
		std::cout << "実行したいプログラムを選んでください。\n"
			"1. q13271091873_101_cui\n"
			"2. q13271091873_101_gui\n"
			"3. q10271260785_101\n"
			"4. q10271260785_102_size_t\n"
			"5. q10271260785_103\n"
			"6. q10271260785_104_algorithm\n"
			;
		int n;
		if (std::cin >> n) {
			static const char q10271260785_stdin_txt[] = "q10271260785_stdin.txt";
			switch (n) {
			case 1: return q13271091873_101_cui();
			case 2: return q13271091873_101_gui();
			case 3: if (入力リダイレクト確認(q10271260785_stdin_txt)) 入力リダイレクト実施(q10271260785_stdin_txt); return q10271260785_101();
			case 4: if (入力リダイレクト確認(q10271260785_stdin_txt)) 入力リダイレクト実施(q10271260785_stdin_txt); return q10271260785_102_size_t();
			case 5: if (入力リダイレクト確認(q10271260785_stdin_txt)) 入力リダイレクト実施(q10271260785_stdin_txt); return q10271260785_103();
			case 6: if (入力リダイレクト確認(q10271260785_stdin_txt)) 入力リダイレクト実施(q10271260785_stdin_txt); return q10271260785_104_algorithm();
			default:
				throw std::range_error("範囲外の値が入力されました。"); 
			}
		}
		else
			throw std::runtime_error("入力エラーが発生しました。");
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
