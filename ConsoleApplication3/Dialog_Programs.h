// ÉvÉçÉOÉâÉÄëIëâÊñ  Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#pragma once
#include "ExportedFunction.h"
#include <Windows.h>
#include <CommCtrl.h>
class Dialog_Programs
{
	std::vector<ExportedFunction> programs;

	INT_PTR Handle_WM_INITDIALOG(HWND hDlg) noexcept;
	INT_PTR Handle_WM_NOTIFY_LVN_GETDISPINFO(HWND hDlg, const NMLVDISPINFO& r) noexcept;
	INT_PTR Handle_WM_NOTIFY_LVN_DELETEITEM(HWND hDlg, const NMLISTVIEW& r) noexcept;
	INT_PTR Handle_WM_NOTIFY(HWND hDlg, const NMHDR& r) noexcept;
	INT_PTR Handle_WM_COMMAND_IDOK(HWND hDlg) noexcept;
	INT_PTR Handle_Message(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) noexcept;
public:
	INT_PTR DialogBoxParamW(_In_opt_ HWND hWndParent);
};

