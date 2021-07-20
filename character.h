#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "map.h"
using namespace sf;

class Character
{
private:
	Vector2f m_Position;// ���������� ���������
	Texture m_Texture;// �������� ���������
	float m_Speed;// �������� ���������
	void collision();// �������� (������������ � ������)
public:
	Character();// �����������
	~Character();// ����������
	float dx, dy;// �������� ��������� �� ����
	float Currentframe;// ������� ���� ��������
	int dir;// ����������� ���������
	int BeforeBattleDir;
	int Health;// �������� ���������
	Sprite m_Sprite;// ������ ���������

	Vector2f getPos();// ������� �������� ��������� ��������� � �������� ����� (engine)
	Vector2f BeforeBattlePos;
	void setPos(float x, float y);// ��������� ��������� ��� ���������
	void setSpeed(float);// ��������� �������� ���������

	void updateCh(float elapsedTime, bool DebugOffCollision);// ������� ���������� ��������� (��������� ������ �������� � ������� ���������)
	void randPos();// ��������� ������� ���������
};