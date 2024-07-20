#pragma once
#include "Object.h"
class Player :
    public Object
{
private:
	float speed;
	float angle; // radian
	D3DXVECTOR2 gunBarrelPoint; // ������ ���� ��ġ�� ��Ÿ�� ����

public:
    // Object��(��) ���� ��ӵ�
    void Initialize() override;
    void Update() override;
    void Render(HDC hdc) override;
    void Release() override;

	void DisplayText(HDC hdc);

public:
    Player();
    virtual ~Player();
};

