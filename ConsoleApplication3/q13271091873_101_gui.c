// C����ŕ��ϒl�E�ő�l�E�ŏ��l�����߂�T���v�� (GUI��) Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "resource.h"

// -------------
// CUI�łƂ̈Ⴂ
// -------------
// ���͂����瑦���Ɍ��ʕ\��
// ���Z�b�g�{�^�����N���b�N���Ă�蒼��
// ���͒l�Ƃ��� 0 �ƕ��̒l���L��

struct DialogData {
	int �f�[�^�̌�;
	int ���v�l      ;
};
void ���Z�b�g����(HWND hDlg)
{
	struct DialogData* const p = (struct DialogData*)GetWindowLongPtrW(hDlg, DWLP_USER);
	p->�f�[�^�̌� = 0;
	SetDlgItemTextA(hDlg, IDC_EDIT_Input, "");
	SetDlgItemTextA(hDlg, IDC_EDIT_Ave  , "");
	SetDlgItemTextA(hDlg, IDC_EDIT_Max  , "");
	SetDlgItemTextA(hDlg, IDC_EDIT_Min  , "");
}
void ���͏���(HWND hDlg)
{
	struct DialogData* const p = (struct DialogData*)GetWindowLongPtrW(hDlg, DWLP_USER);
	BOOL translated;
	const int ���͒l = GetDlgItemInt(hDlg, IDC_EDIT_Input, &translated, TRUE);
	if (translated) {
		SetDlgItemTextA(hDlg, IDC_EDIT_Input, "");
		if (p->�f�[�^�̌�++ == 0) {
			p->���v�l = ���͒l;
			SetDlgItemInt(hDlg, IDC_EDIT_Ave, ���͒l, TRUE);
			SetDlgItemInt(hDlg, IDC_EDIT_Max, ���͒l, TRUE);
			SetDlgItemInt(hDlg, IDC_EDIT_Min, ���͒l, TRUE);
		}
		else {
			p->���v�l += ���͒l;
			char ���ϒl[64];
			sprintf(���ϒl, "%f", (double)p->���v�l / p->�f�[�^�̌�);
			SetDlgItemTextA(hDlg, IDC_EDIT_Ave, ���ϒl);
			if ((int)GetDlgItemInt(hDlg, IDC_EDIT_Max, NULL, TRUE) < ���͒l) SetDlgItemInt(hDlg, IDC_EDIT_Max, ���͒l, TRUE);
			if ((int)GetDlgItemInt(hDlg, IDC_EDIT_Min, NULL, TRUE) > ���͒l) SetDlgItemInt(hDlg, IDC_EDIT_Min, ���͒l, TRUE);
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
			���Z�b�g����(hDlg);
			return TRUE;
		case IDOK:
			���͏���(hDlg);
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
