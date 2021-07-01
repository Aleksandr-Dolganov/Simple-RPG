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
	int Health;// �������� ���������
	Sprite m_Sprite;// ������ ���������
	
	Vector2f getPos();// ������� �������� ��������� ��������� � �������� ����� (engine)
	void setY(float);// ��������� ���������� Y ��� ���������
	void setX(float);// ��������� ���������� X ��� ���������
	void setSpeed(float);// ��������� �������� ���������

	void updateCh(float elapsedTime);// ������� ���������� ��������� (��������� ������ �������� � ������� ���������)
	void randPos();// ��������� ������� ���������
};