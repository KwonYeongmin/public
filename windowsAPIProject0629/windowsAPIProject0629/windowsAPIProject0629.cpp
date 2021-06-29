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

static int score = 0;
static TCHAR id[100] = _T(" ");
enum stage
{
	Lobby=0,Game=1,Ending=2
};
static int stageNum=Lobby;

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


//파일에 있는 정보 가져와서 점수 비교하기
int cprRecord(TCHAR(*name)[100], int *ss)
{
	//std::ofstream out("recore.txt");
	std::ifstream fin("Record.txt", std::ios::in | std::ios::binary);

	if (fin.fail())
	{
		std::cout << "파일을 여는데 실패했습니다.\n" << std::endl;
		return -1;
	}
	//데이터 가지고 오기
	for (int i = 0; i < 5; i++)
	{
		fin.read((char *)name[i], sizeof(TCHAR) * 100);
		fin.read((char *)&ss[i], sizeof(int));
	}
	fin.close();
	return 1;
}
int fileOpen(int index) 
{
	std::ofstream out("recore.txt");
	

	if (out.fail()) 
	{
		std::cout << "파일을 여는데 실패했습니다.\n" << std::endl;
		return 1;
	}

	if (index == 0) 
	{

		out << *id << " : " << score << std::endl;
		
	}
	else if (index==1) 
	{
		TCHAR outBuf[100];// = _T("test");
		char temp[100];
		WideCharToMultiByte(CP_ACP, 0, outBuf, 100, temp, 100, NULL, NULL);
		out << temp << std::endl;
	}
	
	out.close();
	return 1;
}
//파일을 읽기
int readRecord() 
{

}

void saveRecord (TCHAR(*name)[100], int *s)
{
	std::ifstream fin("Record.txt", std::ios::in | std::ios::binary);

	for (int i = 0; i < 5; i++)
	{
		fin.read((char *)name[i], sizeof(TCHAR) * 15);
		fin.read((char *)&s[i], sizeof(int));
	}
	fin.close();
	TCHAR tt[15];
	_tcscpy_s(tt, _countof(tt), id);
	int nt = score;

	for (int i = 0; i < 5; i++)
	{
		if (s[i] < score)
		{
		TCHAR temp[100] = { 0 };
				_tcscpy_s(temp, _countof(temp), name[i]);
				int int_temp = s[i];

				_tcscpy_s(name[i], _countof(name[i]), id);
				s[i] = score;

				_tcscpy_s(id, _countof(id), temp);
				score = int_temp;
			}
		}

		_tcscpy_s(id, _countof(id), tt);
		score = nt;

		std::ofstream fout("Record.txt", std::ios::out | std::ios::binary);


		for (int i = 0; i < 5; i++)
		{
			fout.write((char *)name[i], sizeof(TCHAR) * 15);
			fout.write((char *)&s[i], sizeof(int));
		}

		fout.close();
	}


//case : ening에 넣기
void recordScreen() 
{
	/*
	
	TCHAR SCORE[100] = { 0 };
	_itot_s(Score, SCORE, _countof(SCORE), 10);
	TextOut(hdc, rectview.right / 2 - 155, rectview.bottom / 2 - 20, _T("현재 플레이어 기록"), _tcslen(_T("현재 플레이어 기록")));
	TextOut(hdc, rectview.right / 2 - 10, rectview.bottom / 2 - 20, ID, _tcslen(ID));
	TextOut(hdc, rectview.right / 2 + 65, rectview.bottom / 2 - 20, SCORE, _tcslen(SCORE));

	memset(SCORE, 0, sizeof(SCORE));
	_itot_s(score[0], SCORE, _countof(SCORE), 10);
	TextOut(hdc, rectview.right / 2 - 155, rectview.bottom / 2 + 5, _T("    1위    "), _tcslen(_T("    1위    ")));
	TextOut(hdc, rectview.right / 2 - 10, rectview.bottom / 2 + 5, name[0], _tcslen(name[0]));
	TextOut(hdc, rectview.right / 2 + 65, rectview.bottom / 2 + 5, SCORE, _tcslen(SCORE));
	memset(SCORE, 0, sizeof(SCORE));
	_itot_s(score[1], SCORE, _countof(SCORE), 10);
	TextOut(hdc, rectview.right / 2 - 155, rectview.bottom / 2 + 30, _T("    2위    "), _tcslen(_T("    2위    ")));
	TextOut(hdc, rectview.right / 2 - 10, rectview.bottom / 2 + 30, name[1], _tcslen(name[1]));
	TextOut(hdc, rectview.right / 2 + 65, rectview.bottom / 2 + 30, SCORE, _tcslen(SCORE));
	memset(SCORE, 0, sizeof(SCORE));
	_itot_s(score[2], SCORE, _countof(SCORE), 10);
	TextOut(hdc, rectview.right / 2 - 155, rectview.bottom / 2 + 55, _T("    3위    "), _tcslen(_T("    3위    ")));
	TextOut(hdc, rectview.right / 2 - 10, rectview.bottom / 2 + 55, name[2], _tcslen(name[2]));
	TextOut(hdc, rectview.right / 2 + 65, rectview.bottom / 2 + 55, SCORE, _tcslen(SCORE));
	memset(SCORE, 0, sizeof(SCORE));
	_itot_s(score[3], SCORE, _countof(SCORE), 10);
	TextOut(hdc, rectview.right / 2 - 155, rectview.bottom / 2 + 80, _T("    4위    "), _tcslen(_T("    4위    ")));
	TextOut(hdc, rectview.right / 2 - 10, rectview.bottom / 2 + 80, name[3], _tcslen(name[3]));
	TextOut(hdc, rectview.right / 2 + 65, rectview.bottom / 2 + 80, SCORE, _tcslen(SCORE));
	memset(SCORE, 0, sizeof(SCORE));
	_itot_s(score[4], SCORE, _countof(SCORE), 10);
	TextOut(hdc, rectview.right / 2 - 155, rectview.bottom / 2 + 105, _T("    5위    "), _tcslen(_T("    5위    ")));
	TextOut(hdc, rectview.right / 2 - 10, rectview.bottom / 2 + 105, name[4], _tcslen(name[4]));
	TextOut(hdc, rectview.right / 2 + 65, rectview.bottom / 2 + 105, SCORE, _tcslen(SCORE));
	*/
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
	//
	HDC hdc;
	static int count;
	static SIZE size;
	//포탄
	static RECT rclient;
	static Turret turrent;
	static int lcnt = 0;
	static int rcnt = 0;

	//총알
	static std::list<Bullet*> basket;
	static Bullet *bullet;

	//오브젝트
	static std::list<Object*> objects;
	static Object *obj;

	//바닥
	static std::list<defenseWall*> walls;
	static defenseWall *wall;

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
	//파일 오픈,, 어디다가 넣어야하는지 모르겠습니다.
	case ID_FILEOPEN: 
	{
	
	}break;
	case WM_CREATE:
	{
		//글자쓰기
		CreateCaret(hWnd, NULL, 5, 15);
		ShowCaret(hWnd);
		count = 0;

		//그림 그리기
		GetClientRect(hWnd, &rclient);
		
		SetTimer(hWnd, 1, 100, NULL);
		SetTimer(hWnd, 2, 2000, NULL);
		SetTimer(hWnd, 3, 1500, NULL);
		//defenseWall 생성
		for (int i = 0; i < 8; i++)
		{
			wall = new defenseWall(89, { 178 * i,rclient.bottom });
			walls.push_back(wall);
		}

		//포탄
		turrent.init({ (rclient.right - rclient.left) / 2,rclient.bottom - 120 }, 120, rclient);

		InvalidateRect(hWnd, NULL, true);
	}break;
	case WM_CHAR:
		{
		if (wParam == VK_BACK && count > 0) { id[--count] = NULL; }
		
		else if (wParam == VK_RETURN) stageNum = Game;
		else
		{
			if (count > 100) 
			{
				//"입력하지 못하도록 경고 뜨기"
			}
			else 
			{
				id[count++] = wParam;
				id[count] = NULL;
			}	
		}
		
		InvalidateRect(hWnd, NULL, true);
		}break;
	case WM_SIZE:
		GetClientRect(hWnd, &rclient);
		break;
	case WM_KEYDOWN:
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
	}break;
	case WM_TIMER:
	{
		switch (wParam)
		{
		case 1:
		{
			for (std::list<Bullet*>::iterator it = basket.begin(); it != basket.end(); it++)
			{
				Bullet *bullet = *it;
				bullet->update(turrent);
			}

			
			for (std::list<Object*>::iterator it = objects.begin(); it != objects.end(); it++)
			{
				Object *obj = *it;
				obj->Update();

				for (std::list<Bullet*>::iterator ip = basket.begin(); ip != basket.end(); ip++)
				{
					Bullet *bullet = *ip;
					if (obj->Collision(*bullet) == true)
					{
						score+=5;
						it = objects.erase(it);
					}
				}
			}
			
			for (std::list<defenseWall*>::iterator it = walls.begin(); it != walls.end(); it++)
			{
				defenseWall *wall = *it;
				for (std::list<Object*>::iterator ip = objects.begin(); ip != objects.end(); ip++)
				{
					Object *obj = *ip;
					if (wall->collsion(*obj) == true)
					{
						//맞은 벽 사라지도록
						it = walls.erase(it);
					}
				}
			}
			/*
			for (std::list<Object*>::iterator ip = objects.begin(); ip != objects.end(); ip++)
			{
				Object *obj = *ip;
				for (std::list<defenseWall*>::iterator it = walls.begin(); it != walls.end(); it++)
				{
					 defenseWall *wall = *it;
					if (wall->collsion(*obj) == true)
					{
						//맞은 벽 사라지도록
						it = walls.erase(it);
					}
					else { it++; }
				}
			}*/

			/*만약 벽의 개수가 0이라면
			게임 종료*/
			//if (walls.size() == 0)
			if (score == 10)
			{
				stageNum == Ending;
			}
		InvalidateRect(hWnd, NULL, true);
		}break;
	case 3:
		{
			//오브젝트 생성
			obj = new Object({ rand() % 1300 + 100,-90 }, 10);
			objects.push_back(obj);
		}break;
	}
		}break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			SIZE size;
			switch (stageNum) 
			{
			case Lobby: 
				{
				fileOpen(0);
				RECT rect{ 600, 200, 800, 240 };
				Rectangle(hdc,600,200,800,240);
				TextOut(hdc, 610, 210, id, _tcslen(id));
				GetTextExtentPoint(hdc, id, _tcslen(id), &size);
				SetCaretPos(rect.left + size.cx + 10, rect.top+10);
				}break;
			case Game: 
				{
				HideCaret(hWnd);
				//아이디
				TextOut(hdc, 20, 20, _T("ID : "), lstrlen(_T("ID : ")));
				TextOut(hdc, 50, 20, id, lstrlen(id));
				//점수
				TCHAR out[100];
				wsprintf(out, _T("score : %d"), score);
				TextOut(hdc, 300, 20, out, lstrlen(out));
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
					Object *obj = *it;
					obj->Draw(hdc);
				}

				for (std::list<defenseWall*>::iterator it = walls.begin(); it != walls.end(); it++)
				{
					defenseWall *wall = *it;
					wall->Draw(hdc);
				}
				}break;

			case Ending: 
				{
				//fileOpen(1);
				//saveRecord(&id, &s);
			}break;
			}

			

			EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		KillTimer(hWnd, 1);
		//KillTimer(hWnd, 2);
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
