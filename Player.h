#pragma once
#include "Object.h"
class Player :
    public Object
{
private:
	float speed;
	float angle; // radian
	D3DXVECTOR2 gunBarrelPoint; // 포신의 끝점 위치를 나타낼 벡터

public:
    // Object을(를) 통해 상속됨
    void Initialize() override;
    void Update() override;
    void Render(HDC hdc) override;
    void Release() override;

	void DisplayText(HDC hdc);

public:
    Player();
    virtual ~Player();
};

