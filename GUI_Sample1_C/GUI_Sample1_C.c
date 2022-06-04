#include <Windows.h>
#include "resource.h"

void EnterValue(HWND hDlg)
{
	BOOL bTranslated;
	const int value = GetDlgItemInt(hDlg, IDC_EDIT_Value, &bTranslated, TRUE);
	if (bTranslated) {
		const int max = GetDlgItemInt(hDlg, IDC_EDIT_Max, &bTranslated, TRUE);
		if (bTranslated) {
			//最大値を取得した
			if (max < value)
				SetDlgItemInt(hDlg, IDC_EDIT_Max, value, TRUE);
			else if ((int)GetDlgItemInt(hDlg, IDC_EDIT_Min, &bTranslated, TRUE) > value)
				SetDlgItemInt(hDlg, IDC_EDIT_Min, value, TRUE);
		}
		else {
			//最大値を取得出来なかった（設定されていないと判断…初回の入力であると判断）
			SetDlgItemInt(hDlg, IDC_EDIT_Max, value, TRUE);
			SetDlgItemInt(hDlg, IDC_EDIT_Min, value, TRUE);
		}
		SetDlgItemTextW(hDlg, IDC_EDIT_Value, L"");
	}
}
//Dialog Procedure
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_COMMAND:
		//下位 16 ビット
		switch (LOWORD(wParam)) {
		case IDCANCEL:
			EndDialog(hDlg, IDCANCEL);
			return TRUE;
		case IDC_BUTTON_Input:
			EnterValue(hDlg);
			return TRUE;
		case IDC_BUTTON_Reset:
			SetDlgItemTextW(hDlg, IDC_EDIT_Max, L"");
			SetDlgItemTextW(hDlg, IDC_EDIT_Min, L"");
			return TRUE;
		default:
			return FALSE;
		}
	default:
		return FALSE;
	}
}
//GUI プログラムの main 関数は wWinMain
int APIENTRY wWinMain
( _In_     HINSTANCE hInstance
, _In_opt_ HINSTANCE hPrevInstance
, _In_     LPWSTR    lpCmdLine
, _In_     int       nCmdShow
)
{
	DialogBoxW
	( /*hInstance   */hInstance
	, /*lpTemplate  */MAKEINTRESOURCEW(IDD_DIALOG_MinMax)
	, /*hWndParent  */NULL
	, /*lpDialogFunc*/DialogProc
	);
	return EXIT_SUCCESS;
}
