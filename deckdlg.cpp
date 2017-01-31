#include <windows.h>
#include "resources.h"
INT_PTR CALLBACK DeckDlgProc(HWND hwnd,
							UINT msg,
							WPARAM wParam,
							LPARAM lParam)
{
	switch(msg)
	{
		case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
				case IDC_ADD:
				{
					break;
				}
				case IDC_REM:
				{
					break;
				}
				case IDC_CL:
				{
					break;
				}
				case IDC_SAVE:
				{
					break;
				}
				case IDC_DEL:
				{
					break;
				}
				case IDC_CARDS:
				{
					break;
				}
				case IDC_DECK:
				{
					break;
				}
				case IDC_DECKNAME:
				{
					break;
				}
				case IDC_NUM:
				{
					break;
				}
			}
			break;
		}
		case WM_CLOSE:
		{
			EndDialog(hwnd,WM_CLOSE);
			break;
		}
		default:
		{
			return FALSE;
		}
	}
	return TRUE;
}
