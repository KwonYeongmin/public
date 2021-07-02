// windowsAPIProject0629.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include<commdlg.h>
#include <cstdio>
#include "windowsAPIProject0629.h"
#include "gameObject.h"
#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.



	//---UI 변수
static int life = 8;
static int score = 0;
static TCHAR id[20] = _T(" ");

//--스테이지 
enum stage { Lobby=0,Game=1,Ending = 2};
static int stageNum= Lobby;

	//--파일 입출력
typedef struct recordData
{
	_TCHAR name[20];
	int score;
}data;
static data ary[5];

	//--오브젝트 관련
//--포탄
static RECT rclient;
static Turret turrent;
static int lcnt = 0;
static int rcnt = 0;

//--총알
static std::list<Bullet*> basket;
static Bullet *bullet;

//--오브젝트
static std::list<Object*> objects;
static Object *obj;

//--바닥
static std::list<defenseWall*> walls;
static defenseWall *wall;


//----함수

	//--게임 시작 셋팅함수
void gameStart(HWND hWnd);
	//--파일 입출력 함수
void cprRecord(HDC hdc);
void DrawRecord(HDC hdc);


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
    LoadStringW(hInstance, IDC_WINDOWSAPIPROJECT0629, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSAPIPROJECT0629));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSAPIPROJECT0629));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSAPIPROJECT0629);
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
		//--default
	HDC hdc;
	static int count;
	static SIZE size;

	switch (message)
	{
		srand((unsigned)time(NULL));
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
			//--글자쓰기
		CreateCaret(hWnd, NULL, 5, 15);
		ShowCaret(hWnd);
		count = 0;
			//--그림 그리기
		GetClientRect(hWnd, &rclient);
			//--setTimer
		SetTimer(hWnd, 1, 100, NULL);
		SetTimer(hWnd, 3, 1500, NULL);
	}break;
	case WM_CHAR:
		{
		bool key_ck = false;
		if (wParam == VK_BACK && count > 0) { id[--count] = NULL; }
		
		else if (wParam == VK_RETURN)
		{
			if (key_ck == false) 
			{
				gameStart(hWnd);
				stageNum = Game;
				key_ck = true;
			}
		}
		else
		{
			if (count <= 20) 
			{
				if (key_ck == false)
				{
					id[count++] = wParam;
					id[count] = NULL;
				}
			}
		}
		InvalidateRect(hWnd, NULL, true);
		}
		break;
	case WM_SIZE:
		GetClientRect(hWnd, &rclient);
		break;
	case WM_KEYDOWN:
	{
		if (stageNum == Game) 
		{
			switch (wParam)
			{
			case VK_RIGHT:
			{
				rcnt++;
				turrent.update(lcnt, rcnt, rclient);
			}  break;

			case VK_LEFT:
			{
				lcnt++;
				turrent.update(lcnt, rcnt, rclient);
			} break;
			case VK_SPACE:
			{
				//총알 추가
				bullet = new Bullet(turrent, 20);
				basket.push_back(bullet);
				InvalidateRect(hWnd, NULL, true);
			} break;

			}
			InvalidateRect(hWnd, NULL, true);
		}
		
	}break;
	case WM_TIMER:
	{
		
		switch (wParam)
		{
		case 1:
		{
			if (stageNum == Game) 
			{
				for (std::list<Bullet*>::iterator it = basket.begin(); it != basket.end(); it++)
				{
					Bullet *bullet = *it;
					bullet->update(turrent);
				}

				bool ck2 = false;
				for (std::list<Object*>::iterator it = objects.begin(); it != objects.end(); it++)
				{
					Object *obj = *it;
					obj->Update();

					for (std::list<Bullet*>::iterator ip = basket.begin(); ip != basket.end(); ip++)
					{
						Bullet *bullet = *ip;
						if (obj->Collision(*bullet) == true)
						{
							score += 5;
							//it = objects.erase(it);
							objects.erase(it);
							basket.erase(ip);
							ck2 = true;
							break;
						}
					}
					if (ck2 == true) break;
				}
				bool ck = 0;
				for (std::list<defenseWall*>::iterator it = walls.begin(); it != walls.end(); it++)
				{
					defenseWall *wall = *it;
					for (std::list<Object*>::iterator ip = objects.begin(); ip != objects.end(); ip++)
					{
						Object *obj = *ip;
						if (wall->collsion(*obj) == true)
						{
							//맞은 벽 사라지도록
							life--;
							walls.erase(it); //it = walls.erase(it);
							objects.erase(ip);
							ck = true;
							break;
						}
					}
					if (ck == true) break;
				}

				/*만약 벽의 개수가 1개이하면 게임 종료*/
				if (life < 1)
				{
					stageNum = Ending;
				}
				InvalidateRect(hWnd, NULL, true);
			}
			
		}break;
	case 3:
		{
			//오브젝트 생성
			if (stageNum == Game) 
			{
				obj = new Object({ rand() % 1300 + 100,-90 }, 10);
				objects.push_back(obj);
			}
		}break;
		}
	}break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			SIZE size;
			if (stageNum == Lobby) 
			{
				RECT rect{ 600, 200, 800, 240 };
				Rectangle(hdc, 600, 200, 800, 240);
				TextOut(hdc, 610, 210, id, _tcslen(id));
				GetTextExtentPoint(hdc, id, _tcslen(id), &size);
				SetCaretPos(rect.left + size.cx + 10, rect.top + 10);
			}
			else if (stageNum == Game) 
			{
				HideCaret(hWnd);
				//아이디
				TextOut(hdc, 20, 20, _T("ID : "), lstrlen(_T("ID : ")));
				TextOut(hdc, 50, 20, id, lstrlen(id));
				//점수
				TCHAR out[100];
				wsprintf(out, _T("score : %d"), score);
				TextOut(hdc, 300, 20, out, lstrlen(out));
				//라이프
				TCHAR lifee[100];
				wsprintf(lifee, _T("Life : %d"), life);
				TextOut(hdc, 500, 20, lifee, lstrlen(lifee));
				turrent.draw(hdc);

				for (std::list<Bullet*>::iterator it = basket.begin(); it != basket.end(); it++)
				{
					for (int i = 0; i < basket.size(); i++)
					{
						Bullet *bullet = *it;
						bullet->draw(hdc);
					}
				}
				for (std::list<Object*>::iterator it = objects.begin(); it != objects.end(); it++)
				{
					Object *obj = *it; obj->Draw(hdc);
				}

				for (std::list<defenseWall*>::iterator it = walls.begin(); it != walls.end(); it++)
				{
					defenseWall *wall = *it; wall->Draw(hdc);
				}		
			}
			else if (stageNum == Ending) 
			{
				cprRecord(hdc);
			}
			EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		KillTimer(hWnd, 1);
		KillTimer(hWnd, 3);
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

void gameStart(HWND hWnd)
{
	//defenseWall 생성
	for (int i = 0; i < 8; i++)
	{
		wall = new defenseWall(89, { 178 * i,rclient.bottom });
		walls.push_back(wall);
	}
	//포탄 생성
	turrent.init({ (rclient.right - rclient.left) / 2,rclient.bottom - 120 }, 120, rclient);
	InvalidateRect(hWnd, NULL, true);
}


//점수 비교 및 파일에 저장
void cprRecord(HDC hdc)
{
	static data arr[6];
	int i, j;

	//기록 저장된 텍스트 파일 불러오기
	std::ifstream fin("record.txt", std::ios_base::out | std::ios_base::in | std::ios_base::binary);

	if (fin.fail()) MessageBox(NULL, _T("파일열기"), _T("오류"), MB_ICONEXCLAMATION | MB_OK);

	char id_list[5][20] = { 0 };

	//문자ID와 점수 읽어옴
	for (i = 0; i < 5; i++) fin >> id_list[i] >> arr[i].score;

	//문자를 유니코드로 변환
	for (i = 0; i < 5; i++)
	{
		MultiByteToWideChar(CP_ACP, 0, id_list[i], 20, arr[i].name, 20);
	}
	fin.close();

	_tcscpy(arr[5].name, id);
	arr[5].score = score;
	
	//순위 매기기
	int max;
	for (i = 0; i < 5; i++)
	{
		max = i;
		for (j = i + 1; j < 6; j++)
		{
			if (arr[j].score > arr[max].score)
			{
				int temp = arr[j].score;
				arr[j].score = arr[i].score;
				arr[i].score = temp;
				TCHAR tempchar[20];
				_tcscpy(tempchar, arr[j].name);
				_tcscpy(arr[j].name, arr[i].name);
				_tcscpy(arr[i].name, tempchar);
			}
		}
	}

	//유니코드를 문자로 변환
	for (i = 0; i < 5; i++)
	{
		WideCharToMultiByte(CP_ACP, 0, arr[i].name, 20, id_list[i], 20, NULL, NULL);
	}

	std::ofstream fout("record.txt", std::ios_base::out | std::ios_base::in | std::ios_base::binary);
	for (i = 0; i < 5; i++)
	{
		fout << id_list[i] << ' ' << arr[i].score << '\n';
	}
	fout.close();
	int x = 550;
	int y = 180;
	for (int i = 0; i < 5; i++)
	{
		TextOut(hdc, x, y + 80 * i, _T("ID : "), lstrlen(_T("ID : ")));
		TextOut(hdc, x+50, y + 80 * i, arr[i].name, lstrlen(arr[i].name));

		TCHAR out[100];
		wsprintf(out, _T("score : %d"), arr[i].score);
		TextOut(hdc, x+200, y + 80 * i, out, lstrlen(out));
	}
}
