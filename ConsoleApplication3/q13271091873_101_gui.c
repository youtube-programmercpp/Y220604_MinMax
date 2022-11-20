// C言語で平均値・最大値・最小値を求めるサンプル (GUI版) Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "resource.h"

// -------------
// CUI版との違い
// -------------
// 入力したら即座に結果表示
// リセットボタンをクリックしてやり直し
// 入力値として 0 と負の値も有効

struct DialogData {
	int データの個数;
	int 合計値      ;
};
void リセット処理(HWND hDlg)
{
	struct DialogData* const p = (struct DialogData*)GetWindowLongPtrW(hDlg, DWLP_USER);
	p->データの個数 = 0;
	SetDlgItemTextA(hDlg, IDC_EDIT_Input, "");
	SetDlgItemTextA(hDlg, IDC_EDIT_Ave  , "");
	SetDlgItemTextA(hDlg, IDC_EDIT_Max  , "");
	SetDlgItemTextA(hDlg, IDC_EDIT_Min  , "");
}
void 入力処理(HWND hDlg)
{
	struct DialogData* const p = (struct DialogData*)GetWindowLongPtrW(hDlg, DWLP_USER);
	BOOL translated;
	const int 入力値 = GetDlgItemInt(hDlg, IDC_EDIT_Input, &translated, TRUE);
	if (translated) {
		SetDlgItemTextA(hDlg, IDC_EDIT_Input, "");
		if (p->データの個数++ == 0) {
			p->合計値 = 入力値;
			SetDlgItemInt(hDlg, IDC_EDIT_Ave, 入力値, TRUE);
			SetDlgItemInt(hDlg, IDC_EDIT_Max, 入力値, TRUE);
			SetDlgItemInt(hDlg, IDC_EDIT_Min, 入力値, TRUE);
		}
		else {
			p->合計値 += 入力値;
			char 平均値[64];
			sprintf(平均値, "%f", (double)p->合計値 / p->データの個数);
			SetDlgItemTextA(hDlg, IDC_EDIT_Ave, 平均値);
			if ((int)GetDlgItemInt(hDlg, IDC_EDIT_Max, NULL, TRUE) < 入力値) SetDlgItemInt(hDlg, IDC_EDIT_Max, 入力値, TRUE);
			if ((int)GetDlgItemInt(hDlg, IDC_EDIT_Min, NULL, TRUE) > 入力値) SetDlgItemInt(hDlg, IDC_EDIT_Min, 入力値, TRUE);
		}
	}
}
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_INITDIALOG:
		SetWindowLongPtrW(hDlg, DWLP_USER, lParam);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_BUTTON_Reset:
			リセット処理(hDlg);
			return TRUE;
		case IDOK:
			入力処理(hDlg);
			return TRUE;
		case IDCANCEL:
			EndDialog(hDlg, IDCANCEL);
			return TRUE;
		default:
			return FALSE;
		}
	default:
		return FALSE;
	}
}

int main()
{
	struct DialogData d = { 0 };
	(void)DialogBoxParamW(NULL, MAKEINTRESOURCEW(IDD_DIALOG_q13271091873_101_gui), NULL, DialogProc, (LPARAM)&d);
	return 0;
}
