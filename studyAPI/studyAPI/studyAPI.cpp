// studyAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "studyAPI.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];//          // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.


//함수
void DrawGrid(HDC hdc, POINT start, POINT end, int num);

void DrawCircle(HDC hdc, POINT center, int r);



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
    LoadStringW(hInstance, IDC_STUDYAPI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_STUDYAPI));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
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

	wcex.cbSize = sizeof(WNDCLASSEX); //구조체 크기

	wcex.style = CS_HREDRAW | CS_VREDRAW; // 출력형태
	wcex.lpfnWndProc = WndProc; //프로시저 함수 : 메시지 처리에 사용될 함수의 이름
	wcex.cbClsExtra = 0; // 클래스를 위한 여분의 메모리 크기
	wcex.cbWndExtra = 0; //윈도우를 위한 여분의 메모리 크기
	wcex.hInstance = hInstance; // wWinMain() 함수에 첫번째 매개변수로 넘어온 응용프로그램인스턴스의 값을 넘겨줌
	wcex.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ASTERISK));// MAKEINTRESOURCE(IDI_STUDYAPI)); //기본 아이콘 지정
	wcex.hCursor = LoadCursor(nullptr,IDC_IBEAM); //기본 커서 지정
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); //윈도우 배경색
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_STUDYAPI); // 메뉴의 이름
	wcex.lpszClassName = szWindowClass; // 윈도우 클래스의 이름(문자열)
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));//MAKEINTRESOURCE(IDI_SMALL)); // 작은 아이콘 등록

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

   HWND hWnd = CreateWindowW(szWindowClass, _T("영민의 첫번째 윈도우"),WS_OVERLAPPEDWINDOW,//szTitle, WS_OVERLAPPEDWINDOW,
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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	static TCHAR input[200];
	static int count = 0;
	static int yPos;
	static int XPos;
	static SIZE size;
	//static RECT rect{ rect.left = 200,rect.top = 200,rect.bottom = 400,rect.right = 400 };
			
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
            }
        }
        break;
	case WM_CREATE: 
		{
		CreateCaret(hWnd, NULL, 5, 15);ShowCaret(hWnd);
			count = 0;
			yPos = 0;
		}
		break;
	case WM_CHAR: 
	{
		int ck = 0;
		hdc = GetDC(hWnd);
		if (wParam == VK_BACK && count>0) 
		{
			input[--count] = NULL;
		}
		else if (wParam == VK_RETURN )// || ((size.cx % 200 >190)))//||(ck==0))//
		{
			yPos += 20;
			input[count] != NULL;
			XPos++;	
		}
		else 
		{
			input[count++] = wParam;
			input[count] = NULL;
			XPos++;
			//ck = 0;
		}
		
		InvalidateRect(hWnd, NULL, true);
	}
		break;
	
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			/*
			LPCWSTR str = _T("helloWolrd");
				// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
			
			//TextOutW(hdc,100,100, str,_tcslen(str));
			static RECT rect{ rect.left = 200,rect.top = 200,rect.bottom = 400,rect.right = 400 };
			Rectangle(hdc, rect.left - 10, rect.top - 10, rect.right, rect.bottom);
			TextOut(hdc, rect.left, rect.top + yPos, input, _tcslen(input));
			GetTextExtentPoint(hdc, input, _tcslen(input), &size);
			
			SetCaretPos(rect.left+size.cx, rect.top+yPos);
			ReleaseDC(hWnd, hdc);*/

			//DrawText(hdc, str, _tcslen(str), &rect,DT_CENTER | DT_SINGLELINE|DT_VCENTER );

				//input
			DrawGrid(hdc, { 400,400 }, { 500,500 }, 4);
			DrawCircle(hdc, {100,100}, 50);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		HideCaret(hWnd);
		DestroyCaret();
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

//문제1 : 그리드 그리기
void DrawGrid(HDC hdc, POINT start, POINT end, int num)
{
	int i;
	const int width = (end.x - start.x) / num;
	const int height = (end.y - start.y) / num;
	//가로
	for (i = 0; i < num + 1; i++)
	{
		MoveToEx(hdc, start.x, start.y + height * i, NULL);
		LineTo(hdc, end.x, start.y + height * i);

		MoveToEx(hdc, start.x + width * i, start.y, NULL);
		LineTo(hdc, start.x + width * i, end.y);
	}
}

void DrawCircle(HDC hdc,POINT center, int r) 
{
	
	Ellipse(hdc,center.x-r,center.y-r, center.x + r, center.y + r);
}

//해바라기 그리기
void DrawSunFlower(HDC hdc,POINT center,int r, int num) 
{
	const double PI = 3.14159265359;
	const int angle = 2 * PI / num;
	const double A;
	DrawCircle(hdc, { center.x,center.y }, r);
}
