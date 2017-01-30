#include <windows.h>
#include <tchar.h>
#include <string>
#include "resources.h"

extern INT_PTR CALLBACK AbtDlgProc(HWND hwnd,
							UINT msg,
							WPARAM wParam,
							LPARAM lParam);

LRESULT CALLBACK WndProc(HWND hwnd,
						 UINT msg,
						 WPARAM wParam,
						 LPARAM lParam);

int CALLBACK WinMain(HINSTANCE hInstance,
					 HINSTANCE hPrevInstance,
					 LPSTR     lpCmdLine,
					 int       nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd = NULL;
	MSG msg;
	
	std::string wndClassName = "mainwnd";
	
	HICON hIcon = LoadIcon(GetModuleHandle(NULL),
						   MAKEINTRESOURCE(IDI_ICON));
	
	wc.cbSize        = sizeof(WNDCLASSEX);
	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc   = WndProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = hIcon;
	wc.hCursor       = LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MAINMENU);
	wc.lpszClassName = &wndClassName[0];
	wc.hIconSm       = hIcon;
	
	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL,
				   "Error registering window class!",
				   "Error",
				   MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	
	hwnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,
						  &wndClassName[0],
						  _TEXT("Generic Title"),
						  WS_OVERLAPPEDWINDOW,
						  CW_USEDEFAULT,
						  CW_USEDEFAULT,
						  800,
						  600,
						  NULL,
						  NULL,
						  hInstance,
						  NULL);
	if(hwnd == NULL)
	{
		MessageBox(NULL,
				   "Error creating window!",
				   "Error",
				   MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	
	ShowWindow(hwnd,nCmdShow);
	
	BOOL retVal;
	while((retVal = GetMessage(&msg,NULL,0,0)) != 0)
	{
		if(retVal == -1)
		{
			MessageBox(NULL,
					   "Error occured during message fetching",
					   "Error",
					   MB_OK | MB_ICONEXCLAMATION);
			return 0;
		}
		else
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd,
						 UINT msg,
						 WPARAM wParam,
						 LPARAM lParam)
{
	switch(msg)
	{
		case WM_CREATE:
		{
			RECT rect;
			
			const HWND hDesktop = GetDesktopWindow();
			
			GetWindowRect(hDesktop,&rect);
			//TODO: Find taskbar orientation+taskbar w+h
			
			SetWindowPos(hwnd, 
						 HWND_TOP,
						 rect.left,
						 rect.top,
						 rect.right,
						 rect.bottom,
						 SWP_SHOWWINDOW);
			break;
		}
		case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
				//Menu items
				case ID_ABOUT:
				{
					DialogBox(NULL,
							  MAKEINTRESOURCE(IDD_ABOUT),
							  hwnd,
							  AbtDlgProc);
					break;
				}
				case ID_CHOOSED:
				{
					break;
				}
				case ID_CREATED:
				{
					break;
				}
				case ID_EDITD:
				{
					break;
				}
			}
			break;
		}
		case WM_CLOSE:
		{
			if(MessageBox(hwnd,
						  "Do you really want to close the program?",
						  "Confirmation",
						  MB_YESNO | MB_ICONQUESTION) 
						  == IDYES)
			{
				DestroyWindow(hwnd);
			}
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
		default:
		{
			return DefWindowProc(hwnd,msg,wParam,lParam);
		}
	}
	return 0;
}
