#pragma once
#include <SFML\Graphics.hpp>
#include <ctime>
#include "character.h"
#include "map.h"
#include "view.h"
#include "enemy.h"
using namespace sf;

class Engine
{
private:
	RenderWindow m_Window;// ����

	float CurrentWframe;// ������� ���� �������� ����

	float zoomSpeed;// �������� ����

	Sprite m_map;// ������ �����
	Sprite m_mapW;// ������ ���� (� ���������)
	Texture m_mapTexture;// �������� �����
	Texture m_mapWTexture;// �������� ���� (� ���������)

	Character m_Character;// ��������� ���������

	Enemy e_Enemy;

	void input();// ������� ������������ ������� ������ ����������

	void update(float);// ������� ��� ���������� ���������

	void drawMap(float);// ������� ��������� ����� (�� ����� view.h)
	void randomMap();// ������� ������������ �����

	void collisionX();// �������� �� ���������� X
	void collisionY();// �������� �� ���������� Y\

	void battle();
	int ready;
public:
	Engine();// �����������

	void start();// ������� ������� ����
};