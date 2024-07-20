#pragma once
#include "framework.h"

#define WIN_SIZE_X 800
#define WIN_SIZE_Y 600

extern HWND g_hWnd;

// Ư�� ��ü�� �׸� ��, ��ġ�� ����� �ʿ�
// �׷� �� �� ���� ��ġ�� ����� �Ź� ���� �����ϱ� �������ϱ�
// ���� ���Ǵ� �����͸� ����ü�� ����� ó��
typedef struct tagInfo
{
	D3DXVECTOR3 pos; // ��ġ����
	D3DXVECTOR3 dir; // ���⺤�� (ũ�Ⱑ 1�� ����)
	D3DXVECTOR3 look; // 0���� �ٶ󺸴� ũ�� 1�� ���� ���� (���� ����)
}INFO;

