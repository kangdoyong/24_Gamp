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

	// ���� Ÿ�Գ��� ������ ���� ����Ʈ ��ǥ�� ���ͷ� ��ȯ
	D3DXVECTOR3 mousePos(mouse.x, mouse.y, 0);

	// �÷��̾ ���콺���� �ٶ󺸰� �Ϸ��� ��
	
	// �÷��̾�� ���콺 ������ ���ϴ� ���͸� ����
	info.dir = mousePos - info.pos;
	// ���⺤�ͷ� ����� ����, ������ ũ�⸦ 1�� ������ ��
	//  -> ������ ũ�⸦ ���ؼ�, ������ �� ���Ҹ� ũ��� ������.

	// ������ ũ�⸦ ���Ѵ�. 
	/*float length = sqrt(info.dir.x * info.dir.x + info.dir.y * info.dir.y);
	if (length < 3.f)
	{
		return;
	}
	info.dir.x /= length;
	info.dir.y /= length;*/

	// ���͸� ��������ȭ �Ѵ�.
	D3DXVec3Normalize(&info.dir, &info.dir);

	// ������ �� ���г��� ���ϰ�, ���ϴ� �۾�
	// -> ������ ����
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

	swprintf_s(temp, L"����(Dot) %.2f", dot);
	TextOut(hdc, 50, 50, temp, wcslen(temp));

	swprintf_s(temp, L"����(Radian) %.2f", angle);
	TextOut(hdc, 50, 70, temp, wcslen(temp));

	swprintf_s(temp, L"��׸�(Degree) %.2f", D3DXToDegree(angle));
	TextOut(hdc, 50, 90, temp, wcslen(temp));

	swprintf_s(temp, L"���� ���� x : %.2f, y : %.2f", info.dir.x, info.dir.y);
	TextOut(hdc, 50, 110, temp, wcslen(temp));

	swprintf_s(temp, L"���� ���� x : %.2f, y : %.2f", gunBarrelPoint.x, gunBarrelPoint.y);
	TextOut(hdc, 50, 130, temp, wcslen(temp));
}

Player::Player()
{
}

Player::~Player()
{
}
