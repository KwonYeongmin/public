// 0701windowsAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "0701windowsAPI.h"

#include <ObjIdl.h>
#include<gdiplus.h>
#pragma comment(lib,"Gdiplus.lib")
using namespace Gdiplus;

#pragma comment(lib,"msimg32.lib")
using namespace std;
// >> : double buffering

// >> : GDI+
ULONG_PTR g_GdiToken;
void Gdi_Init();
void Gdi_Draw(HDC hdc);
void OnGdi_Paint(HDC hdc);
void Gdi_End();
// <<

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
    LoadStringW(hInstance, IDC_MY0701WINDOWSAPI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0701WINDOWSAPI));

    MSG msg;
	Gdi_Init();
    // 기본 메시지 루프입니다:
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
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
			//Update();
			InvalidateRect(hWnd, NULL, false);
		}
	}
	Gdi_End();
	return (int)msg.wParam;
	/*
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;*/
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0701WINDOWSAPI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY0701WINDOWSAPI);
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


	//----------------함수
void CreateBitmap();
void DrawBitmapDoubleBufferImage(HWND hWnd, HDC hdc); // 더블버퍼링
void UpdateFrame(HWND hWnd);
void DeleteBitmap();
	//----------------변수
// : BackImage
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
//
RECT rectView;


// >> : double buffering
HBITMAP hDoubleBufferImage;
void DrawBitmapDoubleBufferImage(HWND hWnd, HDC hdc);

HBITMAP hreverseImage;
// << : 




void Gdi_Init() 
{
	GdiplusStartupInput gpsi;
	GdiplusStartup(&g_GdiToken,&gpsi,NULL);// gpsi;
}
void Gdi_Draw(HDC hdc) 
{
	OnGdi_Paint(hdc);
}
void OnGdi_Paint(HDC hdc)
{
	//GDI+ 사용을 위한 graphics 객체 생성
	Graphics graphics(hdc);

	/*
	

	// >> : text
	SolidBrush brush(Color(255,255, 0, 0));
	FontFamily fontFamily(L"Times New Roman");
	Font font(&fontFamily, 24, FontStyleRegular,UnitPixel);
	PointF pointF(10.0f, 20.0f);
	graphics.DrawString(L"Hello GDI+", -1, &font, pointF, &brush);
	// << 

	// >> : line
	Pen pen(Color(50, 0, 255, 255)); //알파 RGB
	graphics.DrawLine(&pen, 0, 0, 200, 100);
	// <<
	*/
	// >> : image
	Image img((WCHAR*)L"images/sigong.png");
	int w = img.GetWidth();
	int h = img.GetHeight();
	graphics.DrawImage(&img,100,100,w,h);
	/*
	// >> : image 회전
	Image*pImg = nullptr;
	pImg = Image::FromFile((WCHAR*)L"images/sigong.png");

	Gdiplus::Matrix mat;
	static int rot = 0;
	int xPos = 400;
	int yPos = 200;
	mat.RotateAt(rot%360, Gdiplus::PointF(xPos+(float) w/2,100+(float)(h/2)));
	//rot += 10;
	graphics.SetTransform(&mat);
	//graphics.DrawImage(pImg, yPos+300, yPos, w, h);
	// >>

	// >> : 컬러키 빼기
	ImageAttributes imgAttr;
	imgAttr.SetColorKey(Color(240, 0, 240), Color(255, 0, 255)); // 이 사이의 값을 뺀다.
	xPos = 300;
	//float a = 300 - (float)w / 2;
	//mat.RotateAt(rot % 360, Gdiplus::PointF(xPos + (float)w / 2, 100 + (float)(h / 2)));
	
	graphics.DrawImage( pImg,
		Rect ( xPos-(float)w/2, yPos - (float)h / 2, w, h ),
		0,0, w, h,
		UnitPixel, &imgAttr);
	// <<

	// >> : 반투명 사각형
	brush.SetColor(Color(128, 255, 0, 0)); // 알파 r,g,b
	graphics.FillRectangle(&brush, 400, 300,200,300);
	// <<

	// >> : 반투명
	static REAL transparency = 0.5f; //투명도
	//투명도 조절
	transparency += 0.1f; 
	if (transparency > 1.0f ) transparency = 0.0f; 

	ColorMatrix colorMatrix = 
	{
	1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, transparency, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	};
	xPos = 400;
	imgAttr.SetColorMatrix(&colorMatrix);
	graphics.DrawImage(pImg,
		Rect(xPos , yPos , w, h), 
		0,0,w,h,
		UnitPixel,&imgAttr);
	// <<

	// >> : 초록색
	colorMatrix =
	{
	0.3f, 0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.6f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.1f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, transparency, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	};
	xPos = 500;
	imgAttr.SetColorMatrix(&colorMatrix);
	graphics.DrawImage(pImg,
		Rect(xPos, yPos, w, h),
		0, 0, w, h,
		UnitPixel, &imgAttr);
	// << :
	
	// >> : 그레이
	colorMatrix =
	{
	   0.3f, 0.3f, 0.3f, 0.0f, 0.0f,
	   0.6f, 0.6f, 0.6f, 0.0f, 0.0f,
	   0.1f, 0.1f, 0.1f, 0.0f, 0.0f,
	   0.0f, 0.0f, 0.0f, transparency, 0.0f,
	   0.0f, 0.0f, 0.0f, 0.0f, 1.0f
	};

	imgAttr.SetColorMatrix(&colorMatrix);
	xPos = 600;
	graphics.DrawImage(pImg,
		Rect(xPos, yPos, w, h),
		0, 0, w, h,
		UnitPixel, &imgAttr);
	// <<

	if (pImg) delete pImg;
	*/
}
void Gdi_End() 
{
	GdiplusShutdown(g_GdiToken);
}

/*
void CreateBitmap()
{
	// >> : back image
	hBackImage = (HBITMAP)LoadImage(NULL, TEXT("images/수지.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
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
	RUN_FRAME_MAX = bitAni.bmWidth / SPRITE_SIZE_X - 1;
	RUN_FRAME_MIN = 2;
	curFrame = RUN_FRAME_MIN; //시작위치
	aniPos.x = 300;
	aniPos.y = 100;
	//<<:


}

void UpdateFrame(HWND hWnd)
{
	curFrame++;
	if (curFrame > RUN_FRAME_MAX)
	{
		curFrame = RUN_FRAME_MIN;
	}
}

void DrawBitmap(HDC hMemDC,HDC hMemDC2, HBITMAP hOldBitmap2)
{
	int bx, by;
	// >> : backImage
	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hBackImage);
		bx = bitBack.bmWidth;
		by = bitBack.bmHeight;
		BitBlt(hMemDC, 0, 0, bx, by, hMemDC2, 0, 0, SRCCOPY);

		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}

	// >> : transparent Image
	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hTransparentImage);
		bx = bitTransparent.bmWidth;
		by = bitTransparent.bmHeight;
		//BitBlt(hMemDC, 100, 200, bx, by, hMemDC2, 0, 0, SRCCOPY);

		//TransparentBlt(hMemDC, 200, 200, bx, by, hMemDC2, 0, 0,
		//	bx, by, RGB(255, 0, 255));

		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}

	// 애니메이션
	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hAniImage);

		// >> : 추가
		HDC hReverseMemDC;
		HBITMAP hOldBitmap3;
		hReverseMemDC = CreateCompatibleDC(hMemDC);
		if (!hReverseMemDC)
		{
			hreverseImage = CreateCompatibleBitmap(hMemDC2, bx, by);
		}
		hOldBitmap3 = (HBITMAP)SelectObject(hReverseMemDC, hreverseImage);
		// <<
		bx = bitAni.bmWidth / 16;
		by = bitAni.bmHeight / 2;

		int xStart = curFrame * bx;
		int yStart = 0;

		// << : 추가
		//StretchBlt(hReverseMemDC, bx - 1, 0, -bx, by, hMemDC2, xStart, yStart, bx, by, SRCCOPY);
		//TransparentBlt(hMemDC, 400, 400, bx * 2, by * 2, hMemDC2, xStart, yStart,	bx, by, RGB(255, 0, 255));
		// >>

		TransparentBlt(hMemDC, 200, 400, bx * 2, by * 2, hMemDC2, xStart, yStart,
			bx, by, RGB(255, 0, 255));

		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}
}
*/
void DrawBitmapDoubleBufferImage(HWND hWnd, HDC hdc)
{
	HDC hMemDC = NULL;
	HBITMAP hOldBitmap = NULL;
	//int bx, by;

	HDC hMemDC2 = NULL;
	HBITMAP hOldBitmap2 =NULL;

	//메모리 디씨 생성
	hMemDC = CreateCompatibleDC(hdc); //복사본 만들기
	if (!hMemDC)
	{
		MessageBox(hWnd, _T("CreateCompatibleDC failed!"), _T("Error"), MB_OK);
		return;
	}
	if (hDoubleBufferImage == NULL)
	{
		hDoubleBufferImage = CreateCompatibleBitmap
		(hdc, rectView.right, rectView.bottom);
	}

	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hDoubleBufferImage);

	//DrawBitmap(hMemDC,hMemDC2,hOldBitmap2);

	Gdi_Draw(hMemDC);

	BitBlt(hdc, 0, 0, rectView.right, rectView.bottom, hMemDC, 0, 0, SRCCOPY);
	
	SelectObject(hMemDC, hOldBitmap);
	DeleteDC(hMemDC);
}

/*
void DeleteBitmap()
{
	DeleteObject(hBackImage);
	DeleteObject(hTransparentImage);
	DeleteObject(hAniImage);
}*/

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
		//CreateBitmap();
		SetTimer(hWnd, 123, 100, NULL);
		GetClientRect(hWnd, &rectView); 
		
	}break;
	case WM_TIMER:
	
	{
		//UpdateFrame(hWnd);
		InvalidateRect(hWnd, NULL,false);
	}
	
		break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
			
			DrawBitmapDoubleBufferImage(hWnd, hdc);
			//Gdi_Draw(hdc);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		//DeleteBitmap();
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


/*
// >> : 8directions
HBITMAP hAnimImage;
BITMAP bitAnim;
const int N_SPRITE_SIZE_X = 64;
const int N_SPRITE_SIZE_Y = 64;
POINT animPos;
int N_RUN_FRAME_MAX = 0;
int N_RUN_FRAME_MIN = 0;
int N_curFrame = N_RUN_FRAME_MIN;
int locY = 0; // 이미지에서 Y의 위치 
int locX = 0; // 이미지에서 X의 위치*/



