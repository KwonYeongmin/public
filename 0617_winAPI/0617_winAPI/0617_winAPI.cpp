// 0617_winAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "0617_winAPI.h"

#define MAX_LOADSTRING 100


//함수 정의
void DrawGrid(HDC hdc, int start, int end, int line);
void drawCircle(HDC hdc, POINT p, double r);
void drawSunflower1(HDC hdc, POINT p, double r, int n);
void drawSunflower2(HDC hdc, POINT p, double r, double nr);


void drawInputText(HDC hdc,RECT rect, LPCUWSTR str, int yPos);
RECT drawRectangle(HDC hdc, POINT center, long width, long height);
void DrawStar(HDC hdc, POINT center, int r,int size);

void keypad(HDC hdc, RECT up, RECT down, RECT left, RECT right, RECT center);


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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	//static bool isPressed= false;
	static TCHAR str[100];
	static int count,yPos;
	RECT rt = { 0,0,1000,1000 };
	static SIZE size;
	static  bool isleft = false;
	static  bool isright = false;
	static  bool isup = false;
	static  bool isdown = false;
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
		CreateCaret(hWnd,NULL,5,15);
		ShowCaret(hWnd);
		count = 0; 
		yPos = 0;
		break;
	
	case WM_KEYDOWN:
	{
		if (wParam == VK_UP) isup == true;
		if (wParam == VK_DOWN)  isdown == true;
		if (wParam == VK_RIGHT)  isright == true;
		if (wParam == VK_LEFT)  isleft == true;
	}
	break;
	case WM_KEYUP:
	{
		if (wParam == VK_UP)isup == false;
		if (wParam == VK_DOWN) isdown == false;
		if (wParam == VK_RIGHT)  isright == false;
		if (wParam == VK_LEFT)  isleft == false;
	}	break;
	
	case WM_CHAR:
		{
		// count가 0보다 작거나 100보다 크면 안된다.
		/*
			if (wParam == VK_BACK&& count > 0) { str[--count] = NULL; }
			
			else if (wParam == VK_RETURN) 
			{
				count = 0; 
				str[0] = NULL;
				yPos+= 20;
			}	
			else
			{
				str[count++] = wParam;
				str[count] = NULL;
			}*/
		if (wParam == VK_UP)isup == true;
		InvalidateRect(hWnd, NULL, true);	
		}
		break; 
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		

				//글씨 쓰기	
			//TextOut(hdc, 100, 100, _T("hello world"), _tcslen(_T("hello world")));// wcslen);
			
				//rect구조체 선언
			/*RECT rect;
			rect.left = 0;
			rect.top = 0;
			rect.right = 400;
			rect.bottom = 400;*/
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
			/*
			DrawGrid(hdc,0,100,4);
			drawCircle(hdc, { 1000, 100 }, 30);*/
			/*drawSunflower2(hdc, { 700,200 }, 80, 50);
			
			drawSunflower1(hdc, { 300,300 }, 100, 8);
				
			RECT rect=drawRectangle(hdc, {500,200},100,100);
			drawInputText(hdc, rect,str,yPos);*/
				
				//선,면 색 바꾸기
			/*
			HPEN pen = CreatePen(PS_DOT,1, RGB(0, 0, 0));
			HPEN oldPen = (HPEN)SelectObject(hdc, pen);
			HBRUSH hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
			//HBRUSH hBrush = CreateSolidBrush(RGB(130, 50, 220));
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			DrawStar(hdc, { 800,200 }, 100, 8);
			DrawStar(hdc, {1000,400},100,5);
			SelectObject(hdc,oldPen);
			DeleteObject(pen); 
			SelectObject(hdc, oldBrush);
			DeleteObject(hBrush);*/


			HBRUSH 	hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
			//HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			
			//초기화상태
			//위
			RECT up = drawRectangle(hdc, { 500,200 }, 80, 100);
			DrawText(hdc, _T("위쪽"), _tcslen(_T("위쪽")),
				&up, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			//아래
			RECT down = drawRectangle(hdc, { 500,400 }, 80, 100);
			DrawText(hdc, _T("아래쪽"), _tcslen(_T("아래쪽")),
				&down, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			//오른쪽
			RECT right = drawRectangle(hdc, { 580,300 }, 80, 100);
			DrawText(hdc, _T("오른쪽"), _tcslen(_T("오른쪽")),
				&right, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			//왼쪽
			RECT left = drawRectangle(hdc, { 420,300 }, 80, 100);
			DrawText(hdc, _T("왼쪽"), _tcslen(_T("왼쪽")),
				&left, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			RECT center = drawRectangle(hdc, { 500,300 }, 80, 100);

			if (isup == true) 
			{
				hBrush = CreateSolidBrush(RGB(255, 0, 0));
				oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
				up = drawRectangle(hdc, { 500,200 }, 80, 100);
			}
			else if (isup == false)
			{
				hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
				oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
				keypad(hdc,up, down,  left, right, center);
			}

			
		


			

			if (isup == true) 
			{
				hBrush = CreateSolidBrush(RGB(255, 0, 0));
				oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
				break;
			}
			//while (1) 
			//{
			
			/*
			else 
			{
				hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
				//HBRUSH hBrush = CreateSolidBrush(RGB(130, 50, 220));
				oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
				up = drawRectangle(hdc, { 500,200 }, 80, 100);
				drawInputText(hdc, up, _T("위쪽"), yPos);
				break;
				}
			}*/
			
		
			EndPaint(hWnd, &ps);	
			SelectObject(hdc, oldBrush);
			DeleteObject(hBrush);
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

//사각형
RECT drawRectangle(HDC hdc, POINT center, long width, long height) 
{
	POINT start, end;
	start.x = center.x  -width / 2;
	start.y = center.y - height / 2;
	end.x =  center.x+ width /2;
	end.y = center.y+height/2;
	Rectangle(hdc, start.x, start.y, end.x, end.y);

	RECT rect;
	rect.left = start.x;
	rect.top = start.y;
	rect.right = end.x;
	rect.bottom = end.y;
	
	return rect;
}
void keypad(HDC hdc,RECT up,RECT down, RECT left, RECT right,RECT center) 
{
	//위
	up = drawRectangle(hdc, { 500,200 }, 80, 100);
	DrawText(hdc, _T("위쪽"), _tcslen(_T("위쪽")),
		&up, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	//아래
	down = drawRectangle(hdc, { 500,400 }, 80, 100);
	DrawText(hdc, _T("아래쪽"), _tcslen(_T("아래쪽")),
		&down, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	//오른쪽
	right = drawRectangle(hdc, { 580,300 }, 80, 100);
	DrawText(hdc, _T("오른쪽"), _tcslen(_T("오른쪽")),
		&right, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	//왼쪽
	left = drawRectangle(hdc, { 420,300 }, 80, 100);
	DrawText(hdc, _T("왼쪽"), _tcslen(_T("왼쪽")),
		&left, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	center = drawRectangle(hdc, { 500,300 }, 80, 100);
}
//사각형안에 글씨쓰기
void drawInputText(HDC hdc, RECT rect, LPCUWSTR str, int yPos)
{
	SIZE size;
	Rectangle(hdc,rect.left, rect.top, rect.right, rect.bottom);
	yPos = rect.top;
	TextOut(hdc, rect.left + 5, yPos+5, str, _tcslen(str));
	GetTextExtentPoint(hdc, str, _tcslen(str), &size);
	//SetCaretPos(rect.left+size.cx + 5, yPos + 5);
}

void DrawStar(HDC hdc,POINT center,int r,int size) 
{
	const double PI = 3.14159265358979323846;
	POINT *point = (POINT*)calloc(size*2, sizeof(POINT));

	const double a = 2 * PI /(double)( size);
	int i;
	//원 위의 점 구하기
	for (i = 0; i < size; i++) 
	{
		(point + i*2)->x = center.x-r * sin(a*i);
		(point + i*2)->y = center.y-r * cos(a*i);
	}

	const double A = sin(a);
	const double B = cos(a);
	double A_ = sin(a/2);
	double B_ = cos(a/2);
	double ta = A_;
	double tb = B_;

	//다각형의 반지름
	const int nr = 2 * (B*(r - B * r) / A);
	
	//다각형 외접원의 점 구하기 
	for (i = 0; i < size ;i++) 
	{
		point[i*2+1].x= center.x - nr * A_;
		point[i * 2 + 1].y = center.y - nr * B_;
		ta = A_;
		tb = B_;
		A_ = ta * B + A * tb;
		B_ = tb * B - A * ta;
	}
	Polygon(hdc, point, size*2);
}

//그리드 그리기
void DrawGrid(HDC hdc, int start, int end, int line)
{
	double width = (end - start) / (line - 1);
	for (int i = 0; i < line; i++)
	{
		MoveToEx(hdc, start, start + i * width, NULL);
		LineTo(hdc, end, start + i * width);
	}
	for (int i = 0; i < line; i++)
	{
		MoveToEx(hdc, start + i * width, start, NULL);
		LineTo(hdc, start + i * width, end);
	}
}

//원 그리기
void drawCircle(HDC hdc, POINT p, double r)
{
	Ellipse(hdc, p.x - r, p.y - r, p.x + r, p.y + r);
}

//원의 개수로 구하기
void drawSunflower1(HDC hdc, POINT p, double r, int n)
{
	const double PI = 3.14159265358979323846;
	//큰 원 그리기
	drawCircle(hdc, { p.x, p.y }, r);
	//각도 구하기
	const double a = 2 * PI / (double)(n);

	const double A = sin(((a / 2)*PI) / PI);
	const double nr = (A*r) / (1 - A);

	POINT nn;
	for (int i = 0; i < n; i++)
	{
		nn.x = p.x + (r + nr)*sin(a*i);
		nn.y = p.y + (r + nr)*cos(a*i);
		drawCircle(hdc, { nn.x, nn.y }, nr);
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
	nn.x = p.x;
	nn.y = p.y - (r + nr);
	drawCircle(hdc, { nn.x, nn.y }, nr);
	A = 2 * Ao*Bo;
	B = pow(Bo, 2) - pow(Ao, 2);

	int ck = 0;

	while (i < 13)
	{
		nn.x = p.x - (r + nr)*A;
		nn.y = p.y - (r + nr)*B;
		if (A == 1) break;
		if (i % 2 == 0)
		{
			drawCircle(hdc, { nn.x, nn.y }, nr);
			ck++;
		}
		double temp_A = A;
		double temp_B = B;

		A = temp_A * Bo + temp_B * Ao;
		B = temp_B * Bo - temp_A * Ao;
		i++;
	}
}