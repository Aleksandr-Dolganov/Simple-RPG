#pragma once
#include <SFML\Graphics.hpp>
#include "map.h"
using namespace sf;

class Character
{
private:
	Vector2f m_Position;// ���������� ���������
	
	Texture m_Texture;// �������� ���������
	// ���������� ������������� ������� ������ w, a, s, d.
	

	float m_Speed;// �������� ���������
public:
	float dx, dy;
	float Currentframe;// ������� ���� ��������
	Sprite m_Sprite;// ������ ���������
	Character();// �����������
	int dir;
	int Health;
	Sprite getSprite();// ������� �������� ������� ��������� � �������� ����� (engine)
	Vector2f getPos();// ������� �������� ��������� ��������� � �������� ����� (engine)

	void setY(float);// ��������� ���������� Y ��� ���������
	void setX(float);// ��������� ���������� X ��� ���������
	void setSpeed(float);// ��������� �������� ���������

	void updateCh(float elapsedTime);// ������� ���������� ��������� (��������� ������ �������� � ������� ���������)
	void randPos();
	void collision();
};