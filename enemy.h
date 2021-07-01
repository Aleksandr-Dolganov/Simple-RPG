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
	int Health;// �������� �����
public:
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