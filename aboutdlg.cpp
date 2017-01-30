#include <windows.h>

INT_PTR CALLBACK AbtDlgProc(HWND hwnd,
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
				case IDOK:
				{
					EndDialog(hwnd,IDOK);
					break;
				}
			}
			break;
		}
		default:
		{
			return FALSE;
		}
	}
	return TRUE;
}
