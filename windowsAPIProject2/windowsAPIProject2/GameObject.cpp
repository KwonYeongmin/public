#include "GameObject.h"
//------GDI+
#include <ObjIdl.h>
#include<gdiplus.h>
#pragma comment(lib,"Gdiplus.lib")
using namespace Gdiplus;

void EnemyMove::init(POINT p, int R, RECT rectview)
{
	r = R;
	center = p;
}

POINT EnemyMove::GetPos()
{
	return center;
}

void EnemyMove::Update()
{

}
void EnemyMove::Draw(HDC hdc)
{
	Ellipse(hdc,center.x-r,center.y-r, center.x + r, center.y + r);
}

List::List() 
{
	head = NULL;
	tail = NULL;
}
void List::AddBack(ss t) 
{
	ss *n = new ss;
	n->p = t.p;

	if (head == NULL)
	{
		n->next = NULL;
		head = n;
		tail = n;
	}
	else
	{
		tail->next = n;
		n->prev = tail;
		tail = n;
	}
	tail->next = NULL;
}
void List::Terminate(ss *list)
{
	delete[] list;
	delete[] head;
	delete[] tail;
}
//�÷��̾�
void Cursor::init(POINT p, int R, RECT rectview)
{
	center = p;
}

void Cursor::Update()
{
	int minX = 180;
	int maxX = 870;
	int minY = 160;
	int maxY = 660;

	/*
	while (true) 
	{
		
	 if (GetKeyState(VK_UP) < 0) center.y -= x;
	 if (GetKeyState(VK_DOWN) < 0)center.y += x;
	 if (GetKeyState(VK_LEFT) < 0) center.x -= x;
	 if (GetKeyState(VK_RIGHT) < 0) center.x += x;

	
	}
	while (GetAsyncKeyState(0) & 0x8001)
	{
		while (GetAsyncKeyState(VK_LEFT) & 0) center.x += x;
		while (GetAsyncKeyState(VK_RIGHT) & 0) center.x -= x;
	}*/
	
		//savepoint�� ���Ͱ� ����
	savePoint = center;
	//savePoint = new;
	//points.push_back(savePoint);
	
	//Ű���� ��ġ�� ���� ���󰡼� �� ��ġ

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001) 
	{
		if(center.x < maxX) center.x += moveSpeed;
	}
		
	if (GetAsyncKeyState(VK_LEFT) & 0x8001) 
	{
		if (center.x > minX) center.x -= moveSpeed;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8001) 
	{
		if (center.y < maxY) center.y += moveSpeed;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8001)
	{
		if (center.y > minY) center.y -= moveSpeed;
	}
	
	//*savePoints = center;
	
	//if (center.x == savePos.x && center.y == savePos.y) {}
}

//Ŀ�� �����̱�
void Cursor::OnGdi_Draw(HDC hdc)
{

}

// �������
void Cursor::OnGdi_line(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 0, 0));

	//Ŀ��
	Rect tt(center.x-r/2,center.y - r / 2,r,r);
	graphics.DrawEllipse(&pen, tt);
		//����� ���Ͱ� ���� ���� �׷����� 
	//��
	graphics.DrawLine(&pen, 200, 160, center.x, center.y); //update�� �� ���ϱ�
	
		//����
		//������ ����� ������ �κ�
		//������ ���� ���� ������ ����ũ����� ���⵵��
	if (points.begin() == points.end()) {}
	//
	SolidBrush brush(Color(255, 255, 0, 0));



}

//���� �ε�����
void Cursor::Collision() {}


POINT Cursor::GetPos()
{
	return center;
}


void DrawFrontImage::OnGdi_Draw(HDC hdc)
{
	Graphics graphics(hdc);//GDI+ ����� ���� graphics ��ü ����

	// >> : text
	SolidBrush brush(Color(255, 200, 150, 0));
	FontFamily fontFamily(L"Times New Roman");
	Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
	PointF pointF(10.0f, 20.0f);
	graphics.DrawString(L"< Gals Panic > ", -1, &font, pointF, &brush);
	// << 

	// >> : BackImage
	Image img((WCHAR*)L"images/frontImage2.png");
	int w = img.GetWidth();
	int h = img.GetHeight();
	graphics.DrawImage(&img, pos.x, pos.y, w*1.5, h*1.5); 
	
	//1. ������ ������ �״�� �����Ǳ�
	//2. ������ �� �� ��ŭ ����ũ ��
	//2. ����ũ���� ������ 80%�� ������ ����
}

void DrawFrontImage::OnGdi_Update(Cursor cursor)
{

	
}



//BackImage
void DrawBackImage::CreateBitmap() 
{
	hBackBackImage = (HBITMAP)LoadImage(NULL, TEXT("images/backback.bmp"),//FrontImage
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hBackBackImage, sizeof(BITMAP), &bitBackBack);

	hBackImage = (HBITMAP)LoadImage(NULL, TEXT("images/backImage2.bmp"),//FrontImage
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hBackImage, sizeof(BITMAP), &bitBack);
}
void DrawBackImage::DrawBitmap(HDC hMemDC, HDC hMemDC2, HBITMAP hOldBitmap2)
{
	int bx, by;
	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hBackBackImage);
		bx = bitBackBack.bmWidth;
		by = bitBackBack.bmHeight;
		TransparentBlt(hMemDC, pos.x-50, pos.y - 30, bx*1.8, by*1.8, hMemDC2, 0, 0,
			bx, by, RGB(255, 0, 255));

		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}

	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hBackImage);
		bx = bitBack.bmWidth ;
		by = bitBack.bmHeight;
		TransparentBlt(hMemDC, pos.x, pos.y, bx*1.5, by*1.5, hMemDC2, 0, 0,
				bx, by, RGB(255, 0, 255));
		
		SelectObject(hMemDC2, hOldBitmap2);
		DeleteDC(hMemDC2);
	}
}
void DrawBackImage::DeleteBitmap()
{
	DeleteObject(hBackImage);
}