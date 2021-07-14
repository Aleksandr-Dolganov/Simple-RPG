#pragma once
#include <SFML\Graphics.hpp>
#include <ctime>
#include <iostream>
#include "map.h"
using namespace sf;

class Enemy
{
private:
	float CurrentEframe;// ������� ���� �������� �����
	Vector2f e_Position;// ������� �����
	Sprite e_Sprite;// ������ �����
	Texture e_Texture;// �������� �����
public:
	int Health;// �������� �����
	Vector2f BeforeBattlePos;
	Vector2f getPos();
	void setPos(float x, float y);
	// �����������
	Enemy();
	// ����������
	~Enemy();
	// �������� ������� ����� � ������� �������
	Sprite getSprite();
	// ���������� �����
	void updateEn(float);
	// ���������������� ������� �����
	void randPos();
};