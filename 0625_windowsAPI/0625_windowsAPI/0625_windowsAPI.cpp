// 0625_windowsAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#define _CRT_SECURE_NO_WARNINGS 
#include "framework.h"
#include "0625_windowsAPI.h"
#include<commdlg.h>
#include <cstdio>
#pragma comment(lib,"msimg32.lib")
#define MAX_LOADSTRING 100


void Update();


// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY0625WINDOWSAPI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0625WINDOWSAPI));

    MSG msg;

    // 기본 메시지 루프입니다:
	/*
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }*/
	while (true)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			if (msg.message==WM_QUIT) 
			{
				break;
			}
			else 
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else 
		{
			Update();
		}
	}
    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0625WINDOWSAPI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY0625WINDOWSAPI);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

/*

문제
8방향 캐릭터 이미지를 이용해서
키누른 방향으로 애니메이션되는 캐릭터 이동하도록 프로그램을 작성

*/
void OutFromFile(TCHAR filename[], HWND hwnd) 
{
	FILE *fPtr;
	HDC hdc;
	int line;
	TCHAR buffer[500];
	line = 0;
	hdc = GetDC(hwnd);
#ifdef _UNICODE
	_tfopen_s(&fPtr, filename, _T("r,ccs=UNICODE"));
#else
	_tfopen_s(&fPtr, filename, _T("r"));
#endif // _UNICODE
	while (_fgetts(buffer, 100, fPtr) != NULL) 
	{
		if (buffer[_tcslen(buffer) - 1] == _T('\n'))
		{
			buffer[_tcslen(buffer) - 1] == NULL;
		}
		TextOut(hdc,0,line*20,buffer,_tcslen(buffer));
		line++;
	}
	fclose(fPtr);
	ReleaseDC(hwnd,hdc);
}


//>>:image --> 배열이나 리스트로 사용
//  : back Image
HBITMAP hBackImage;
BITMAP bitBack;
//  : transparent Image
HBITMAP hTransparentImage;
BITMAP bitTransparent;
// : animation 912 104
HBITMAP hAniImage;
BITMAP bitAni;
const int SPRITE_SIZE_X = 57;
const int SPRITE_SIZE_Y = 52;
POINT aniPos;

// : run
int RUN_FRAME_MAX = 0;
int RUN_FRAME_MIN = 0;
int curFrame = RUN_FRAME_MIN;

// : text
RECT rectView;
void DrawRectText(HDC hdc);

void CreateBitmap();
void DrawBitmap(HDC hdc, HWND hWnd);
void DeleteBitmap();

void UpdateFrame(HWND hWnd);
VOID CALLBACK AniProc(HWND hWnd,UINT uMsg,UINT idEvent,DWORD dwTime);

//-----추가
void CreateBitmap2();
void DrawBitmap2(HDC hdc, HWND hWnd);
void UpdateFrame2();
void DeleteBitmap2();
void defaultUpdateFrame();

void CreateBitmap()
{
	// >> : back image
	hBackImage = (HBITMAP) LoadImage(NULL, TEXT("images/수지.bmp"),
		IMAGE_BITMAP,0,0,LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hBackImage, sizeof(BITMAP), &bitBack);
	//>>:

	// >> : transparent Image
	hTransparentImage = (HBITMAP)LoadImage(NULL, TEXT("images/sigong.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hTransparentImage, sizeof(BITMAP), &bitTransparent);
	//<<:

	// >> : animation 
	hAniImage = (HBITMAP)LoadImage(NULL, TEXT("images/zero_run.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hAniImage, sizeof(BITMAP), &bitAni);
		//프레임 설정
	RUN_FRAME_MAX = bitAni.bmWidth / SPRITE_SIZE_X-1;
	RUN_FRAME_MIN = 2;
	curFrame = RUN_FRAME_MIN; //시작위치
	aniPos.x = 300;
	aniPos.y = 100;
	//<<:


}

void DrawBitmap(HDC hdc, HWND hWnd) 
{
	HDC hMemDC;
	HBITMAP hOldBitmap;
	int bx, by;
	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBackImage);
		bx = bitBack.bmWidth;
		by = bitBack.bmHeight;

		BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);
		SelectObject(hMemDC, hOldBitmap);

		DeleteDC(hMemDC);
	}

	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hTransparentImage);
		bx = bitTransparent.bmWidth;
		by = bitTransparent.bmHeight;

		//BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);
		BitBlt(hdc, 100, 200, bx, by, hMemDC, 0, 0, SRCCOPY);
		TransparentBlt(hdc, 200, 200, bx, by, hMemDC, 0, 0, bx, by,RGB(255,0,255));
		SelectObject(hMemDC, hOldBitmap);

		DeleteDC(hMemDC);
	}
	// >> : ANI
	
	{
		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hAniImage);
		bx = bitAni.bmWidth / 16; // 가로에 16장있음
		by = bitAni.bmHeight / 2;//세로에 2장들어있음
		int xStart = curFrame * bx;
		int yStart = 0;
		TransparentBlt(hdc, aniPos.x, aniPos.y, bx, by, hMemDC,
			xStart, yStart, bx, by, RGB(255, 0, 255));
		SelectObject(hMemDC, hOldBitmap);
		DeleteDC(hMemDC);
	}
	// <<

 
}

void Update()
{
	DWORD newTime = GetTickCount();
	static DWORD oldTime = newTime;
	if (newTime - oldTime < 100) return;
	oldTime = newTime;
	UpdateFrame2();
}



void DeleteBitmap() 
{
	DeleteObject(hBackImage);
	DeleteObject(hTransparentImage);
	DeleteObject(hAniImage);
}

void UpdateFrame(HWND hWnd) 
{

	//전
	curFrame++;
	if (curFrame > RUN_FRAME_MAX) 
	{
		curFrame = RUN_FRAME_MIN;
	}
}

VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	curFrame++;
	if (curFrame > RUN_FRAME_MAX) curFrame = RUN_FRAME_MIN;
	InvalidateRect(hWnd, NULL, false);
}
void DrawRectText(HDC hdc) 
{
	static int yPos = 0;
	TCHAR strTest[] = _T("이미지 출력");
	TextOut(hdc, 40, yPos, strTest, _tcslen(strTest));
	yPos += 5;
	if (yPos > rectView.bottom) yPos = 0;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	OPENFILENAME OFN;
	TCHAR str[100], lpstrFile[100] = _T("");
	TCHAR filter[] = _T("Every File(*.*)\0*.*\0Text File\0*.txt;*doc\0");
	//색상변경
	HDC hdc;
	PAINTSTRUCT ps;
	CHOOSECOLOR COLOR;
	static COLORREF tmp[16], color;
	HBRUSH hBrush, oldBrush;
	int i;

	
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);

		case ID_FUNC1:
		{
			int ans = MessageBox(hWnd, _T("기본 설정으로 작동합니다."), _T("기능 1"), MB_YESNOCANCEL);
			switch (ans)
			{
			case IDYES:
				MessageBox(hWnd, _T("YES버튼 선택."), _T("확인"), MB_OK);
				break;
			case IDNO:
				MessageBox(hWnd, _T("NO버튼 선택."), _T("확인"), MB_OK);
				break;
			case IDCANCEL:
				MessageBox(hWnd, _T("CANCEL버튼 선택."), _T("확인"), MB_OK);
				break;
			default:
				break;
			}
		}
		break;
		case ID_FUNC2:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About); break;
		case ID_FUNC3:DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About); break;
			
			
		case ID_FILEOPEN: 
		{
			memset(&OFN, 0, sizeof(OPENFILENAME));
			OFN.lStructSize = sizeof(OPENFILENAME);
			OFN.hwndOwner = hWnd;
			OFN.lpstrFilter = filter;
			OFN.lpstrFile = lpstrFile;
			OFN.nMaxFile = 256;
			OFN.lpstrInitialDir = _T(".");
			if (GetOpenFileName(&OFN) != 0) 
			{
				_stprintf(str, _T("%s 파일을 열겠습니까?"), OFN.lpstrFile);
				int aa=MessageBox(hWnd, str, _T("열기 선택"),MB_OK);
				
				if (aa) OutFromFile(OFN.lpstrFile, hWnd);
			}
		}	break;
		case ID_COLORDLG: 
		{
			for (i = 0; i < 16; i++) 
			{
				tmp[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
				memset(&COLOR, 0, sizeof(CHOOSECOLOR));
				COLOR.lStructSize = sizeof(CHOOSECOLOR);
				COLOR.hwndOwner = hWnd;
				COLOR.lpCustColors = tmp;
				COLOR.Flags = CC_FULLOPEN;
				if (ChooseColor(&COLOR) != 0) 
				{
					color = COLOR.rgbResult;
					InvalidateRgn(hWnd, NULL, TRUE);
				}
			}

		}	break;
		
		}
		break;
	}
	case WM_CREATE: 
	{
		CreateBitmap();
		CreateBitmap2();
		SetTimer(hWnd, 123, 100, NULL);
		//SetTimer(hWnd,123,100, AniProc);
		GetClientRect(hWnd, &rectView);
	}break;
	case WM_TIMER: 
	{
		UpdateFrame(hWnd); 
		defaultUpdateFrame();
	//	UpdateFrame2();
		InvalidateRect(hWnd, NULL, false);
	}
	break;
	case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
			/*
			hBrush = CreateSolidBrush(color);
			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			Ellipse(hdc,100,100,400,400);
			SelectObject(hdc, oldBrush);
			DeleteObject(hBrush);
			*/
			DrawBitmap(hdc, hWnd);
			DrawBitmap2(hdc,hWnd);
			HBRUSH brush;
			DrawRectText(hdc);
			EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		DeleteBitmap();
		KillTimer(hWnd, 123);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


// : 8directions
HBITMAP hAnimImage;
BITMAP bitAnim;
const int N_SPRITE_SIZE_X = 64;
const int N_SPRITE_SIZE_Y = 64;
POINT animPos;
int N_RUN_FRAME_MAX = 0;
int N_RUN_FRAME_MIN = 0;
int N_curFrame = N_RUN_FRAME_MIN;
int locY = 0; // 이미지에서 Y의 위치 
int locX = 0; // 이미지에서 X의 위치

void CreateBitmap2() 
{

	hAnimImage = (HBITMAP)LoadImage(NULL, TEXT("images/HeroSmall.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hAnimImage, sizeof(BITMAP), &bitAnim);
	N_RUN_FRAME_MAX = bitAnim.bmWidth / N_SPRITE_SIZE_X - 1;
	N_RUN_FRAME_MIN = 0;
	N_curFrame = N_RUN_FRAME_MIN;
	animPos.x = 200;
	animPos.y = 400;
	
}

void DrawBitmap2(HDC hdc, HWND hWnd) 
{
	HDC hMemDC;
	HBITMAP hOldBitmap;
	int bx, by;

		hMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hAnimImage);
		bx = bitAnim.bmWidth / 5;
		by = bitAnim.bmHeight / 8;
		int N_xStart = N_curFrame * bx;
		int N_yStart = locY * by;
		TransparentBlt(hdc, animPos.x, animPos.y, bx, by, hMemDC,
			N_xStart, N_yStart, bx, by, RGB(255, 255, 255));
		SelectObject(hMemDC, hOldBitmap);
		DeleteDC(hMemDC);
}
void defaultUpdateFrame()
{
	N_curFrame++;
	if (N_curFrame > N_RUN_FRAME_MAX) 
	{
		N_curFrame = N_RUN_FRAME_MIN;
	}
}
void UpdateFrame2()
{
	
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		animPos.y += 5;
		locY = 0;
	}
	if ((GetKeyState(VK_RIGHT) & 0x8000) && (GetKeyState(VK_UP) & 0x8000))
	{
		animPos.x += 5;
		animPos.y -= 5;
		locY = 1;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		animPos.x += 5;
		locY = 2;
	}
	if ((GetKeyState(VK_LEFT) & 0x8000) && (GetKeyState(VK_UP) & 0x8000))
	{
		animPos.x -= 5;
		animPos.y -= 5;
		locY = 3;
	}
	if (GetKeyState(VK_UP) & 0x8000)
	{
		animPos.y -= 5;
		locY = 4;
	}
	if ((GetKeyState(VK_LEFT) & 0x8000) && (GetKeyState(VK_DOWN) & 0x8000))
	{
		animPos.x -= 5;
		animPos.y += 5;
		locY = 5;
	}
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		animPos.x -= 5;
		locY = 6;
	}
	if ((GetKeyState(VK_RIGHT) & 0x8000) && (GetKeyState(VK_DOWN) & 0x8000))
	{
		animPos.x += 5;
		animPos.y += 5;
		locY = 7;
	}
}

void DeleteBitmap2() 
{

	DeleteObject(hAnimImage);
}