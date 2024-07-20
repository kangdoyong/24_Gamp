#pragma once
#include "Define.h"

class Object;

class MainGame
{
private:
	HDC hdc; // ���� �� ��ü�� �׸� �� ���� hdc
	Object* player; // �÷��̾� ��ü

public:
	void Initialize(); // �ʱ�ȭ
	void Update(); // ���� �� ����
	void Render(); // �׸���
	void Release(); // �޸� ����

public:
	MainGame();
	~MainGame();
};

