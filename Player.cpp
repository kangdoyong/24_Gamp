#include "Player.h"

void Player::Initialize()
{
	speed = 3.f;
	info.pos = D3DXVECTOR3(WIN_SIZE_X / 2.f, WIN_SIZE_Y / 2.f, 0);
	info.dir = D3DXVECTOR3(0, 1.f, 0);
	info.look = D3DXVECTOR3(1.f, 0, 0);
}

void Player::Update()
{
	POINT mouse;
	GetCursorPos(&mouse);
	ScreenToClient(g_hWnd, &mouse);

	// 벡터 타입끼리 연산을 위해 포인트 좌표를 벡터로 변환
	D3DXVECTOR3 mousePos(mouse.x, mouse.y, 0);

	// 플레이어가 마우스쪽을 바라보게 하려고 함
	
	// 플레이어에서 마우스 쪽으로 향하는 벡터를 구함
	info.dir = mousePos - info.pos;
	// 방향벡터로 만들기 위해, 벡터의 크기를 1로 만들어야 함
	//  -> 벡터의 크기를 구해서, 벡터의 각 원소를 크기로 나눈다.

	// 벡터의 크기를 구한다. 
	/*float length = sqrt(info.dir.x * info.dir.x + info.dir.y * info.dir.y);
	if (length < 3.f)
	{
		return;
	}
	info.dir.x /= length;
	info.dir.y /= length;*/

	// 벡터를 단위벡터화 한다.
	D3DXVec3Normalize(&info.dir, &info.dir);

	// 벡터의 각 성분끼리 곱하고, 더하는 작업
	// -> 벡터의 내적
	// D3DXVec3Dot
	// angle = acosf(info.dir.x * info.look.x + info.dir.y * info.look.y);
	angle = acosf(D3DXVec3Dot(&info.dir, &info.look));

	if (mouse.y > info.pos.y)
	{
		angle = 2 * D3DX_PI - angle;
	}
	gunBarrelPoint = D3DXVECTOR2(cosf(angle) * 100.f + info.pos.x,
		-sinf(angle) * 100.f + info.pos.y);

	info.pos += info.dir * speed;
}

void Player::Render(HDC hdc)
{
	DisplayText(hdc);
	Rectangle(hdc, info.pos.x - 50, info.pos.y - 50, info.pos.x + 50, info.pos.y + 50);
	MoveToEx(hdc, info.pos.x, info.pos.y, NULL);
	LineTo(hdc, gunBarrelPoint.x, gunBarrelPoint.y);
}

void Player::Release()
{
}

void Player::DisplayText(HDC hdc)
{
	TCHAR temp[128] = L"";
	float dot = D3DXVec3Dot(&info.dir, &info.look);

	swprintf_s(temp, L"내적(Dot) %.2f", dot);
	TextOut(hdc, 50, 50, temp, wcslen(temp));

	swprintf_s(temp, L"라디안(Radian) %.2f", angle);
	TextOut(hdc, 50, 70, temp, wcslen(temp));

	swprintf_s(temp, L"디그리(Degree) %.2f", D3DXToDegree(angle));
	TextOut(hdc, 50, 90, temp, wcslen(temp));

	swprintf_s(temp, L"방향 벡터 x : %.2f, y : %.2f", info.dir.x, info.dir.y);
	TextOut(hdc, 50, 110, temp, wcslen(temp));

	swprintf_s(temp, L"포신 끝점 x : %.2f, y : %.2f", gunBarrelPoint.x, gunBarrelPoint.y);
	TextOut(hdc, 50, 130, temp, wcslen(temp));
}

Player::Player()
{
}

Player::~Player()
{
}
