#include "MainGame.h"
#include "Player.h"

void MainGame::Initialize()
{
	srand(GetTickCount64());

	// ���� ������ �ڵ��� ���� dc�� �����´�
	hdc = GetDC(g_hWnd);

	player = new Player();
	player->Initialize();


}

void MainGame::Update()
{
	player->Update();

	
}

void MainGame::Render()
{
	// â �ػ󵵸�ŭ �簢���� ���� �׷�, ȭ���� ������ ��ó�� ���̰� ��
	Rectangle(hdc, 0, 0, WIN_SIZE_X, WIN_SIZE_Y);
	player->Render(hdc);

}

void MainGame::Release()
{
	// �÷��̾� ��ü�� �����Ѵٸ� ����
	if (player)
	{
		delete player;
		player = nullptr;
	}

	// �����Դ� dc�� �ý��ۿ� ��ȯ (����)
	ReleaseDC(g_hWnd, hdc);
}

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
	Release();
}
