// 0617_winAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "0617_winAPI.h"

#define MAX_LOADSTRING 100

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
    LoadStringW(hInstance, IDC_MY0617WINAPI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0617WINAPI));

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

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0617WINAPI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY0617WINAPI);
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
void DrawGrid(HDC hdc,int start, int end,int line)
{
	double width = (end - start) / (line - 1);
	//가로
	for (int i = 0; i < line; i++) 
	{
		MoveToEx(hdc, start, start + i * width,NULL);
		LineTo(hdc, end, start + i * width);
	}
	//세로
	for (int i = 0; i < line; i++)
	{
		MoveToEx(hdc, start + i * width, start, NULL);
		LineTo(hdc, start + i * width, end);
	}
}


//drawCircle(중심,반지름)
void drawCircle(HDC hdc,POINT p,double r) 
{
	Ellipse(hdc, p.x-r, p.y - r, p.x + r, p.y + r);
}



//원의 개수로 구하기
void drawSunflower1(HDC hdc, POINT p, double r, int n)
{
	const double PI = 3.14159265358979323846;

	//큰 원 그리기
	drawCircle(hdc,{ p.x, p.y}, r);
	//각도 구하기
	const double a = 2*PI /(double)(n);


	const double A = sin(((a/2)*PI) / PI);
	//꽃잎의 반지름
	const double nr = (A*r)/(1-A);
	
	POINT nn;
	for (int i = 0; i < n; i++)
	{
		nn.x = p.x + (r + nr)*sin(a*i);
		nn.y = p.y + (r + nr)*cos(a*i);
		drawCircle(hdc, {nn.x, nn.y}, nr);
	}

}
//반지름주어짐
void drawSunflower2(HDC hdc, POINT p, double r, double nr)
{
	const double PI = 3.14159265358979323846;

	//큰 원 그리기
	drawCircle(hdc, { p.x, p.y }, r);

	POINT nn;
	int i = 0;
	
	double Ao = nr / (nr + r); 
	double Bo = (sqrt(pow(r, 2) + 2 * r*nr)) / (r + nr);
	double A = Ao;
	double B = Bo;

	//첫번째
	nn.x = p.x ;
	nn.y = p.y - (r + nr);
	drawCircle(hdc, { nn.x, nn.y }, nr);
	A = 2 * Ao*Bo;
	B = pow(Bo, 2) - pow(Ao, 2);
	
	
	while (i<14)
	{
		nn.x = p.x - (r + nr)*A;
		nn.y = p.y - (r + nr)*B;
		//if (A==1) break;
		if(i%2==0)drawCircle(hdc, { nn.x, nn.y }, nr);
		double temp_A = A;
		double temp_B = B;

		A = temp_A * Bo + temp_B * Ao;
		B = temp_B * Bo - temp_A * Ao;		
		i++;
	}

}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	//static bool isPressed= false;
	static TCHAR str[100];
	static int count,yPos;
	RECT rt = { 0,0,1000,1000 };
	static SIZE size;
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
		//CreateCaret(hWnd,NULL,5,15);
		//ShowCaret(hWnd);
		
		count = 0; 
		yPos = 0;
		break;
	
	case WM_CHAR:
		{
		// count가 0보다 작거나 100보다 크면 안된다.
			if (wParam == VK_BACK&& count > 0) { str[--count] = NULL; }
			
			else if (wParam == VK_RETURN) 
			{
				count = 0; 
				str[0] = NULL;
				yPos =yPos+ 20;
			}	
			else
			{
				str[count++] = wParam;
				str[count] = NULL;
			}
			InvalidateRect(hWnd, NULL, true);
			
		}
		break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
				
				//추가
			//TextOut(hdc, 100, 100, _T("hello world"), _tcslen(_T("hello world")));// wcslen);
			
				//rect구조체 선언
			RECT rect;
			rect.left = 0;
			rect.top = 0;
			rect.right = 400;
			rect.bottom = 400;
			//SetTextColor(hdc,RGB(120,0,180));
			//DrawText(hdc, _T("hello world2"), _tcslen(_T("hello world2")), 
			//	&rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			//SetTextColor(hdc, RGB(0, 0, 0));
			//TextOut(hdc, 0, 0, str, _tcslen(str));
			//TextOut(hdc, 0, yPos, str, _tcslen(str));
			//GetTextExtentPoint(hdc, str, _tcslen(str), &size);
			//DrawText(hdc, str, _tcslen(str), &rt, DT_TOP | DT_LEFT);
			
			/*
			LPPOINT p;// = 300;// , 300);
			p->x = 300;
			p->y = 300;*/
			//drawCircle(hdc, &p, 100);

			DrawGrid(hdc,0,100,4);
			drawCircle(hdc, { 1000, 100 }, 30);
			drawSunflower2(hdc, { 700,200 }, 80, 50);
			drawSunflower1(hdc, { 300,300 }, 100, 8);
			//SetCaretPos(size.cx,yPos);
			EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		//HideCaret(hWnd);
		//DestroyCaret();
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
