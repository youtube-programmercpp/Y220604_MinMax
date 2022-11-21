// プログラム選択画面 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include "Dialog_Programs.h"
#include "RedirectStdinToFile.h"
#include "resource.h"
#include <stdexcept>
#include <iostream>

extern "C" extern IMAGE_DOS_HEADER  __ImageBase;

#ifdef UNICODE
std::wstring to_tstring(const std::string& lpMultiByteStr)
{
	if (const auto cbMultiByte = lpMultiByteStr.length()) {
		if (cbMultiByte > INT_MAX)
			throw std::range_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): the string is too long");
		else if (const auto cchWideChar = MultiByteToWideChar
		( /*_In_                                     UINT   CodePage      */CP_ACP
		, /*_In_                                     DWORD  dwFlags       */0
		, /*_In_NLS_string_(cbMultiByte)             LPCCH  lpMultiByteStr*/lpMultiByteStr.c_str()
		, /*_In_                                     int    cbMultiByte   */static_cast<int>(cbMultiByte)
		, /*_Out_writes_to_opt_(cchWideChar, return) LPWSTR lpWideCharStr */nullptr
		, /*_In_                                     int    cchWideChar   */0
		)) {
			std::wstring lpWideCharStr(cchWideChar, L'\0');
			lpWideCharStr.resize(MultiByteToWideChar
			( /*_In_                                     UINT   CodePage      */CP_ACP
			, /*_In_                                     DWORD  dwFlags       */0
			, /*_In_NLS_string_(cbMultiByte)             LPCCH  lpMultiByteStr*/lpMultiByteStr.c_str()
			, /*_In_                                     int    cbMultiByte   */static_cast<int>(cbMultiByte)
			, /*_Out_writes_to_opt_(cchWideChar, return) LPWSTR lpWideCharStr */&lpWideCharStr.front()
			, /*_In_                                     int    cchWideChar   */cchWideChar
			));
			return lpWideCharStr;
		}
		else
			return {};
	}
	else
		return {};
}
#else
#	define	to_tstring(lpMultiByteStr)	(lpMultiByteStr)
#endif


INT_PTR Dialog_Programs::Handle_WM_INITDIALOG(HWND hDlg) noexcept
{
	const auto hListView = GetDlgItem(hDlg, IDC_LIST1);
	LVCOLUMN col
	{ /*UINT   mask   ;*/LVCF_TEXT|LVCF_WIDTH
	, /*int    fmt    ;*/LVCFMT_LEFT
	, /*int    cx     ;*/180
	, /*LPTSTR pszText;*/const_cast<LPTSTR>(TEXT("Source"))
	};
	ListView_InsertColumn(hListView, 0, &col);
	col.pszText = const_cast<LPTSTR>(TEXT("Language"));
	col.cx = 60;
	ListView_InsertColumn(hListView, 1, &col);


	LVITEM m
	{ /*UINT   mask      */LVIF_TEXT
	, /*int    iItem     */0
	, /*int    iSubItem  */0
	, /*UINT   state     */0
	, /*UINT   stateMask */0
	, /*LPTSTR pszText   */LPSTR_TEXTCALLBACK
	, /*int    cchTextMax*/0
	, /*int    iImage    */0
	, /*LPARAM lParam    */0
	};
	programs = ExportedFunction::MakeVector(__ImageBase);
	for (const auto& r : programs) {
		m.mask |= LVIF_PARAM;
		m.lParam = LPARAM(&r);
		m.iItem = INT_MAX;
		m.iSubItem = 0;
		m.iItem = ListView_InsertItem(hListView, &m);
		m.mask &= ~LVIF_PARAM;
		++m.iSubItem;
		ListView_SetItem(hListView, &m);
	}
	return true;
}
INT_PTR Dialog_Programs::Handle_WM_NOTIFY_LVN_GETDISPINFO(HWND hDlg, const NMLVDISPINFO& r) noexcept
{
	if (const auto p = reinterpret_cast<ExportedFunction*>(r.item.lParam)) {
		switch (r.item.iSubItem) {
		case 0:
			(void)lstrcpyn(r.item.pszText, to_tstring(p->Name()).c_str(), r.item.cchTextMax);
			return true;
		case 1:
			(void)lstrcpyn(r.item.pszText, p->IsCpp() ? TEXT("C++") : TEXT("C"), r.item.cchTextMax);
			return true;
		default:
			return false;
		}
	}
	else
		return false;
}
INT_PTR Dialog_Programs::Handle_WM_NOTIFY_LVN_DELETEITEM(HWND hDlg, const NMLISTVIEW& r) noexcept
{
	//if (const auto p = reinterpret_cast<ExportedFunction*>(r.lParam))
	//	delete p;
	return true;
}
INT_PTR Dialog_Programs::Handle_WM_NOTIFY(HWND hDlg, const NMHDR& r) noexcept
{
	switch (r.idFrom) {
	case IDC_LIST1:
		switch (r.code) {
		case LVN_GETDISPINFO:
			return Handle_WM_NOTIFY_LVN_GETDISPINFO(hDlg, reinterpret_cast<const NMLVDISPINFO&>(r));
		case LVN_DELETEITEM:
			return Handle_WM_NOTIFY_LVN_DELETEITEM(hDlg, reinterpret_cast<const NMLISTVIEW&>(r));
		default:
			return false;
		}
	default:
		return false;
	}
}
#include <assert.h>
static void ExecProgram(const ExportedFunction* p, bool redirect)
{
	std::cout << "---------- " << p->Name() << " [" << (p->IsCpp() ? "C++" : "C") << "] 開始 ----------\n";
	static const char q10271260785_stdin_txt[] = "q10271260785_stdin.txt";
	if (redirect)
		RedirectStdinToFile(q10271260785_stdin_txt);
	assert(p != nullptr);
	(*p->Address())();
	std::cout << "---------- " << p->Name() << " [" << (p->IsCpp() ? "C++" : "C") << "] 終了 ----------\n";
}
INT_PTR Dialog_Programs::Handle_WM_COMMAND_IDOK(HWND hDlg) noexcept
{
	const auto hListView = GetDlgItem(hDlg, IDC_LIST1);
	LVITEM m
	{ /*UINT   mask      */LVIF_PARAM
	, /*int    iItem     */ListView_GetNextItem(hListView, -1, LVNI_SELECTED)
	, /*int    iSubItem  */0
	, /*UINT   state     */0
	, /*UINT   stateMask */0
	, /*LPTSTR pszText   */nullptr
	, /*int    cchTextMax*/0
	, /*int    iImage    */0
	, /*LPARAM lParam    */0
	};
	if (m.iItem != -1) {
		const auto redirect = IsDlgButtonChecked(hDlg, IDC_CHECK_RedirectStdin);
		(void)ListView_GetItem(hListView, &m);
		ExecProgram(reinterpret_cast<const ExportedFunction*>(m.lParam), redirect);
		while ((m.iItem = ListView_GetNextItem(hListView, m.iItem, LVNI_SELECTED)) != -1) {
			RedirectStdinToFile("con");
			std::cin.clear();
			(void)ListView_GetItem(hListView, &m);
			ExecProgram(reinterpret_cast<const ExportedFunction*>(m.lParam), redirect);
		}
	}
	return true;
}
INT_PTR Dialog_Programs::Handle_Message(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) noexcept
{
	switch (message) {
	case WM_NOTIFY:
		return Handle_WM_NOTIFY(hDlg, *LPNMHDR(lParam));
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDOK:
			return Handle_WM_COMMAND_IDOK(hDlg);
		case IDCANCEL:
			EndDialog(hDlg, IDOK);
			return true;
		default:
			return false;
		}
	default:
		return false;
	}
}
INT_PTR Dialog_Programs::DialogBoxParamW(_In_opt_ HWND hWndParent)
{
	return /*WINUSERAPI INT_PTR WINAPI*/::DialogBoxParamW
	( /*_In_opt_ HINSTANCE hInstance     */HINSTANCE(&__ImageBase)
	, /*_In_     LPCWSTR   lpTemplateName*/MAKEINTRESOURCEW(IDD_DIALOG_Programs)
	, /*_In_opt_ HWND      hWndParent    */hWndParent
	, /*_In_opt_ DLGPROC   lpDialogFunc  */[](HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) noexcept->INT_PTR
		{
			if (const auto pThis = reinterpret_cast<Dialog_Programs*>(GetWindowLongPtrW(hDlg, DWLP_USER)))
				return pThis->Handle_Message(hDlg, message, wParam, lParam);
			else if (message == WM_INITDIALOG) {
				SetWindowLongPtrW(hDlg, DWLP_USER, lParam);
				return reinterpret_cast<Dialog_Programs*>(lParam)->Handle_WM_INITDIALOG(hDlg);
			}
			else
				return false;
		}
	, /*_In_     LPARAM    dwInitParam   */LPARAM(this)
	);
}
